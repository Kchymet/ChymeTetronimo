#ifndef CHYME_TETRONIMO_BOARD_H
#define CHYME_TETRONIMO_BOARD_H

#include "tile.h"
#include "block.h"
#include "direction.h"
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

namespace Tetronimo{
	class Board{
	public:
		Tile tiles[BOARD_HEIGHT][BOARD_HEIGHT];
		Block fallingblock;
		int x, y;

		Board();

		void spawnNextBlock(Block);
		void moveFallingBlock(move_direction_t);
		void rotateFallingBlock(rotate_direction_t);
		void softDropFallingBlock();
		void hardDropFallingBlock();
		void placeFallingBlock();
		bool checkCollision();
		bool checkContact();
		bool checkValid();
	};
}

#endif //CHYME_TETRONIMO_BOARD_H