#include "pch.h"
#include "Picture.h"

#include "GLFWCode/OpenGLPicture.h"

namespace pr {
	Picture::Picture(const std::string& textureFile) {
#ifdef PIEROGI_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(textureFile) };
#elif PIEROGI_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(textureFile) };
#elif PIEROGI_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(textureFile) };
#endif
	}

	Picture::Picture(std::string&& textureFile) {
#ifdef PIEROGI_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(move(textureFile)) };
#elif PIEROGI_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(move(textureFile))) };
#elif PIEROGI_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(move(textureFile)) };
#endif
	}

	void Picture::Bind() {
		mImplementation->Bind();
	}
}