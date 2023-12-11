#pragma once

#include "Utilities.h"

namespace pr {
	class PIEROGI_API KeyPressed {
	public:
		KeyPressed(int keycode);

		int getKeyCode() const;
	private:
		int mKeyCode;
	};

	class PIEROGI_API KeyReleased {
	public:
		KeyReleased(int keycode);

		int getKeyCode() const;
	private:
		int mKeyCode;
	};

	class PIEROGI_API WindowClosed {

	};
}
