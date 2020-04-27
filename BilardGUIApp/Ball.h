#pragma once
#include "Constants.h"
#include "Board.h"
class Board;
class Ball
{
private:
	int r; // promien kuli
	int x0;
	int y0;
	int x;
	int y;
	//Color color;
	int number;
	//Type type;
	int speed;
	int v0;
	int angle; // kat uderzenia liczony od wspol x (patrz uklad wspl)
	double a; //przyspieszenie
	bool onBoard;
	int mass;
	Board* board;
	bool changed;
public:
	Ball (int r, int number, int mass, Board* board);
	Color getColor();
	Type getType();
	int getRadius();
	int getX();
	int getY();
	int getNumber();
	int getSpeed();
	int getAngle();
	bool isTouchingEdge();
	bool isTouchingAnotherBall(Ball *ball);
	void move();
	void setInitialCoordinates(int i, int j,Board *board); //i-nr kolumny, j-nr przekatnej (patrz rys.1)
	void setInitialCueCoordinates(Board* board);
	void setOnBoard(bool onBoard);
	void setChanged(bool changed);
	double getX(int t);
	double getY(int t);
	double getVx(int t);
	double getVy(int t);
	void setX(int x);
	void setY(int y);
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

