#include <GL/freeglut.h>
#include "common.h"

void dragFloor() {

	glColor3f(0.92f, 0.88f, 0.77f);

	glBegin(GL_QUADS);
	glVertex3f(-100.0f, -30.0f, 0.0f);
	glVertex3f(100.0f, -30.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glVertex3f(-100.0f, 0.0f, 0.0f);
	glEnd();
}