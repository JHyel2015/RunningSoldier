#include <GL/freeglut.h>

int refreshRate = 300;

void reshape(GLint w, GLint h);
void initGL();
void timer(int value);

void display3D();

void dragFloor();
void dragPlayer();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejecricio Transformaciones de la vista");

    glutDisplayFunc(display3D);
    glutReshapeFunc(reshape);

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
    dragPlayer();
    glPopMatrix();

    glPushMatrix();
    dragFloor();
    glPopMatrix();


    glutSwapBuffers();
}
