#include "GUI.h"

GUI::GUI()
{
	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
}
void GUI::print(std::string s)
{
	//std::cout << width << ' ' << height << ' ' << cof << ' ' << r << std::endl;
	QString qs = QString::fromStdString(s);
	QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
	text->setText(qs);
	//text->setPos(0, 0);
	scene->addItem(text);
}
void GUI::print(int i)
{
	//std::cout << width << ' ' << height << ' ' << cof << ' ' << r << std::endl;
	std::string s = std::to_string(i);
	QString qs = QString::fromStdString("ala ma kota");
	QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
	text->setText(qs);
	text->setPos(0, 0);
	scene->addItem(text);
}
void GUI::draw()
{
	QGraphicsRectItem* rect = new QGraphicsRectItem();
	rect->setRect(0, 0, guiWidth, guiHeight);
	rect->setBrush(Qt::darkGreen);
	scene->addItem(rect);
	for (int i = 0; i < balls->size(); i++) {
		int x = getGUICoordinateX(balls->at(i)->getX());
		int y = getGUICoordinateY(balls->at(i)->getY());
		QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
		ellipse->setRect(x , y, guiDiameter, guiDiameter);
		ellipse->setBrush(Qt::darkRed);
		guiBalls.push_back(ellipse);
		scene->addItem(ellipse);
	}
}
void GUI::refresh()
{
	for (int i = 0; i < balls->size(); i++)
	{
		int x = getGUICoordinateX(balls->at(i)->getX());
		int y = getGUICoordinateY(balls->at(i)->getY());
		guiBalls.at(i)->setRect(x, y, guiDiameter, guiDiameter);
		guiBalls.at(i)->setBrush(Qt::darkRed);
	}
}
void GUI::setGuiWidth(int guiWidth)
{
	this->guiWidth = guiWidth * guiCoef / 100;
}
void GUI::setGuiHeight(int guiHeight)
{
	this->guiHeight = guiHeight * guiCoef / 100;
}
void GUI::setGuiDiameter(int guiDiameter)
{
	this->guiDiameter = guiDiameter * guiCoef / 100;
}
void GUI::setGuiCoef(int guiCoef)
{
	this->guiCoef = guiCoef;
}
void GUI::setBalls(std::vector<Ball*>* balls)
{
	this->balls = balls;
}
void GUI::show()
{
	view->show();
}

int GUI::getGUICoordinateX(int x)
{
	return (guiWidth * x / board->getWidth());
}

int GUI::getGUICoordinateY(int y)
{
	return (guiHeight * y / board->getHeight());
}

void GUI::hideBalls()
{
	for (int i = 0;i < guiBalls.size();i++)
	{
		if (balls->at(i)->hasChanged())
		{
			guiBalls.at(i)->setVisible(false);
		}
			
	}
}


