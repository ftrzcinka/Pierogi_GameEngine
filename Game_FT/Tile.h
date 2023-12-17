#pragma once
#include "Pierogi.h"

class Tile {
public:
	Tile(int x, int y);

	bool isActive();
	void toggleActive();
	bool isClear();
	void toggleClear();
	bool isHit();
	void toggleHit();
	bool isMissed();
	void toggleMiss();

	void setShip();
	bool isShip();

	int getXCoord();
	int getYCoord();
	void setXCoord(int x);
	void setYCoord(int y);

	void setCurr(short val);

	void reset();

	pr::Picture& getCurrPicture();
private:
	std::vector<pr::Picture> TilePicture;
	
	bool active{ false };
	bool clear{ true };
	bool hit{ false };
	bool miss{ false };

	bool ship{ false };

	int xCoor;
	int yCoor;

	short currPicture{ 0 };

	void setCurrPic();
};