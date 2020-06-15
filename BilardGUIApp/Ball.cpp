#include "Ball.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

Ball::Ball(double r, int number, double mass, Board* board)
{
	this->mass = mass;
	this->r = r;
	this->number = number;
	this->board = board;
	speed = 0;
	onBoard = false;
	changed = false;
	angle = 0;
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

double Ball::getRadius()
{
	return r;
}

double Ball::getX()
{
	return x;
}

double Ball::getY()
{
	return y;
}

int Ball::getNumber()
{
	return 0;
}

double Ball::getSpeed()
{
	return 0;
}

double Ball::getAngle()
{
	return 0;
}

bool Ball::isTouchingEdge()
{
	return true;//(x <= r or x >= board->getWidth() - r or y <= r or y >= board->getHeight() - r);

	//return (pos < 0 || pos > board->getWidth()) ? () : (pos);
	//return (pos<0 || pos > board->getHeight()) ? (0) : (pos);
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
	double d = 2 * r;
	x = x0 = i * sqrt(3) / 2 * d + 3. / 4. * board->getWidth();
	y = y0 = (double)i * d / 2.0 - (double) d * j + board->getHeight() / 2.0;
}

void Ball::setInitialCueCoordinates(Board* board)
{
	x = x0 = 1. / 4. * board->getWidth();
	y = y0 = board->getHeight() / 2.;
}

void Ball::setOnBoard(bool onBoard)
{
	this->onBoard = onBoard;
}

void Ball::setChanged(bool changed)
{
	this->changed = changed;
}

double Ball::getX(double t)
{
	double g = board->getG();
	double cof = board->getCof();
	double v0x = v0 * cos(angle);
	double a = cof * g;
	double ax = a * cos(angle);
	x = x0 + v0x * t - ax * t * t / 2;
	isTouchingEdge();
	return x;
}

double Ball::getY(double t)
{
	double g = board->getG();
	double cof = board->getCof();
	double v0y = v0 * sin(angle);
	double a = cof * g;
	double ay = a * sin(angle);
	y = y0 + v0y * t - ay * t * t / 2;
	return y;
}

double Ball::getVx(double t)
{
	bool vxPositiveS = 0;
	bool vxPositiveE = 0;
	double g = board->getG();
	double cof = board->getCof();
	Vx = v0 * cos(angle);
	if (Vx > 0)
		vxPositiveS = 1;
	double a = cof * g;
	double ax = a * cos(angle);
	Vx = Vx - ax * t;
	if (Vx > 0)
		vxPositiveE = 1;
	if (vxPositiveS != vxPositiveE)
		Vx = 0;
	return Vx;
}

double Ball::getVy(double t)
{
	bool vyPositiveS = 0;
	bool vyPositiveE = 0;
	double g = board->getG();
	double cof = board->getCof();
	Vy = v0 * sin(angle);
	if (Vy > 0)
		vyPositiveS = 1;
	double a = cof * g;
	double ay = a * sin(angle);
	Vy = Vy - ay * t;
	if (Vy > 0)
		vyPositiveE = 1;
	if (vyPositiveS != vyPositiveE)
		Vy = 0;
	return Vy;
}

double Ball::getG()
{
	return board->getG();
}

double Ball::getCof()
{
	return board->getCof();
}

void Ball::setX(double x)
{
	this->x = x;
}

void Ball::setY(double y)
{
	this->y = y;
}

void Ball::setV0(double v0)
{
	this->v0 = v0;
}

void Ball::setAngle(double angle)
{
	this->angle = angle;
}

bool Ball::isMoving()
{
	//return (Vx > 0 && Vy == 0 || Vx == 0 && Vy > 0 || Vx > 0 && Vy > 0);
	return (Vx != 0 && Vy != 0);
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
