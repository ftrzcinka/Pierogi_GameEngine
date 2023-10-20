#include "pch.h"
#include "PRWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace pr {
	PRWindow::PRWindow()
	{
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
	}
	void PRWindow::CreateWindow(const std::string& name, int height, int width)
	{
		mImplementation->CreateWindow(name, width, height);
	}
	int PRWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
	int PRWindow::GetWidth() const
	{
		return mImplementation->GetWidth();;
	}

	void PRWindow::swapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void PRWindow::pollEvents()
	{
		mImplementation->PollEvents();
	}


}