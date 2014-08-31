#ifndef CHYME_TETRONIMO_BOARD_H
#define CHYME_TETRONIMO_BOARD_H

#include "tile.h"
#include "block.h"
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

namespace Tetronimo{
	class Board{
		Tile tiles[BOARD_HEIGHT][BOARD_HEIGHT];
		Block fallingblock;

		Board();

		void moveFallingBlock();
		void rotateFallingBlock();
		bool checkCollision();
		bool checkContact();
		bool checkValid();

	};
}

#endif //CHYME_TETRONIMO_BOARD_H