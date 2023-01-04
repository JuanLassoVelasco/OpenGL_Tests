#include "GL/freeglut.h"
#include "GL/glut.h"
#include <math.h>

float xPos = 0.0f;
float yPos = 0.0f;

float moveSpeed = 0.1f;

void triangle(){
    glBegin(GL_TRIANGLES);
        glVertex3f(0.1 + xPos, 0.1 + yPos, 0.0);
        glVertex3f(-0.1 + xPos, 0.1 + yPos, 0.0);
        glVertex3f(0.0 + xPos, -0.1 + yPos, 0.0);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    triangle();
    glFlush();
}

void keyboard(int key, int x, int y){
    switch (key)
    {
    case GLUT_KEY_LEFT:
        xPos -= moveSpeed;
        break;
    case GLUT_KEY_RIGHT:
        xPos += moveSpeed;
        break;
    case GLUT_KEY_UP:
        yPos += moveSpeed;
        break;
    case GLUT_KEY_DOWN:
        yPos -= moveSpeed;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Moving Triangle");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
