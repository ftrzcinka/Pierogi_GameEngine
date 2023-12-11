#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"
#include "Utilities.h"

pr::Renderer::Renderer()
{
#ifdef PIEROGI_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif PIEROGI_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif PIEROGI_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void pr::Renderer::Init()
{
	mImplementation->Init();
}

void pr::Renderer::Draw(int x, int y, Picture& picture)
{
	mImplementation->Draw(x, y, picture);
}

void pr::Renderer::Draw(Unit& unit)
{
	mImplementation->Draw(unit);
}

void pr::Renderer::Clear()
{
	mImplementation->Clear();
}
