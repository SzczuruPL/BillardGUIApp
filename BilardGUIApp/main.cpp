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
	srand(time(0));
	QApplication a(argc, argv);
	//bilard.start();
	GUI* gui = new GUI();
	Game bilard(gui);
	bilard.draw();
	gui->hideBalls();
	gui->show();
	return a.exec();
}