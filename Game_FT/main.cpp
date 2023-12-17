#include "Pierogi.h"
#include "Tile.h"
#include "BattleBoard.h"

class MyGame : public pr::PierogiApp<MyGame> {
public:

	MyGame() {
		SetKeyPressedCallback([this](const pr::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override {
		//std::cout << "Updating..." << std::endl;
		DrawBoard();
	}

	void OnKeyPress(const pr::KeyPressed& e) {
		if (e.getKeyCode() == PIEROGI_KEY_RIGHT) {
			board.moveRight();
		}
		else if (e.getKeyCode() == PIEROGI_KEY_LEFT) {
			board.moveLeft();
		}
		else if (e.getKeyCode() == PIEROGI_KEY_DOWN) {
			board.moveDown();
		}
		else if (e.getKeyCode() == PIEROGI_KEY_UP) {
			board.moveUp();
		}
		else if (e.getKeyCode() == PIEROGI_KEY_ENTER) {
			board.shoot();
		}
		else if (e.getKeyCode() == PIEROGI_KEY_R) {
			board.restart();
		}
	}

private:
	BattleBoard board;
	pr::Unit title{ "../Assets/Images/title.png", 2, 620 };
	pr::Unit description{"../Assets/Images/description.png", 1000, 45};
	pr::Unit shotsLabel{ "../Assets/Images/shotsleft.png", 950, 10 };

	void DrawBoard() {
		Draw(2, 630, board.getTitleCard());
		Draw(description);
		Draw(shotsLabel);
		Draw(1170, 13, board.getShotsLeftPic());
		for (short i = 0; i < 24; i++) {
			Draw(board.getCurrXCoord(i), board.getCurrYCoord(i), board.getTilePic(i));
		}
	}

};

PIEROGI_APPLICATION_START(MyGame);