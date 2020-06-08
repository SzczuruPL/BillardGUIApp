#include "GUIBall.h"
#include <colorDlg.h>

GUIBall::GUIBall(int x, int y, int diameter, int number, GUI *gui) :
	qColor{ Qt::white,Qt::yellow,Qt::darkBlue,Qt::darkRed,Qt::darkMagenta,Qt::darkYellow,Qt::darkGreen,Qt::darkGray,Qt::black }
{
	this->gui = gui;
	this->x = x;
	this->y = y;
	this->diameter = diameter;
	this->number = number;
	circle = new QGraphicsEllipseItem();
	//gui->addItem(circle);
	stripe = new QGraphicsRectItem();
	//gui->addItem(stripe);
	textNumber = getTextNumber();	
	circle->setBrush(qColor[getColor()]);
	circle->setRect(x - (diameter / 2), y - (diameter / 2), diameter, diameter);

	
}
QGraphicsSimpleTextItem* GUIBall::getTextNumber()
{
	std::string s = std::to_string(number);
	QString qs = QString::fromStdString(s);
	QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
	QFont* font = new QFont();
	font->setPointSize(20);
	text->setFont(*font);
	text->setText(qs);
	if (number < 10)
		text->setPos(x - 7, y - 16);
	else
		text->setPos(x - 15, y - 16);
	//gui->addItem(text);
	return text;
}
void GUIBall::setTextNumber()
{
	if (number < 10)
		textNumber->setPos(x - 7, y - 16);
	else
		textNumber->setPos(x - 15, y - 16);
}
void GUIBall::refresh()
{
	circle->setRect(x - (diameter / 2), y - (diameter / 2), diameter, diameter);	
	//circle->setBrush(qColor[balls->at(i)->getColor()]);
	setTextNumber();
}
void GUIBall::addScene()
{
	gui->addItem(circle);
	gui->addItem(stripe);
	gui->addItem(textNumber);
}
int GUIBall::getX()
{
	return x;
}
void GUIBall::setX(int x)
{
	this->x = x;
}
void GUIBall::setY(int y)
{
	this->y = y;
}
Color GUIBall::getColor()
{
	return (number < 9) ? (Color)number : (Color)(number - 8);
}