#pragma once

#include "Utilities.h"
#include "pch.h"
#include "WindowImplementation.h"
#include "Events.h"

namespace pr {
	class PIEROGI_API PRWindow {
	public:
		PRWindow();
		void CreateWindow(const std::string& name, int width, int height);
		int GetHeight() const;
		int GetWidth() const;
		void swapBuffers();
		void pollEvents();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowClosedCallback(std::function<void()> callbackFunc);

	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
	};
}