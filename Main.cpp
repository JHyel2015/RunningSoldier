#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <GL/freeglut.h>
#include <soil.h>
#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <map>
#include <list>
#include "common.h"

using namespace std;
namespace fs = std::experimental::filesystem;

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
void loadTextures(const char* path, int cont);
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
float centerX = 0.0f;
float centerY = 0.0f;
float cameraSpeed = 0.01f;

float posx = 0.0f;
float posy = 0.0f;
float playerSpeed = 0.01f;
bool isKey = false, isFirst = true, isJumping = false;

float objectX = 0.0f;
float objectY = 0.0f;
float objectVelocityY = 0.0f;
float objectAccelerationY = -0.25f;

int cont = 10;

GLuint textureIDs[5];   // Array of texture IDs}
map<string, GLuint*> mapTextures;
int currentTexture = 0;
string currentAction = "stan";

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejecricio Transformaciones de la vista");

    // loadTexture(&textureIDs);
    loadTextures("ninja/stan", 4);
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
    if (isJumping) {
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

    // Update the current texture index
    currentTexture = (currentTexture + 1) % 4;
    // cout << sizeof(mapTextures[currentAction]) << endl;

    // currentTexture = (currentTexture + 1) % sizeof(mapTextures[currentAction]);

    glutPostRedisplay();
    glutTimerFunc(refreshRate, timer, 0);
}

void display3D() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    gluLookAt(camX, camY, 10, centerX, 0, 0, 0, 1, 0);

    glPushMatrix();
    glTranslatef(posx, objectY, 0.0f);
    dragPlayer();
    glPopMatrix();

    for (int i = 1; i <= 10; i++)
    {
        glPushMatrix();
        glTranslatef(5.0f * (float) i, 0.0f - (i % 2 ), 0.0f);
        dragEnemy();
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(3.5f, 5.0f, 0.0f);
    dragCloud(5);
    glPopMatrix();

    dragFloors(5);


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
        glutIdleFunc(spinDisplayIzq);
        break;
    case GLUT_KEY_RIGHT:
        isKey = true;
        glutIdleFunc(spinDisplayDer);
        break;
    case GLUT_KEY_UP:
        isKey = true;
        objectVelocityY = 1.0f;
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
        glutIdleFunc(NULL);
        break;
    case GLUT_KEY_UP:
        glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}

void loadTextures(const char *path, int cont) {

    string a = "textures/";
    string path2 = "";

    a += path;
    a += "/";

    string path3 = "./textures/ninja";
    string dir = "";
    int cont2 = 0;
    int cont3 = 0;
    /*
    for (const auto& entry : fs::directory_iterator(path3)) {

        cout << entry.path() << endl;
        dir = entry.path().filename().string();
        cout << dir << endl;

        cont2 = 0;
        cont3 = 0;

        for (const auto& entry2 : fs::directory_iterator(entry.path()))
        {
            cont2++;
        }


        GLuint* listTexturesIDs = new GLuint(cont2);

        for (const auto& entry2 : fs::directory_iterator(entry.path()))
        {
            const char* filename = entry2.path().string().c_str();
            cout << filename << endl;
            cout << cont3 << endl;
            ++cont3;
            listTexturesIDs[cont3] = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
        }

        mapTextures[dir] = listTexturesIDs;
        cout << mapTextures[dir] << endl;

    }

    for (const auto& pair : mapTextures) {
        cout << pair.first << " " << endl;
    }
    */

    for (int i = 0; i < cont; i++)
    {
        path2 = a + to_string(i);
        path2 += ".png";

        const char* filename = path2.c_str();
        printf("%s\n", filename);
        textureIDs[i] = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
    }

}