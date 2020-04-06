#include <cstdlib>
#include <iostream>
#include "Game.h"
#include "GUI.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	//bilard.start();
	GUI* gui = new GUI();
	Game bilard(gui);
	bilard.draw();
	gui->show();
	return a.exec();
}