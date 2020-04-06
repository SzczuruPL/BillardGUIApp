#pragma once
#include "Ball.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <vector>
class GUI
{
private:
	QGraphicsScene* scene;
	QGraphicsView* view;
	int guiWidth;
	int guiHeight;
	int guiCoef;
	std::vector <Ball*> *balls;
public:
	GUI();
	void print(std::string s);
	void print(int i);
	void show();
	void draw();
	void setGuiWidth(int guiWidth);
	void setGuiHeight(int guiHeight);
	void setGuiCoef(int guiCoef);
	void setBalls(std::vector <Ball*> *balls);
};

