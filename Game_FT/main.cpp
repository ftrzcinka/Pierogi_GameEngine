#include "Pierogi.h"
#include<iostream>

class MyGame : public pr::PierogiApp<MyGame> {
public:

	MyGame() {
		SetKeyPressedCallback([this](const pr::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override {
		//std::cout << "Updating..." << std::endl;
		Draw(mUnit);
	}

	void OnKeyPress(const pr::KeyPressed& e) {
		if (e.getKeyCode() == PIEROGI_KEY_RIGHT) {
			mUnit.UpdateXCoor(50);
			std::cout << "Right Key Clicked" << std::endl;
		}
		else if (e.getKeyCode() == PIEROGI_KEY_LEFT) {
			mUnit.UpdateXCoor(-50);
			std::cout << "Left Key Clicked" << std::endl;
		}
	}

private:
	pr::Unit mUnit{ "../Assets/Images/test.png" , 100, 100 };
};

PIEROGI_APPLICATION_START(MyGame);