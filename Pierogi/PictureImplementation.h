#pragma once
#include "pch.h"

namespace pr {
	class PictureImplementation {
	public:
		virtual void Bind() = 0;

		~PictureImplementation() {};
	};
}