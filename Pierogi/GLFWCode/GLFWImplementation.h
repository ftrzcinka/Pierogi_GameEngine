#pragma once
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace pr {
	class GLFWImplementation : public WindowImplementation {
	public:
		GLFWImplementation();
		virtual void CreateWindow(const std::string& name, int width, int height) override;
		virtual int GetHeight() const override;
		virtual int GetWidth() const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) override;
		virtual void SetWindowClosedCallback(std::function<void()> callbackFunc) override;
	private:
		struct CallBacks {
			std::function<void(const KeyPressed&)> keyPressedFunc{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)> keyReleasedFunc{ [](const KeyReleased&) {} };
			std::function<void()> windowClosedFunc{ []() {} };
		} mCallBacks;
		
		GLFWwindow* mWindow;
	};
}