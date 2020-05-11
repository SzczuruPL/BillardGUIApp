#pragma once
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Color;
class GUIBall
{
private:
	QGraphicsEllipseItem* circle;
	QGraphicsSimpleTextItem* textNumber;
	QGraphicsRectItem* stripe;
	int x;
	int y;
	int diameter;
	int number;
	const QBrush qColor[9];
public:
	GUIBall(int x, int y, int diameter, int nubmer);
};

