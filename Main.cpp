#include <GL/freeglut.h>
#include "common.h"

int refreshRate = 300;

void reshape(GLint w, GLint h);
void initGL();
void timer(int value);

void display3D();

void dragFloor();
void dragPlayer();

void spinDisplayIzq();
void spinDisplayDer();

void keyDown(int key, int, int);
void keyUp(int key, int, int);

float posx = 0.0f;
bool isKey = false, isFirst = true;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejecricio Transformaciones de la vista");

    glutDisplayFunc(display3D);
    glutReshapeFunc(reshape);

    glutSpecialFunc(keyDown);
    glutSpecialUpFunc(keyUp);

    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();

}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, 1, 1, 100);
}

void initGL() {
    glClearColor(0.0f, 0.67f, 5, 0.89f);
    glEnable(GL_DEPTH_TEST);
    //    glDepthFunc(GL_ALWAYS);
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshRate, timer, 0);
}

void display3D() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
    glTranslatef(posx, 0.0f, 0.0f);
    dragPlayer();
    glPopMatrix();

    glPushMatrix();
    dragFloor();
    glPopMatrix();


    glutSwapBuffers();
}


void spinDisplayIzq() {
    if (isKey)
        posx -= 0.005f;
    glutPostRedisplay();
}

void spinDisplayDer() {
    if (isKey)
        posx += 0.005f;
    glutPostRedisplay();
}

void keyDown(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isKey = true;
        glutIdleFunc(spinDisplayIzq);
        break;
    case GLUT_KEY_RIGHT:
        isKey = true;
        glutIdleFunc(spinDisplayDer);
        break;
    default:
        break;
    }
}

void keyUp(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isKey = false;
        glutIdleFunc(NULL);
        break;
    case GLUT_KEY_RIGHT:
        isKey = false;
        glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}