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
		int numColChan;
		unsigned char* data = stbi_load(textureFile.c_str(), &mWidth, &mHeight, &numColChan, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
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
		int numColChan;
		unsigned char* data = stbi_load(textureFile.c_str(), &mWidth, &mHeight, &numColChan, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
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
	int OpenGLPicture::getWidth() const
	{
		return mWidth;
	}
	int OpenGLPicture::getHeight() const
	{
		return mHeight;
	}
	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mPictureTexture);
	}
}