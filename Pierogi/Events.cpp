#include "pch.h"
#include "Events.h"

namespace pr {
	KeyPressed::KeyPressed(int keyCode): mKeyCode(keyCode) {
	}

	int KeyPressed::getKeyCode() const {
		return mKeyCode;
	}

	KeyReleased::KeyReleased(int keyCode) : mKeyCode(keyCode) {
	}

	int KeyReleased::getKeyCode() const {
		return mKeyCode;
	}
}