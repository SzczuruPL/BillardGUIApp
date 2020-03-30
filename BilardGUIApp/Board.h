#pragma once
#include <iostream>
#include <vector>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "Ball.h"
class Ball;
class Board
{
private:
	int guiWidth;
	int guiHeight;
	int width;
	int height;
	int cof;
	int r;
	int mass;
	int cue_mass;
	std::vector <Ball*> balls;
public:
	Board(int guiWidth, int guiHeight, int guiCoef, int width,int height,int cof, int diameter, int mass, int cue_mass);
	void draw(QGraphicsScene* scene);
	void setBalls();
	int getWidth();
	int getHeight();
	void print();
};

