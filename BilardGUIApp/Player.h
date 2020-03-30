#pragma once
#include <vector>
#include "Ball.h"

class Player
{
private:
	Board* board;
	Type type;
public:
	Player (Board *board);
	bool hit(int angle, int speed);
	bool isWinner();
	bool isSolid();
	bool isStriped();
};

