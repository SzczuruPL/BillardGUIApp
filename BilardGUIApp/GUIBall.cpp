#include "GUIBall.h"
#include <Color.Dlg>

GUIBall::GUIBall(int x, int y, int diameter, int number) :
	qColor{ Qt::white,Qt::yellow,Qt::darkBlue,Qt::darkRed,Qt::darkMagenta,Qt::darkYellow,Qt::darkGreen,Qt::darkGray,Qt::black }
{
	this->x = x;
	this->y = y;
	this->diameter = diameter;
	this->number = number;
	QGraphicsSimpleTextItem* textNumber = new QGraphicsSimpleTextItem();
	QGraphicsEllipseItem* circle = new QGraphicsEllipseItem();
	QGraphicsRectItem* stripe = new QGraphicsRectItem();
	circle->setRect(x - (diameter / 2), y - (diameter / 2), diameter, diameter);
	circle->setBrush(qColor[]);
}

Color GUIBall::getColor()
{
	return (number < 9) ? (Color)number : (Color)(number - 8);
}