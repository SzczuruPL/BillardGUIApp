#include "Player.h"

Player::Player(Board *board)
{
	this -> board=board;
}

bool Player::hit(int angle, int speed)
{
	return false;
}

bool Player::isWinner()
{
	return false;
}

bool Player::isSolid()
{
	return false;
}

bool Player::isStriped()
{
	return false;
}
