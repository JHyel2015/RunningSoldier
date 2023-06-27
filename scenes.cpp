#include <GL/freeglut.h>
#include "common.h"

void dragFloor() {

	glColor3f(0.92f, 0.88f, 0.77f);

	glBegin(GL_POLYGON);
	glVertex3f(-10.0f, -30.0f, 0.0f);
	glVertex3f(10.0f, -30.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(8.0f, 1.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 0.0f);
	glVertex3f(4.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 1.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glVertex3f(-8.0f, 1.0f, 0.0f);
	glVertex3f(-10.0f, 0.0f, 0.0f);
	glEnd();
}