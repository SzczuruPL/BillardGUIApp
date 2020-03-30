#include <cstdlib>
#include <iostream>
#include "Game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>


int main(int argc, char* argv[])
{
	Game bilard;
	QApplication a(argc, argv);
	//bilard.start();
	QGraphicsScene* scene = new QGraphicsScene();
	QGraphicsView* view = new QGraphicsView(scene);
	bilard.draw(scene);
	view->show();
	return a.exec();
}