#include <GL/freeglut.h>
#include "common.h"

void dragPlayer() {
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();
}