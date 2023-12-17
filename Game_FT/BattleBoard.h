#pragma once
#include "Pierogi.h"
#include "Tile.h"

class BattleBoard {
public:
	BattleBoard();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	void shoot();

	short getShotsLeft();
	pr::Picture& getShotsLeftPic();

	pr::Picture& getTilePic(short loc);
	int getCurrXCoord(short loc);
	int getCurrYCoord(short loc);

	void restart();

	pr::Picture& getTitleCard();

private:

	std::vector<Tile> Board; //4x6 tiles
	/*
		T0,  T1,  T2,  T3,  T4,  T5,
		T6,  T7,  T8,  T9,  T10, T11,
		T12, T13, T14, T15, T16, T17,
		T18, T19, T20, T21, T22, T23
	*/
	
	short activeTile{ 0 };

	struct Ship {
		short size;
		short startTile;
		short middleTile;
		short endTile;
		bool orientation; //0 is horizontal, 1 is vertical;
	} ship2, ship3;

	void establishShip2();
	void establishShip3();

	short shots{ 15 };
	std::vector<pr::Picture> shotsLeft;

	std::vector<pr::Picture> title;
	short hit{ 0 };
};