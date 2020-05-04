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
class GUI;
class Board
{
private:
	double width;
	double height;
	double cof;
	double r;
	double g;
	double mass;
	double cue_mass;
	std::vector <Ball*> *balls;
	GUI* gui;
public:
	Board(double width, double height, double cof, double diameter, double mass, double cue_mass, double g, GUI* gui);
	void draw();
	void setBalls();
	double getWidth();
	double getHeight();
	double getCof();
	double getG();
	void setBall(int n, double x, double y);
	Ball* getBall(int n);
};

