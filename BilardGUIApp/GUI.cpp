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

void GUI::drawTable()
{
	QGraphicsRectItem* rect = new QGraphicsRectItem();
	rect->setRect(0, 0, guiWidth, guiHeight);
	rect->setBrush(Qt::darkGreen);
	scene->addItem(rect);
}

void GUI::draw()
{
	drawTable();
	//print(guiHeight);
	for (int i = 0; i < balls->size(); i++) {
		int x = getGUICoordinateX(balls->at(i)->getX());
		int y = getGUICoordinateY(balls->at(i)->getY());
		GUIBall* ball = new GUIBall(x , y , guiDiameter, i);
		guiBalls.push_back(ellipse);
		scene->addItem(ellipse);
		guiBallNumbers.push_back(getTextNumber(i, x, y));
	}
}
void GUI::refresh()
{
	for (int i = 0; i < balls->size(); i++)
	{
		if (balls->at(i)->hasChanged())
		{
			int x = getGUICoordinateX(balls->at(i)->getX());
			int y = getGUICoordinateY(balls->at(i)->getY());
			guiBalls.at(i)->setRect(x - (guiDiameter / 2), y - (guiDiameter / 2), guiDiameter, guiDiameter);
			guiBalls.at(i)->setBrush(qColor[balls->at(i)->getColor()]);
			setTextNumber(guiBallNumbers.at(i), balls->at(i), x, y);
		}
	}
	//showBalls();
}

void GUI::delay(double i)
{
	QTime dieTime = QTime::currentTime().addMSecs(i*1000);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void GUI::setGuiWidth(double guiWidth)
{
	this->guiWidth = guiWidth * guiCoef;
}
void GUI::addItem(QGraphicsItem* item)
{
	scene->addItem(item);
}
void GUI::setGuiHeight(double guiHeight)
{
	//print(guiCoef);
	this->guiHeight = guiHeight * guiCoef;
}
void GUI::setGuiDiameter(double guiDiameter)
{
	//print(guiCoef * 10);
	this->guiDiameter = guiDiameter * guiCoef;
}
void GUI::setGuiCoef(double guiCoef)
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

int GUI::getGUICoordinateX(double x)
{
	return (guiWidth * x / board->getWidth());
}

int GUI::getGUICoordinateY(double y)
{
	return (guiHeight * y / board->getHeight());
}
QGraphicsSimpleTextItem* GUI::getTextNumber(int n, int x, int y)
{
	std::string s = std::to_string(n);
	QString qs = QString::fromStdString(s);
	QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
	QFont* font = new QFont();
	font->setPointSize(20);
	text->setFont(*font);
	text->setText(qs);
	if (n < 10)
		text->setPos(x - 7, y - 16);
	else
		text->setPos(x - 15, y - 16);
	scene->addItem(text);
	return text;
}
void GUI::setTextNumber(QGraphicsSimpleTextItem* text, Ball* ball, int x, int y)
{
	if (ball->getNumber() < 10)
		text->setPos(x - 7, y - 16);
	else
		text->setPos(x - 15, y - 16);
}
//void GUI::showBalls()
//{
//	for (int i = 0;i < guiBalls.size();i++)
//	{
//		if (balls->at(i)->hasChanged())
//		{
//			guiBalls.at(i)->setVisible(true);
//		}
//
//	}
//	for (int i = 0;i < guiBallNumbers.size();i++)
//	{
//		if (balls->at(i)->hasChanged())
//		{
//			guiBallNumbers.at(i)->setVisible(true);
//		}
//
//	}
//}
//void GUI::hideBalls()
//{
//	for (int i = 0;i < guiBalls.size();i++)
//	{
//		if (balls->at(i)->hasChanged())
//		{
//			guiBalls.at(i)->setVisible(false);
//		}
//			
//	}
//	for (int i = 0;i < guiBallNumbers.size();i++)
//	{
//		if (balls->at(i)->hasChanged())
//		{
//			guiBallNumbers.at(i)->setVisible(false);
//		}
//
//	}
//}


