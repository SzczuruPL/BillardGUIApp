#include <cstdlib>
#include <iostream>
#include "Game.h"
#include "GUI.h"
#include "MyWidget.h"
#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

void colors()
{
	QColor color;
	color.setRgb(255, 255, 100);
	Qt::BrushStyle bs = Qt::SolidPattern;
	QBrush* QCol = new QBrush(color, Qt::SolidPattern);
	QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
	ellipse->setRect(300, 300, 100, 100);
	ellipse->setBrush(*QCol);
	//gui->addItem(ellipse);
}
int main(int argc, char* argv[])
{
	//srand(time(0));
	QApplication a(argc, argv);
	//bilard.start();
	GUI* gui = new GUI();
	Game bilard(gui);
	bilard.draw();
	gui->show();

	//MyWidget myWidget;
	//myWidget.show();
	bilard.hit_tmp(1,-30);
	//delay(2000);
	//gui->hideBalls();
	//bilard.hit(30);
	//delay(5000);
	//gui->refresh();
	return a.exec();
}