#include "Tile.h"

Tile::Tile(int x, int y)
{
	xCoor = x;
	yCoor = y;

	TilePicture.emplace_back("../Assets/Images/clear.png");
	TilePicture.emplace_back("../Assets/Images/active.png");
	TilePicture.emplace_back("../Assets/Images/miss.png");
	TilePicture.emplace_back("../Assets/Images/hit.png");
}

bool Tile::isActive()
{
	return active;
}

void Tile::toggleActive()
{
	active = !active;
	setCurrPic();
}

bool Tile::isClear()
{
	return clear;
}

void Tile::toggleClear()
{
	clear = !clear;
	setCurrPic();
}

bool Tile::isHit()
{
	return hit;
}

void Tile::toggleHit()
{
	hit = !hit;
	setCurrPic();
}

bool Tile::isMissed()
{
	return miss;
}

void Tile::toggleMiss()
{
	miss = !miss;
	setCurrPic();
}

void Tile::setShip()
{
	ship = true;
}

bool Tile::isShip()
{
	return ship;
}

int Tile::getXCoord()
{
	return xCoor;
}

int Tile::getYCoord()
{
	return yCoor;
}

void Tile::setXCoord(int x)
{
	xCoor = x;
}

void Tile::setYCoord(int y)
{
	yCoor = y;
}

void Tile::setCurr(short val)
{
	currPicture = val;
}

void Tile::reset()
{
	active = false;
	clear = false;
	hit = false;
	miss = false;
	ship = false;
	currPicture = 0;
}

pr::Picture& Tile::getCurrPicture()
{
	return TilePicture[currPicture];
}

void Tile::setCurrPic()
{
	if (hit) {
		currPicture = 3;
	}
	else if (miss) {
		currPicture = 2;
	}
	else if (active) {
		currPicture = 1;
	}
	else {
		currPicture = 0;
	}
}


