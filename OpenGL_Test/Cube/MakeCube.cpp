#include "GL/freeglut.h"
#include "GL/glut.h"
#include <math.h>

float boxScale = 1;
double rotX = 0;
double rotY = 0;

// coordinates for the vertices of the cube
double x = 0.6;
double y = 0.6;
double z = 0.6;

void DrawCube(){
    
    glClearColor(0.4,0.4,0.4,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(rotX, 1.0, 0.0, 0.0);
    glRotatef(rotY, 0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.3, 0.5);
        glVertex3f(0, y, 0);
        glVertex3f(x, y, 0);
        glVertex3f(0, y, z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.3, 0.5);
        glVertex3f(0, y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, y, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.1, 0.5);
        glVertex3f(z, y, 0);
        glVertex3f(x, y, z);
        glVertex3f(x, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.1, 0.5);
        glVertex3f(x, y, z);
        glVertex3f(x, 0, 0);
        glVertex3f(x, 0, z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.1, 0.4);
        glVertex3f(x, y, z);
        glVertex3f(x, 0, z);
        glVertex3f(0, 0, z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.1, 0.3);
        glVertex3f(x, y, z);
        glVertex3f(0, y, z);
        glVertex3f(0, 0, z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.4, 0.3);
        glVertex3f(0, 0, z);
        glVertex3f(0, y, z);
        glVertex3f(0, y, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.4, 0.2);
        glVertex3f(0, 0, 0);
        glVertex3f(0, y, 0);
        glVertex3f(0, 0, z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.4, 0.2);
        glVertex3f(x, y, 0);
        glVertex3f(x, 0, 0);
        glVertex3f(0, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.4, 0.0);
        glVertex3f(x, y, 0);
        glVertex3f(0, y, 0);
        glVertex3f(0, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.3, 0.5);
        glVertex3f(0, 0, 0);
        glVertex3f(x, 0, 0);
        glVertex3f(0, 0, z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.5, 0.5);
        glVertex3f(0, 0, z);
        glVertex3f(x, 0, z);
        glVertex3f(x, 0, 0);
    glEnd();

    glFlush();
    glutSwapBuffers();

}

void keyboard(int key, int x, int y){

    if (key == GLUT_KEY_RIGHT){
        rotY += 15;
    }
    else if (key == GLUT_KEY_LEFT){
        rotY -= 15;
    }
    else if (key == GLUT_KEY_DOWN){
        rotX -= 15;
    }
    else if (key == GLUT_KEY_UP){
        rotX += 15;
    }

    glutPostRedisplay();

}

int main(int argc, char **argv){

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Linux Journal Opensomething");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(DrawCube);
    glutSpecialFunc(keyboard);

    glutMainLoop();

    return 0;

}
