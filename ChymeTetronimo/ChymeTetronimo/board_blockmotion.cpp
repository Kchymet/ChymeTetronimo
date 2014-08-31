#include "board.h"

namespace Tetronimo{
	void Board::moveFallingBlock(move_direction_t md){
		if (md == LEFT){
			(this->x)--;
			if (this->checkCollision()){
				(this->x)++;
			}
		}
		else if (md == RIGHT){
			(this->x)++;
			if (this->checkCollision()){
				(this->x)--;
			}
		}
	}
	void Board::rotateFallingBlock(rotate_direction_t rd){
		//TODO
	}
	void Board::softDropFallingBlock(){
		if (this->checkContact()){
			this->placeFallingBlock();
		}
		else{
			(this->y)++;
		}
	}
	void Board::hardDropFallingBlock(){
		while (!this->checkContact()){
			this->softDropFallingBlock();
		}
	}
}