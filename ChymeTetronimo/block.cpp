#include "block.h"
#include "direction.h"

namespace Tetronimo{
	Block::Block(){}
	void Block::rotate(rotate_direction_t rd){
		transpose();
		if (rd == CLOCKWISE) reverseRows();
		else if (rd == COUNTERCLOCKWISE) reverseCols();
	}
	void Block::transpose(){
		for (int i = 0; i < dimension - 2; i++){
			for (int j = i + 1; j < dimension - 1; j++){
				swapTiles(&tiles[i][j], &tiles[j][i]);
			}
		}
	}
	void Block::reverseRows(){
		for (int i = 0; i < dimension; i++){
			for (int j = 0; j < dimension / 2; j++){
				swapTiles(&tiles[i][j], &tiles[i][dimension - j - 1]);
			}
		}
	}
	void Block::reverseCols(){
		for (int i = 0; i < dimension; i++){
			for (int j = 0; j < dimension / 2; j++){
				swapTiles(&tiles[j][i], &tiles[dimension - j - 1][i]);
			}
		}
	}
	void Block::swapTiles(Tile *a, Tile *b){
		Tile c = *a;
		*a = *b;
		*b = c;
	}
}