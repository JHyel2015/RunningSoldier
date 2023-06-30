#include <GL/freeglut.h>
#include <soil.h>
#include <iostream>
#include "common.h"

void dragEnemy() {
	glColor3f((float)203/255, (float)50/255, (float)52/255);

	glBegin(GL_POLYGON);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.75f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.25f, 1.0f, 0.0f);
	glVertex3f(1.5f, 0.5f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(-0.75f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.5f, 0.0f);
	glVertex3f(-1.25f, 1.0f, 0.0f);
	glVertex3f(-1.5f, 0.5f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glEnd();

}

void dragPlayer() {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, textureIDs[currentTexture]);


	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, 3.0f, 0.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, 3.0f, 0.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);

}


void dragPlayer2() {
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-1.5f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(1.5f, -0.5f, 0.0f);
	glEnd();

	glColor3f((float)90 / 255, (float)100 / 255, (float)70 / 255);

	glBegin(GL_POLYGON);
	glVertex3f(-0.5f, 3.0f, 0.0f);
	glVertex3f(0.5f, 3.0f, 0.0f);
	glVertex3f(0.5f, 2.0f, 0.0f);
	glVertex3f(-0.5f, 2.0f, 0.0f);
	glEnd();

	glColor3f((float)120 / 255, (float)134 / 255, (float)107 / 255);

	glBegin(GL_POLYGON);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 2.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-1.5f, 2.0f, 0.0f);
	glVertex3f(-0.5f, 2.0f, 0.0f);
	glVertex3f(-0.5f, 1.5f, 0.0f);
	glVertex3f(-1.5f, 1.5f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.5f, 2.0f, 0.0f);
	glVertex3f(0.5f, 2.0f, 0.0f);
	glVertex3f(0.5f, 1.5f, 0.0f);
	glVertex3f(1.5f, 1.5f, 0.0f);
	glEnd();
}

void loadTexture(GLuint* texture) {
	*texture = SOIL_load_OGL_texture("textures/player.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
	);
	if (*texture == NULL) {
		printf("[Texture loader] \"%s\" failed to load!\n", "der.png");
	}
}
