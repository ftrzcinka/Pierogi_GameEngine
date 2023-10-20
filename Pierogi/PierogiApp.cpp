#include "pch.h"

#include "PierogiApp.h"

namespace pr {

	template<typename T>
	PierogiApp<T>::PierogiApp() {}

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
	void PierogiApp<T>::Run() {

		mWindow.CreateWindow("Game_FT Window", 800, 600);

		while (mShouldContinue) {
			OnUpdate();

			mWindow.swapBuffers();
			mWindow.pollEvents();
		}
	}
}