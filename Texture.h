#pragma once
#include <GL/glut.h>


class Texture
{
private:
	GLuint *id = new GLuint[20];
	int width, height, nrChannels;

	void checkData(unsigned char* data, GLint textureFormat, int width, int height);

public:
	Texture();
	Texture(const char* texturePath, GLint textureFormat, GLuint idx);

	~Texture() {
		glDeleteTextures(20, id);
	}

	GLuint getId(GLuint index) const { return index; }

	void bind(GLenum type, GLuint idx);

	void unbind(GLenum type);

};