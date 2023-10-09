#include "Pierogi.h"
#include<iostream>

class MyGame : public pr::PierogiApp<MyGame> {
public:
	virtual void OnUpdate() override {
		std::cout << "Updating..." << std::endl;
	}
};

PIEROGI_APPLICATION_START(MyGame);