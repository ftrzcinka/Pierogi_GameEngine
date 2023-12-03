#pragma once
#include "Utilities.h"
#include "pch.h"
#include "PictureImplementation.h"

namespace pr {
	class PIEROGI_API Picture {
	public:
		Picture(const std::string& textureFile);
		Picture(std::string&& textureFile);
		void Bind();
	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}