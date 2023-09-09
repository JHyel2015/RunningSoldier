
#include <GL/freeglut.h>
//#include <soil.h>
#include <string>
#include <iostream>
//#include <experimental/filesystem>
#include <map>
#include <vector>
#include <list>
#include "common.h"

#include "Texture.h"

using namespace std;
//namespace fs = std::experimental::filesystem;

int refreshRate = 300;

void reshape(GLint w, GLint h);
void initGL();
void timer(int value);

void display3D();

void dragFloor();
void dragFloors(int cont);
void dragCloud(int size);

void dragEnemy();

void loadTexture(GLuint** texture);
void loadTextures(const char* path, GLuint *textures, int ini, int cont);
void dragPlayer(GLuint texture);
void dragPlayer();

void dragHongo();

void spinDisplayIzq();
void spinDisplayDer();
void spinDisplayJump();

void keyDown(int key, int, int);
void keyUp(int key, int, int);

float camX = 0.0f;
float camY = 0.0f;
GLint numtextures = 0;
extern GLuint textures[30];
extern int izqder;
GLuint playerStan[20];
float centerX = 0.0f;
float centerY = 0.0f;
float cameraSpeed = 0.01f;

float posx = 0.0f;
float posy = 0.0f;
float playerSpeed = 0.05f;
bool isKey = false, isFirst = true, isJumping = false, isRunning = false;

float objectX = 0.0f;
float objectY = 0.0f;
float objectVelocityY = 0.0f;
float objectAccelerationY = -0.25f;

Texture miTextura;

int cont = 10;

GLuint textureIDs[5];   // Array of texture IDs}
map<string, GLuint*> mapTextures;
int currentTexture = 0;
int idxRunning = 4;
int numRunning = 5;
string currentAction = "stan";

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejecricio Transformaciones de la vista");

    // loadTexture(&textureIDs);
    //loadTextures("standing", playerStan, 0, 5);
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
    glGenTextures(30, textures);
    glClearColor(0.0f, 0.67f, 5, 0.89f);
    glEnable(GL_DEPTH_TEST);
    //    glDepthFunc(GL_ALWAYS);
    izqder = 1;
}

void timer(int value) {
    numRunning = 5;
    idxRunning = 4;
    playerSpeed = 0.05f;

    if (isJumping) {
        numRunning = 5;
        idxRunning = 19;
        playerSpeed = 0.1f;
        // Apply gravity to the vertical velocity
        objectVelocityY += objectAccelerationY;

        // Update the object's vertical position based on the velocity
        objectY += objectVelocityY;

        // Check if the object has landed (e.g., reached the ground level)
        if (objectY <= 0.0f) {
            // Reset the position and velocity to simulate a jump
            objectY = 0.0f;
            objectVelocityY = 0.0f;
            isJumping = false;
        }
    }

    if (isRunning && !isJumping)
    {
        numRunning = 10;
        idxRunning = 9;
    }

    // Update the current texture index
    currentTexture = (currentTexture + 1) % numRunning;
    // cout << sizeof(mapTextures[currentAction]) << endl;

    // currentTexture = (currentTexture + 1) % sizeof(mapTextures[currentAction]);

    glutPostRedisplay();
    glutTimerFunc(refreshRate, timer, 0);
}

void display3D() {
    miTextura = Texture("textures/nube.jpg", GL_RGB, textures[0]);
    miTextura = Texture("textures/arena.jpg", GL_RGB, textures[1]);
    miTextura = Texture("textures/crab/0.png", GL_RGBA, textures[2]);
    miTextura = Texture("textures/standing/0.png", GL_RGBA, textures[4]);
    miTextura = Texture("textures/standing/1.png", GL_RGBA, textures[5]);
    miTextura = Texture("textures/standing/2.png", GL_RGBA, textures[6]);
    miTextura = Texture("textures/standing/3.png", GL_RGBA, textures[7]);
    miTextura = Texture("textures/standing/4.png", GL_RGBA, textures[8]);
    miTextura = Texture("textures/running/0.png", GL_RGBA, textures[9]);
    miTextura = Texture("textures/running/1.png", GL_RGBA, textures[10]);
    miTextura = Texture("textures/running/2.png", GL_RGBA, textures[11]);
    miTextura = Texture("textures/running/3.png", GL_RGBA, textures[12]);
    miTextura = Texture("textures/running/4.png", GL_RGBA, textures[13]);
    miTextura = Texture("textures/running/5.png", GL_RGBA, textures[14]);
    miTextura = Texture("textures/running/6.png", GL_RGBA, textures[15]);
    miTextura = Texture("textures/running/7.png", GL_RGBA, textures[16]);
    miTextura = Texture("textures/running/8.png", GL_RGBA, textures[17]);
    miTextura = Texture("textures/running/9.png", GL_RGBA, textures[18]);
    miTextura = Texture("textures/jumping/0.png", GL_RGBA, textures[19]);
    miTextura = Texture("textures/jumping/1.png", GL_RGBA, textures[20]);
    miTextura = Texture("textures/jumping/2.png", GL_RGBA, textures[21]);
    miTextura = Texture("textures/jumping/3.png", GL_RGBA, textures[22]);
    miTextura = Texture("textures/jumping/4.png", GL_RGBA, textures[23]);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camX, camY, 10, centerX, 0, 0, 0, 1, 0);


    glPushMatrix();
    glTranslatef(posx, objectY, 0.0f);
    miTextura.bind(GL_TEXTURE_2D, textures[idxRunning+currentTexture]);
    dragPlayer();
    miTextura.unbind(GL_TEXTURE_2D);
    glPopMatrix();

    for (int i = 1; i <= 10; i++)
    {
        glPushMatrix();
        glTranslatef(5.0f * (float) i, 0.0f - (i % 2 ), 0.0f);
        glScalef(i % 2 + 1.0f, 1.0f + i % 2, 1.0f);
        miTextura.bind(GL_TEXTURE_2D, textures[2]);
        dragEnemy();
        miTextura.unbind(GL_TEXTURE_2D );
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(3.5f, 5.0f, 0.0f);
    miTextura.bind(GL_TEXTURE_2D, textures[0]);
    dragCloud(5);
    miTextura.unbind(GL_TEXTURE_2D);
    glPopMatrix();

    miTextura.bind(GL_TEXTURE_2D, textures[1]);
    dragFloors(5);
    miTextura.unbind(GL_TEXTURE_2D);


    glutSwapBuffers();
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

void keyDown(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isKey = true;
        isRunning = true;
        izqder = -1;
        glutIdleFunc(spinDisplayIzq);
        break;
    case GLUT_KEY_RIGHT:
        isKey = true;
        isRunning = true;
        izqder = 1;
        glutIdleFunc(spinDisplayDer);
        break;
    case GLUT_KEY_UP:
        isKey = true;
        objectVelocityY = 1.5f;
        isJumping = true;
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
        isRunning = false;
        glutIdleFunc(NULL);
        break;
    case GLUT_KEY_UP:
        glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}

void loadTextures(const char *path, GLuint *textures, int ini, int cont) {

    string a = "textures/";
    string path2 = "";

    a += path;
    a += "/";

    string path3 = "./textures/ninja";
    string dir = "";
    int cont2 = 0;
    int cont3 = 0;

    for (int i = 0; i < cont; i++)
    {
        path2 = a + to_string(i);
        path2 += ".png";

        const char* filename = path2.c_str();
        printf("%s\n", filename);
        miTextura = Texture(filename, GL_RGB, textures[1+i]);
        //textureIDs[i] = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
    }

}