#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <shader/shader.h>
#include "iostream"
#include "sstream"

void processInput(GLFWwindow* window) 
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
    float triangle1[] = {
        // triangle one
        -0.5f, 0.5f, 0.0f,
        -0.2f, 0.5f, 0.0f,
        -0.35f, 0.2f, 0.0f
    };

    float triangle2[] = {
        // triangle two
        0.5f, -0.5f, 0.0f,
        0.2f, -0.5f, 0.0f,
        0.35f, -0.2f, 0.0f,
    };

    unsigned int VBO1;
    unsigned int VAO1;
    unsigned int VBO2;
    unsigned int VAO2;
    unsigned int vertexShader;
    unsigned int fragmentShader;

    int success;
    char infolog[512];

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);   
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Render Primitives", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Could not initialize GLAD" << std::endl;
        glfwTerminate();

        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader("/home/juan-ros-workspace/Documents/OpenGL_Dev/OpenGL_Tests/Move_Shapes/shaders/vertexShader.vs", "/home/juan-ros-workspace/Documents/OpenGL_Dev/OpenGL_Tests/Move_Shapes/shaders/fragmentShader.fs");

    glGenBuffers(1, &VBO1);
    glGenBuffers(1, &VBO2);
    glGenVertexArrays(1, &VAO1);
    glGenVertexArrays(1, &VAO2);

    glBindVertexArray(VAO1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    shader.use();
    shader.setVec4("ourColor", 0.5, 0.0, 0.0, 1.0);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        float timeVar = glfwGetTime();
        float greenValue = (sin(timeVar) / 2.0f) + 0.5f;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));

        shader.use();

        unsigned int transformLoc = glGetUniformLocation(shader.ID, "transform");
        glProgramUniformMatrix4fv(shader.ID, transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO1);
    glDeleteVertexArrays(1, &VAO2);
    glDeleteBuffers(1, &VBO1);
    glDeleteBuffers(1, &VBO2);

    glfwTerminate();
    
    return 0;
}


