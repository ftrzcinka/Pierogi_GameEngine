#include "BattleBoard.h"

BattleBoard::BattleBoard()
{
	//Row 1
	Board.emplace_back(20, 500);
	Board[activeTile].toggleActive();
	Board.emplace_back(170, 500);
	Board.emplace_back(320, 500);
	Board.emplace_back(470, 500);
	Board.emplace_back(620, 500);
	Board.emplace_back(770, 500);

	//Row 2
	Board.emplace_back(20, 350);
	Board.emplace_back(170, 350);
	Board.emplace_back(320, 350);
	Board.emplace_back(470, 350);
	Board.emplace_back(620, 350);
	Board.emplace_back(770, 350);

	//Row 3
	Board.emplace_back(20, 200);
	Board.emplace_back(170, 200);
	Board.emplace_back(320, 200);
	Board.emplace_back(470, 200);
	Board.emplace_back(620, 200);
	Board.emplace_back(770, 200);

	//Row 4
	Board.emplace_back(20, 50);
	Board.emplace_back(170, 50);
	Board.emplace_back(320, 50);
	Board.emplace_back(470, 50);
	Board.emplace_back(620, 50);
	Board.emplace_back(770, 50);

	
	//Establish ships
	establishShip3();
	establishShip2();

	Board[ship2.startTile].setShip();
	Board[ship2.endTile].setShip();
	Board[ship3.startTile].setShip();
	Board[ship3.middleTile].setShip();
	Board[ship3.endTile].setShip();

	
	//Estblaish shots
	shotsLeft.emplace_back("../Assets/Images/0.png");
	shotsLeft.emplace_back("../Assets/Images/1.png");
	shotsLeft.emplace_back("../Assets/Images/2.png");
	shotsLeft.emplace_back("../Assets/Images/3.png");
	shotsLeft.emplace_back("../Assets/Images/4.png");
	shotsLeft.emplace_back("../Assets/Images/5.png");
	shotsLeft.emplace_back("../Assets/Images/6.png");
	shotsLeft.emplace_back("../Assets/Images/7.png");
	shotsLeft.emplace_back("../Assets/Images/8.png");
	shotsLeft.emplace_back("../Assets/Images/9.png");
	shotsLeft.emplace_back("../Assets/Images/10.png");
	shotsLeft.emplace_back("../Assets/Images/11.png");
	shotsLeft.emplace_back("../Assets/Images/12.png");
	shotsLeft.emplace_back("../Assets/Images/13.png");
	shotsLeft.emplace_back("../Assets/Images/14.png");
	shotsLeft.emplace_back("../Assets/Images/15.png");


	title.emplace_back("../Assets/Images/title.png");
	title.emplace_back("../Assets/Images/won.png");
	title.emplace_back("../Assets/Images/lost.png");
}

void BattleBoard::moveRight()
{
	short prev = activeTile;
	bool found = false;

	while (!found) {
		activeTile += 1;
		if (activeTile < 0 || activeTile > 23) {
			activeTile = 0;
		}

		if (!Board[activeTile].isHit() && !Board[activeTile].isMissed()) {
			found = true;
		}
	}

	Board[prev].toggleActive();
	Board[activeTile].toggleActive();
}

void BattleBoard::moveLeft(){

	short prev = activeTile;
	bool found = false;

	while (!found) {
		activeTile -= 1;
		if (activeTile < 0 || activeTile > 23) {
			activeTile = 23;
		}

		if (!Board[activeTile].isHit() && !Board[activeTile].isMissed()) {
			found = true;
		}
	}

	Board[prev].toggleActive();
	Board[activeTile].toggleActive();
}

void BattleBoard::moveUp()
{
	short prev = activeTile;
	bool found = false;

	while (!found) {
		activeTile -= 6;
		if (activeTile < 0 || activeTile > 23) {
			activeTile += 24;
		}

		if (!Board[activeTile].isHit() && !Board[activeTile].isMissed()) {
			found = true;
		}
	}

	Board[prev].toggleActive();
	Board[activeTile].toggleActive();
}

void BattleBoard::moveDown()
{
	short prev = activeTile;
	bool found = false;

	while (!found) {
		activeTile += 6;
		if (activeTile < 0 || activeTile > 23) {
			activeTile -= 24;
		}

		if (!Board[activeTile].isHit() && !Board[activeTile].isMissed()) {
			found = true;
		}
	}

	Board[prev].toggleActive();
	Board[activeTile].toggleActive();
}

void BattleBoard::shoot()
{
	if (shots > 0) {
		Board[activeTile].toggleActive();

		if (Board[activeTile].isShip()) {
			Board[activeTile].toggleHit();
			hit++;
		}
		else {
			Board[activeTile].toggleMiss();
		}

		shots--;
	}
}

short BattleBoard::getShotsLeft()
{
	return shots;
}

pr::Picture& BattleBoard::getShotsLeftPic()
{
	return shotsLeft[shots];
}

pr::Picture& BattleBoard::getTilePic(short loc)
{
	return Board[loc].getCurrPicture();
}

int BattleBoard::getCurrXCoord(short loc)
{
	return Board[loc].getXCoord();
}

int BattleBoard::getCurrYCoord(short loc)
{
	return Board[loc].getYCoord();
}

void BattleBoard::restart()
{
	for (short i = 0; i < 24; i++) {
		Board[i].reset();
	}
	activeTile = 0;
	shots = 15;
	hit = 0;


	Board[activeTile].toggleActive();

	establishShip3();
	establishShip2();

	Board[ship2.startTile].setShip();
	Board[ship2.endTile].setShip();
	Board[ship3.startTile].setShip();
	Board[ship3.middleTile].setShip();
	Board[ship3.endTile].setShip();

}

pr::Picture& BattleBoard::getTitleCard()
{
	if (hit == 5) {
		return title[1];
	}
	else if (shots == 0) {
		return title[2];
	}
	else {
		return title[0];
	}
}

void BattleBoard::establishShip2()
{
	ship2.size = 2;
	ship2.middleTile = -1; //no middle tile
	std::random_device rd;
	std::uniform_int_distribution<int> start(0, 23);
	std::uniform_int_distribution<int> orient(0, 1);

	ship2.orientation = bool(orient(rd));
	ship2.startTile = short(start(rd));

	if (!ship2.orientation) { //Ship horizontal
		ship2.endTile = ship2.startTile + 1;
		bool found = false;
		while (!found) {
			if (ship2.startTile == ship3.startTile || ship2.startTile == ship3.middleTile || ship2.startTile == ship3.endTile
				|| ship2.endTile == ship3.endTile || ship2.endTile == ship3.middleTile || ship2.endTile == ship3.startTile) {
				ship2.startTile = short(start(rd));
				ship2.endTile = ship2.startTile + 1;
			} else if (ship2.startTile == 5 || ship2.startTile == 11 || ship2.startTile == 17 || ship2.startTile == 23) {
				ship2.startTile -= 1;
				ship2.endTile = ship2.startTile + 1;
			}
			else {
				found = true;
			}
		}
	}
	else { //Ship vertical
		ship2.endTile = ship2.startTile + 6;
		bool found = false;
		while (!found) {
			if (ship2.startTile == ship3.startTile || ship2.startTile == ship3.middleTile || ship2.startTile == ship3.endTile
				|| ship2.endTile == ship3.endTile || ship2.endTile == ship3.middleTile || ship2.endTile == ship3.startTile) {
				ship2.startTile = short(start(rd));
				ship2.endTile = ship2.startTile + 6;
			}
			else if (ship2.startTile == 18 || ship2.startTile == 19 || ship2.startTile == 20 || ship2.startTile == 21 
				|| ship2.startTile == 22 || ship2.startTile == 23) {
				ship2.startTile -= 6;
				ship2.endTile = ship2.startTile + 6;
			}
			else {
				found = true;
			}
		}
	}
	//std::cout << "Ship 2: " << ship2.startTile << "  " << ship2.endTile << std::endl;
}

void BattleBoard::establishShip3()
{
	ship3.size = 3;
	std::random_device rd;
	std::uniform_int_distribution<int> start(0, 23);
	std::uniform_int_distribution<int> orient(0, 1);

	ship3.orientation = bool(orient(rd));
	ship3.startTile = short(start(rd));

	if (!ship3.orientation) { //Ship horizontal

		if (ship3.startTile == 5 || ship3.startTile == 11 || ship3.startTile == 17 || ship3.startTile == 23
			|| ship3.startTile == 4 || ship3.startTile == 10 || ship3.startTile == 16 || ship3.startTile == 22) {
			ship3.startTile -= 2;
		}

		ship3.middleTile = ship3.startTile + 1;
		ship3.endTile = ship3.startTile + 2;
	}
	else { //Ship vertical

		if (ship3.startTile == 12 || ship3.startTile == 13 || ship3.startTile == 14 || ship3.startTile == 15 || ship3.startTile == 16
			|| ship3.startTile == 17 || ship3.startTile == 18 || ship3.startTile == 19 || ship3.startTile == 20 || ship3.startTile == 21
			|| ship3.startTile == 22 || ship3.startTile == 23) {
			ship3.startTile -= 12;
		}

		ship3.middleTile = ship3.startTile + 6;
		ship3.endTile = ship3.startTile + 12;

	}
	//std::cout << "Ship 3: " << ship3.startTile << "  " << ship3.middleTile << "  " << ship3.endTile << std::endl;
}
