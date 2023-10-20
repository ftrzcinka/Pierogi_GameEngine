#pragma once
#include "pch.h"

namespace pr {
	class WindowImplementation {
	public:
		virtual void CreateWindow(const std::string& name, int width, int height) = 0;
		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual ~WindowImplementation() {};
	};
}
