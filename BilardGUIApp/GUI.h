#pragma once
#include "Ball.h"
#include "Board.h"
#include "Constants.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <vector>
#include <QTime>

//QBrush qColor[] = { Qt::white,Qt::yellow };
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
	std::vector <QGraphicsSimpleTextItem*> guiBallNumbers;
	Board* board;
	const QBrush qColor[9];
public:
	GUI();
	void print(std::string s);
	void print(int i);
	void show();
	void draw();
	void refresh();
	void delay(int i);
	void setGuiWidth(int guiWidth);
	void setGuiHeight(int guiHeight);
	void setGuiDiameter(int guiDiameter);
	void setGuiCoef(int guiCoef);
	void setBalls(std::vector <Ball*> *balls);
	int getGUICoordinateX(int x);
	int getGUICoordinateY(int y);
	QGraphicsSimpleTextItem* getTextNumber(int n, int x, int y);
	void setTextNumber(QGraphicsSimpleTextItem* text, Ball* ball, int x, int y);
	//void showBalls();
	//void hideBalls();
};

