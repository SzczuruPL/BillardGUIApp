#pragma once
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "GUI.h"

//class Color;
class GUI;
class GUIBall
{
private:
	GUI* gui;
	QGraphicsEllipseItem* circle;
	QGraphicsSimpleTextItem* textNumber;
	QGraphicsRectItem* stripe;
	int x;
	int y;
	int diameter;
	int number;
	const QBrush qColor[9];
public:
	GUIBall(int x, int y, int diameter, int nubmer,GUI *gui);
	QGraphicsSimpleTextItem* getTextNumber();
	void setTextNumber();
	void refresh();
	Color getColor();
};

