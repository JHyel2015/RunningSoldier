#include <GL/freeglut.h>
#include <soil.h>
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