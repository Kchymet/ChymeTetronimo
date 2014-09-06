#include "gtest/gtest.h"
#include "block.h"

#define BLOCKTESTS 7

static bool CWIBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool CCWIBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 0, 0, 0, 0 } };
static bool FIBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 } };

static bool CWLBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 0, 0 }, { 1, 1, 1, 0 }, { 1, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool CCWLBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 1, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool FLBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 1, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } };

static bool CWRLBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 1, 0, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool CCWRLBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 } };
static bool FRLBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 1, 1, 0 }, { 0, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } };

static bool CWSQBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 1, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool CCWSQBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 1, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool FSQBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 1, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

static bool CWTBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } };
static bool CCWTBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } };
static bool FTBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

static bool CWZBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 1, 0 }, { 0, 1, 1, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } };
static bool CCWZBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 1, 0, 0, 0 }, { 0, 0, 0, 0 } };
static bool FZBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } };

static bool CWRZBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 } };
static bool CCWRZBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } };
static bool FRZBLOCK[MAX_DIMENSION][MAX_DIMENSION] = { { 0, 0, 0, 0 }, { 0, 1, 1, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 } };

class BlockTest : public testing::Test{
protected:
	Tetronimo::Block blocks[BLOCKTESTS];
	Tetronimo::Block rblocks[BLOCKTESTS];
	Tetronimo::Block r2blocks[BLOCKTESTS];
	Tetronimo::Block r3blocks[BLOCKTESTS];
	virtual void SetUp(){
		//test each possible tile
		createTiles(&blocks[0].tiles[0][0], &IBLOCK[0][0],  MAX_DIMENSION);
		createTiles(&blocks[0].tiles[0][0], &LBLOCK[0][0],  MAX_DIMENSION);
		createTiles(&blocks[0].tiles[0][0], &RLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&blocks[0].tiles[0][0], &TBLOCK[0][0],  MAX_DIMENSION);
		createTiles(&blocks[0].tiles[0][0], &ZBLOCK[0][0],  MAX_DIMENSION);
		createTiles(&blocks[0].tiles[0][0], &RZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&blocks[0].tiles[0][0], &SQBLOCK[0][0], MAX_DIMENSION);
		//clockwise rotated versions
		createTiles(&rblocks[0].tiles[0][0], &CWIBLOCK[0][0], MAX_DIMENSION);
		createTiles(&rblocks[0].tiles[0][0], &CWLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&rblocks[0].tiles[0][0], &CWRLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&rblocks[0].tiles[0][0], &CWTBLOCK[0][0], MAX_DIMENSION);
		createTiles(&rblocks[0].tiles[0][0], &CWZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&rblocks[0].tiles[0][0], &CWRZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&rblocks[0].tiles[0][0], &CWSQBLOCK[0][0], MAX_DIMENSION);
		//counter-clockwise rotated versions
		createTiles(&r2blocks[0].tiles[0][0], &CCWIBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r2blocks[0].tiles[0][0], &CCWLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r2blocks[0].tiles[0][0], &CCWRLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r2blocks[0].tiles[0][0], &CCWTBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r2blocks[0].tiles[0][0], &CCWZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r2blocks[0].tiles[0][0], &CCWRZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r2blocks[0].tiles[0][0], &CCWSQBLOCK[0][0], MAX_DIMENSION);
		//180 versions
		createTiles(&r3blocks[0].tiles[0][0], &FIBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r3blocks[0].tiles[0][0], &FLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r3blocks[0].tiles[0][0], &FRLBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r3blocks[0].tiles[0][0], &FTBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r3blocks[0].tiles[0][0], &FZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r3blocks[0].tiles[0][0], &FRZBLOCK[0][0], MAX_DIMENSION);
		createTiles(&r3blocks[0].tiles[0][0], &FSQBLOCK[0][0], MAX_DIMENSION);
	}
	virtual void TearDown(){}
	
	void createTiles(Tetronimo::Tile *t,bool *b, int dim){
		for (int i = 0; i < dim*dim; i++){
			t[i].occupied = b[i];
		}
	}
	bool compareBlocks(Tetronimo::Block a, Tetronimo::Block b){
		for (int i = 0; i < MAX_DIMENSION; i++){
			for (int j = 0; j < MAX_DIMENSION; j++){
				if (a.tiles[i][j].occupied != b.tiles[i][j].occupied) return false;
			}

		}
		return true;
	}

};

TEST_F(BlockTest, ClockwiseRotation)
{
	for (int i = 0; i < BLOCKTESTS; i++){
		blocks[i].rotate(Tetronimo::CLOCKWISE);
		EXPECT_TRUE(compareBlocks(blocks[i],rblocks[i]));
		blocks[i].rotate(Tetronimo::CLOCKWISE);
		EXPECT_TRUE(compareBlocks(blocks[i], r3blocks[i]));
		blocks[i].rotate(Tetronimo::CLOCKWISE);
		EXPECT_TRUE(compareBlocks(blocks[i], r2blocks[i]));
	}
}
TEST_F(BlockTest, CClockwiseRotation)
{
	for (int i = 0; i < BLOCKTESTS; i++){
		blocks[i].rotate(Tetronimo::COUNTERCLOCKWISE);
		EXPECT_TRUE(compareBlocks(blocks[i], r2blocks[i]));
		blocks[i].rotate(Tetronimo::COUNTERCLOCKWISE);
		EXPECT_TRUE(compareBlocks(blocks[i], r3blocks[i]));
		blocks[i].rotate(Tetronimo::COUNTERCLOCKWISE);
		EXPECT_TRUE(compareBlocks(blocks[i], rblocks[i]));
	}
}