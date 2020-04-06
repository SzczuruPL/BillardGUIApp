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
	QString qs = QString::fromStdString(s);
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
		QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
		ellipse->setRect(balls->at(i)->getX(), balls->at(i)->getY(), 30, 30);
		ellipse->setBrush(Qt::darkRed);
		scene->addItem(ellipse);
	}
}
void GUI::setGuiWidth(int guiWidth)
{
	this->guiWidth = guiWidth* (guiCoef / 100.);
}
void GUI::setGuiHeight(int guiHeight)
{
	this->guiHeight = guiHeight* (guiCoef / 100.);
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