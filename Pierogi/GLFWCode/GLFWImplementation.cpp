#include "pch.h"
#include "GLFWImplementation.h"

#include "GLFW/glfw3.h"

namespace pr {
	GLFWImplementation::GLFWImplementation() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void GLFWImplementation::CreateWindow(const std::string& name, int width, int height) {
		mWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		if (mWindow == NULL) {
			PR_ERROR("Failed to create Window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallBacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
			if (action == GLFW_PRESS) {
				CallBacks* callbacks{ (CallBacks*)glfwGetWindowUserPointer(window) };
				KeyPressed e{ keycode };
				callbacks->keyPressedFunc(e);
			}
			else if (action == GLFW_RELEASE) {
				CallBacks* callbacks{ (CallBacks*)glfwGetWindowUserPointer(window) };
				KeyReleased e{ keycode };
				callbacks->keyReleasedFunc(e);
			}
			});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			CallBacks* callbacks{ (CallBacks*)glfwGetWindowUserPointer(window) };
			callbacks->windowClosedFunc();
		});
	}
	int GLFWImplementation::GetHeight() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}
	int GLFWImplementation::GetWidth() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}
	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}
	void GLFWImplementation::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mCallBacks.keyPressedFunc = callbackFunc;
	}
	void GLFWImplementation::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mCallBacks.keyReleasedFunc = callbackFunc;
	}
	void GLFWImplementation::SetWindowClosedCallback(std::function<void()> callbackFunc)
	{
		mCallBacks.windowClosedFunc = callbackFunc;
	}
}
