#define _USE_MATH_DEFINES
#include <GL/freeglut.h>
#include <cmath>
#include "common.h"

void dragFloor() {

	glColor3f(0.92f, 0.88f, 0.77f);

	glBegin(GL_POLYGON);
	glVertex3f(-10.0f, -30.0f, 0.0f);
	glVertex3f(10.0f, -30.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
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
	const float RAD = M_PI / 180;

	float radio = size * 0.35f;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float inRad = i * RAD;
		glVertex2f((cos(inRad) * radio), sin(inRad) * radio);
	}
	glEnd();

	radio -= size * 0.15f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float inRad = i * RAD;
		glVertex2f(size * -0.35 + (cos(inRad) * radio), sin(inRad) * radio);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float inRad = i * RAD;
		glVertex2f(size * 0.35 + (cos(inRad) * radio), sin(inRad) * radio);
	}
	glEnd();
}