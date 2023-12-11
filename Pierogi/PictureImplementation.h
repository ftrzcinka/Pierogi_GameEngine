#pragma once
#include "pch.h"

namespace pr {
	class PictureImplementation {
	public:
		virtual void Bind() = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

		~PictureImplementation() {};
	};
}