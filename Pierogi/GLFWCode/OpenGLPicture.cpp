#include "pch.h"
#include "Utilities.h"
#include "OpenGLPicture.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../stbi/stb_image.h"

namespace pr{
	OpenGLPicture::OpenGLPicture(const std::string& textureFile)
	{
		glGenTextures(1, &mPictureTexture);
		glBindTexture(GL_TEXTURE_2D, mPictureTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);
		int width, height, numColChan;
		unsigned char* data = stbi_load(textureFile.c_str(), &width, &height, &numColChan, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			PR_ERROR("failed to load a texture picture from file!");
		}

		stbi_image_free(data);
	}
	OpenGLPicture::OpenGLPicture(std::string&& textureFile)
	{
		glGenTextures(1, &mPictureTexture);
		glBindTexture(GL_TEXTURE_2D, mPictureTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);
		int width, height, numColChan;
		unsigned char* data = stbi_load(textureFile.c_str(), &width, &height, &numColChan, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			PR_ERROR("failed to load a texture picture from file!");
		}

		stbi_image_free(data);

	}
	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mPictureTexture);
	}
	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mPictureTexture);
	}
}