#pragma once
#include "Ball.h"
#include "Board.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <vector>
class Board;
class Ball;
class GUI
{
private:
	QGraphicsScene* scene;
	QGraphicsView* view;
	int guiWidth;
	int guiHeight;
	int guiCoef;
	int guiDiameter;
	std::vector <Ball*> *balls;
	std::vector <QGraphicsEllipseItem*> guiBalls;
	Board* board;
public:
	GUI();
	void print(std::string s);
	void print(int i);
	void show();
	void draw();
	void refresh();
	void setGuiWidth(int guiWidth);
	void setGuiHeight(int guiHeight);
	void setGuiDiameter(int guiDiameter);
	void setGuiCoef(int guiCoef);
	void setBalls(std::vector <Ball*> *balls);
	int getGUICoordinateX(int x);
	int getGUICoordinateY(int y);
	void hideBalls();
};
