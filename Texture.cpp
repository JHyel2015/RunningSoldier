#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION   // use of stb functions once and for all
#include "stb_image.h"
#include <GL/glut.h>

Texture::Texture(){}

Texture::Texture(const char* texturePath, GLint textureFormat, GLuint idx)
{
	/*
	if (id)
	{
		glDeleteTextures(20, id);
	}
	glGenTextures(20, id);*/
	glBindTexture(GL_TEXTURE_2D, idx);

	// Wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// filtros
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	checkData(data, textureFormat, width, height);
	stbi_image_free(data);
}

void Texture::bind(GLenum type, GLuint idx)
{
	glEnable(type);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(type, idx);
}

void Texture::unbind(GLenum type)
{
	glDisable(type);
	glBindTexture(type, 0);
}


void Texture::checkData(unsigned char* data, GLint textureFormat, int width, int height)
{
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, width, height, 0, textureFormat, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		printf("Error al cargar la imagen de la texture");
	}
}