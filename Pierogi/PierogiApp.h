#pragma once

#include "Utilities.h"
#include "PRWindow.h"

namespace pr {
	template<typename T>
	class PIEROGI_API PierogiApp {
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;
	private:
		PierogiApp();
		inline static PierogiApp* sInstance{ nullptr };
		bool mShouldContinue{ true };
		PRWindow mWindow;
	};
}

#include "PierogiApp.cpp"