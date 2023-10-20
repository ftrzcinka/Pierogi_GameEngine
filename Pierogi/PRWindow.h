#pragma once

#include "Utilities.h"
#include "pch.h"
#include "WindowImplementation.h"

namespace pr {
	class PIEROGI_API PRWindow {
	public:
		PRWindow();
		void CreateWindow(const std::string& name, int width, int height);
		int GetHeight() const;
		int GetWidth() const;
		void swapBuffers();
		void pollEvents();

	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
	};
}