#define _USE_MATH_DEFINES
#include <GL/freeglut.h>
#include <cmath>
#include "common.h"

void dragFloor() {

	glColor3f(0.92f, 0.88f, 0.77f);

	glBegin(GL_POLYGON);
	glTexCoord2f(-5.0f, -15.0f);
	glVertex3f(-10.0f, -30.0f, 0.0f);
	glTexCoord2f(5.0f, -15.0f);
	glVertex3f(10.0f, -30.0f, 0.0f);
	glTexCoord2f(5.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glTexCoord2f(-5.0f, 0.0f);
	glVertex3f(-10.0f, 0.0f, 0.0f);
	glEnd();
}

void dragFloors(int cont) {
	for (int i = -2; i < cont; i++)
	{
		glPushMatrix();
		glTranslatef(20.0f * (float)i, 0.0f, 0.0f);
		dragFloor();
		glPopMatrix();
	}
}

void dragCloud(int size) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	const float RAD = M_PI / 180;

	float radio = size * 0.35f;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float inRad = i * RAD;
		float x = (cos(inRad) * radio);
		float y = sin(inRad) * radio;
		float s = (x) / (2.0f * radio) + 0.5f;
		float t = (y) / (2.0f * radio) + 0.5f;
		glTexCoord2f(s, t);
		glVertex2f(x, y);
	}
	glEnd();

	radio -= size * 0.15f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float inRad = i * RAD;
		float x = (cos(inRad) * radio)+ size * -0.35;
		float y = sin(inRad) * radio;
		float s = (x) / (2.0f * radio) + 0.5f;
		float t = (y) / (2.0f * radio) + 0.5f;
		glTexCoord2f(s, t);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float inRad = i * RAD;
		float x = (cos(inRad) * radio)+ size * 0.35;
		float y = sin(inRad) * radio;
		float s = (x) / (2.0f * radio) + 0.5f;
		float t = (y) / (2.0f * radio) + 0.5f;
		glTexCoord2f(s, t);
		glVertex2f(x, y);
	}
	glEnd();
}