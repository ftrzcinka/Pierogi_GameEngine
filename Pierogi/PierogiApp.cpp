#include "pch.h"
#include "Utilities.h"

#include "Pierogi.h"

#include "PierogiApp.h"

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "../stbi/stb_image.h"
#include "Renderer.h"


namespace pr {

	template<typename T>
	PierogiApp<T>::PierogiApp() {
		mWindow.CreateWindow("Game_FT Window", 1500, 800);

		mRenderer.Init();

		SetWindowClosedCallback([this]() {DefaultWindowCloseHandler(); });
	}

	template<typename T>
	void PierogiApp<T>::Init() {
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void PierogiApp<T>::RunInterface() {
		sInstance->Run();
	}

	template<typename T>
	void PierogiApp<T>::OnUpdate() {
	}

	template<typename T>
	void PierogiApp<T>::Draw(int x, int y, Picture& picture)
	{
		mRenderer.Draw(x, y, picture);
	}

	template<typename T>
	void PierogiApp<T>::Draw(Unit& unit)
	{
		mRenderer.Draw(unit);
	}

	template<typename T>
	void PierogiApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) {
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void PierogiApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void PierogiApp<T>::SetWindowClosedCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowClosedCallback(callbackFunc);
	}

	template<typename T>
	void PierogiApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}

	template<typename T>
	void PierogiApp<T>::Run() {

		pr::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue) {
			mRenderer.Clear();

			shader.Bind();
			shader.setUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.swapBuffers();
			mWindow.pollEvents();

		}
	}


}