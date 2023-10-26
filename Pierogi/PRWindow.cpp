#include "pch.h"
#include "PRWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace pr {
	PRWindow::PRWindow()
	{
#ifdef PIEROGI_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif PIEROGI_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif PIEROGI_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif
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