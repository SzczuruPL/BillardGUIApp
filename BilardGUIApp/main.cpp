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
	//srand(time(0));
	QApplication a(argc, argv);
	//bilard.start();
	GUI* gui = new GUI();
	Game bilard(gui);
	bilard.draw();
	gui->show();
	//bilard.hit_tmp(40);
	//delay(2000);
	//gui->hideBalls();
	////bilard.hit(30);
	//delay(5000);
	//gui->refresh();
	return a.exec();
}