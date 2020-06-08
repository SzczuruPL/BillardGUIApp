#pragma once
#include "Constants.h"
#include "Board.h"
class Board;
class Ball
{
private:
	double r; // promien kuli
	double x0;
	double y0;
	double x;
	double y;
	//Color color;
	int number;
	//Type type;
	double speed;
	double v0;
	double Vx;
	double Vy;
	double angle; // kat W RADIANACH! uderzenia liczony od wspol x (patrz uklad wspl)
	double a; //przyspieszenie
	bool onBoard;
	double mass;
	Board* board;
	bool changed;
public:
	Ball (double r, int number, double mass, Board* board);
	Color getColor();
	Type getType();
	double getRadius();
	double getX();
	double getY();
	int getNumber();
	double getSpeed();
	double getAngle();
	bool isTouchingEdge();
	bool isTouchingAnotherBall(Ball *ball);
	void move();
	void setInitialCoordinates(int i, int j,Board *board); //i-nr kolumny, j-nr przekatnej (patrz rys.1)
	void setInitialCueCoordinates(Board* board);
	void setOnBoard(bool onBoard);
	void setChanged(bool changed);
	double getX(double t);
	double getY(double t);
	double getVx(double t);
	double getVy(double t);
	double getG();
	double getCof();
	void setX(double x);
	void setY(double y);
	void setV0(double v0);
	void setAngle(double angle);
	bool isMoving();
	void recountPosition();
	void recountVelocity();
	void recountAngle();
	bool isOnBoard();
	bool isWhite();
	bool isBlack();
	bool isSolid();
	bool isStriped();
	bool hasChanged();
};

