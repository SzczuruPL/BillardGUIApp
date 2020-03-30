#include "Board.h"
#include <cstdlib>
#include <ctime>


Board::Board(int guiWidth, int guiHeight, int guiCoef, int width, int height, int cof, int diameter, int mass, int cue_mass)
{
	//std::cout << guiWidth << ' ' << guiHeight << ' ' << guiCoef;
	this->guiWidth = guiWidth* (guiCoef / 100.);
	this->guiHeight = guiHeight* (guiCoef / 100.);
	this->width=width;
	this->height=height;
	this->cof=cof;
	this->r=diameter/2;
	this->mass = mass;
	this->cue_mass = cue_mass;
}

void Board::draw(QGraphicsScene* scene)
{
	QGraphicsRectItem* rect = new QGraphicsRectItem();
	rect->setRect(0, 0, guiWidth, guiHeight);
	rect->setBrush(Qt::darkGreen);
	scene->addItem(rect);
	for (int i = 0; i < 10; i++) {
		QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
		ellipse->setRect(10 + 24 * i, 10 + 24 * i, 30, 30);
		ellipse->setBrush(Qt::darkRed);
		scene->addItem(ellipse);
	}
}

void Board::setBalls()
{
	Ball* ball = new Ball(r, 0, cue_mass, this);
	ball->setInitialCueCoordinates(this);
	int k = 1;
	for (int i = 0;i <= 4;i++) //TODO: bile ustawiaja sie wedlug numerow, trzeba to rozwiazac
	{
		for (int j = 0; j <= i; j++)
		{
		Ball* ball = new Ball(r, k, mass, this); //TODO: ustawienie 8 (zamiana z 7) i rozne w rogach i losowo
		k++;
		ball->setInitialCoordinates(i,j,this);
		balls.push_back(ball);
		}
	}
}

//void Board::setBalls()
//{
//	Ball* cueBall = new Ball(r, 0, cue_mass, this);
//	cueBall->setInitialCueCoordinates(this);
//	cueBall->setOnBoard(true);
//	balls.push_back(cueBall);
//	srand(time(0));
//	for (int k = 1; k <= 15;k++)
//	{
//		Ball* ball = new Ball(r, k, mass, this);
//		balls.push_back(ball);
//	}
//	balls[8]->setOnBoard(true);
//	for (int i = 0;i <= 4;i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			int index;
//			do
//			{
//				index = (rand() % 15 + 1);
//			} while (balls[index]->isOnBoard() == true);
//			balls[index]->setInitialCoordinates(i, j, this);
//		}
//	}
//
//}

int Board::getWidth()
{
	return width;
}

int Board::getHeight()
{
	return height;
}

void Board::print()
{
	std::cout << width << ' ' << height << ' ' << cof << ' ' << r << std::endl;
}
