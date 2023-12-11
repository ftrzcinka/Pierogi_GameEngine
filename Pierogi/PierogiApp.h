#pragma once

#include "Utilities.h"
#include "PRWindow.h"
#include "Renderer.h"
#include "Picture.h"
#include "Events.h"
#include "keys.h"
#include "Unit.h"

namespace pr {

	constexpr int FPS{ 60 };

	template<typename T>
	class PierogiApp {
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		void Draw(int x, int y, Picture& picture);
		void Draw(Unit& unit);

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowClosedCallback(std::function<void()> callbackFunc);

		void DefaultWindowCloseHandler();

		friend typename T;
	private:
		PierogiApp();
		inline static PierogiApp* sInstance{ nullptr };
		bool mShouldContinue{ true };
		PRWindow mWindow;
		Renderer mRenderer;

		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

#include "PierogiApp.cpp"