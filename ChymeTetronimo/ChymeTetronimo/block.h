#ifndef CHYME_TETRONIMO_BLOCK_H
#define CHYME_TETRONIMO_BLOCK_H

#include "tile.h"
#define MAX_DIMENSION 4

namespace Tetronimo{
	class Block{
		Tile tiles[MAX_DIMENSION][MAX_DIMENSION];
		int dimension; //used dimension. if it's only a 2x2 block, then only tiles[0][0] thru tiles[1][1] are used
		Block();
	};
}

#endif //CHYME_TETRONIMO_BLOCK_H