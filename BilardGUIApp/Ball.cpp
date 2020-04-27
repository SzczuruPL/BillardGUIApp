#include "Ball.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

Ball::Ball(int r, int number, int mass, Board* board)
{
	this->mass = mass;
	this->r = r;
	this->number = number;
	this->board = board;
	speed = 0;
	onBoard = false;
	changed = false;
	//changed = rand() % 3;
}

Color Ball::getColor()
{
	return (number<9)?(Color)number:(Color)(number-8);
}

Type Ball::getType()
{
	return (Type)(number/9);
}

int Ball::getRadius()
{
	return r;
}

int Ball::getX()
{
	return x;
}

int Ball::getY()
{
	return y;
}

int Ball::getNumber()
{
	return 0;
}

int Ball::getSpeed()
{
	return 0;
}

int Ball::getAngle()
{
	return 0;
}

bool Ball::isTouchingEdge()
{
	return true;//(x <= r or x >= board->getWidth() - r or y <= r or y >= board->getHeight() - r);
}

bool Ball::isTouchingAnotherBall(Ball *ball)
{
	return (x-ball->x) * (x-ball->x) + (y-ball->y) * (y-ball->y) <= 4 * (r * r);
}

void Ball::move()
{

}

void Ball::setInitialCoordinates(int i, int j,Board *board)
{
	int d = 2 * r;
	x = i * sqrt(3) / 2 * d + 3. / 4. * board->getWidth() ;
	y = (double)i * d / 2.0 - (double) d * j + board->getHeight() / 2.0;
}

void Ball::setInitialCueCoordinates(Board* board)
{
	x = 1. / 4. * board->getWidth();
	y = board->getHeight() / 2.;
}

void Ball::setOnBoard(bool onBoard)
{
	this->onBoard = onBoard;
}

void Ball::setChanged(bool changed)
{
	this->changed = changed;
}

double Ball::getX(int t)
{
	double g = board->getG() / 100.;
	double cof = board->getCof() / 100.;
	double v0x = v0 * cos(angle);
	double a = cof * g;
	double ax = a * cos(angle);
	return x0 + v0x * t + ax * t * t / 2;
}

double Ball::getY(int t)
{
	double g = board->getG() / 100.;
	double cof = board->getCof() / 100.;
	double v0y = v0 * sin(angle);
	double a = cof * g;
	double ay = a * sin(angle);
	return y0 + v0y * t + ay * t * t / 2;
}

double Ball::getVx(int t)
{
	double g = board->getG() / 100.;
	double cof = board->getCof() / 100.;
	double v0x = v0 * cos(angle);
	double a = cof * g;
	double ax = a * cos(angle);
	return v0x + ax * t;
}

double Ball::getVy(int t)
{
	double g = board->getG() / 100.;
	double cof = board->getCof() / 100.;
	double v0y = v0 * sin(angle);
	double a = cof * g;
	double ay = a * sin(angle);
	return v0y + ay * t;
}

void Ball::setX(int x)
{
	this->x = x;
}

void Ball::setY(int y)
{
	this->y = y;
}

bool Ball::isMoving()
{
	return false;
}

void Ball::recountPosition()
{
}

void Ball::recountVelocity()
{
}

void Ball::recountAngle()
{
}

bool Ball::isOnBoard()
{
	return onBoard;
}

bool Ball::isWhite()
{
	return (getColor() == WHITE) ? (true) : (false);
}

bool Ball::isBlack()
{
	return (getColor() == BLACK) ? (true) : (false);
}

bool Ball::isSolid()
{
	return (getType()==SOLID)?(true):(false);
}

bool Ball::isStriped()
{
	return (getType() == STRIPED) ? (true) : (false);
}

bool Ball::hasChanged()
{
	return changed;
}
