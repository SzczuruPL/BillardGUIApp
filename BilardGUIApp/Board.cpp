#include "Board.h"
#include <cstdlib>
#include <ctime>


Board::Board(int guiCoef, int width, int height, int cof, int diameter, int mass, int cue_mass,GUI* gui)
{
	/*print("test");*/
	//std::cout << guiWidth << ' ' << guiHeight << ' ' << guiCoef;
	this->gui = gui;
	this->width=width;
	this->height=height;
	this->cof=cof;
	this->r=diameter/2;
	this->mass = mass;
	this->cue_mass = cue_mass;
	balls = new std::vector <Ball*>();
}

void Board::draw()
{
	gui->draw();
}

void Board::setBalls()
{
	Ball* ball = new Ball(r, 0, cue_mass, this);
	ball->setInitialCueCoordinates(this);
	balls->push_back(ball);
	int k = 1;
	for (int i = 0;i <= 4;i++) //TODO: bile ustawiaja sie wedlug numerow, trzeba to rozwiazac
	{
		for (int j = 0; j <= i; j++)
		{
		Ball* ball = new Ball(r, k, mass, this); //TODO: ustawienie 8 (zamiana z 7) i rozne w rogach i losowo
		k++;
		ball->setInitialCoordinates(i,j,this);
		balls->push_back(ball);
		}
	}
	gui->setBalls(balls);
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
//		balls->push_back(ball);
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
	return 2240;//width;
}

int Board::getHeight()
{
	return 1120;//height;
}

int Board::getCof()
{
	return cof;
}

void Board::setBall(int n, int x, int y)
{

}

Ball* Board::getBall(int n)
{
	return nullptr;
}

