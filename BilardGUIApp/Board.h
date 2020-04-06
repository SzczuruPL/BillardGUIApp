#pragma once
#include <iostream>
#include <QString>
#include <vector>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "Ball.h"
#include "GUI.h"
class Ball;
class Board
{
private:
	int width;
	int height;
	int cof;
	int r;
	int mass;
	int cue_mass;
	std::vector <Ball*> *balls;
	GUI* gui;
public:
	Board(int guiCoef, int width,int height,int cof, int diameter, int mass, int cue_mass, GUI* gui);
	void draw();
	void setBalls();
	int getWidth();
	int getHeight();
};

