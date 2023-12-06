#pragma once
#include "pch.h"

#include "PictureImplementation.h"

namespace pr {
	class OpenGLPicture : public PictureImplementation {
	public:
		OpenGLPicture(const std::string& textureFile);
		OpenGLPicture(std::string&& textureFile);


		void Bind() override;

		~OpenGLPicture();

	private:

		unsigned int mPictureTexture;
	};
}