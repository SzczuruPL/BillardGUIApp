#pragma once
#include "Constants.h"
#include "Board.h"
class Board;
class Ball
{
private:
	int r; // promien kuli
	int x;
	int y;
	//Color color;
	int number;
	//Type type;
	int speed;
	int angle; // kat uderzenia liczony od wspol x (patrz uklad wspl)
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

