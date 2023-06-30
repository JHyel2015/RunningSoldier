#include <GL/freeglut.h>
#include "common.h"

int refreshRate = 300;

void reshape(GLint w, GLint h);
void initGL();
void timer(int value);

void display3D();

void dragFloor();
void dragFloors(int cont);
void dragCloud(int size);

void dragEnemy();

void dragPlayer();

void dragHongo();

void spinDisplayIzq();
void spinDisplayDer();
void spinDisplayJump();

void keyDown(int key, int, int);
void keyUp(int key, int, int);

float camX = 0.0f;
float camY = 0.0f;
float centerX = 0.0f;
float centerY = 0.0f;
float cameraSpeed = 0.01f;

float posx = 0.0f;
float posy = 0.0f;
float playerSpeed = 0.01f;
float playerVelocity = 0.0f;
bool isKey = false, isFirst = true, isJumping = false;

int cont = 10;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
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
    gluPerspective(100, (float)4/3, 1, 100);
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


    gluLookAt(camX, camY, 10, centerX, 0, 0, 0, 1, 0);

    glPushMatrix();
    glTranslatef(3.5f, 5.0f, 0.0f);
    dragCloud(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(posx, posy, 0.0f);
    dragPlayer();
    glPopMatrix();

    for (int i = 1; i <= 10; i++)
    {
        glPushMatrix();
        glTranslatef(5.0f * (float) i, 0.0f - (i % 2 ), 0.0f);
        dragEnemy();
        glPopMatrix();
    }

    dragFloors(5);


    glutSwapBuffers();
    if (isJumping)
    {
        posy += playerVelocity;
        playerVelocity -= 0.25f;

        if (playerVelocity < 0.0f) {
            posy = 0.0f;
            playerVelocity = 0.0f;
            isJumping = false;
        }
    }
}


void spinDisplayIzq() {
    if (isKey) {
        posx -= playerSpeed;
        camX -= cameraSpeed;
        centerX -= cameraSpeed;
    }
    glutPostRedisplay();
}

void spinDisplayDer() {
    if (isKey)
    {
        posx += playerSpeed;
        camX += cameraSpeed;
        centerX += cameraSpeed;
    }
    glutPostRedisplay();
}

void spinDisplayJump() {
    if (isJumping)
    {
        posy += playerVelocity;
        playerVelocity -= 0.01f;

        if (playerVelocity < 0.0f) {
            posy = 0.0f;
            playerVelocity = 0.0f;
            isJumping = false;
        }
    }
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
    case GLUT_KEY_UP:
        isKey = true;
        playerVelocity = 1.0f;
        isJumping = true;
        //glutIdleFunc(spinDisplayJump);
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
    case GLUT_KEY_UP:
        glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}