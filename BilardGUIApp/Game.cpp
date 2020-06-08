#include "Game.h"
#include "Board.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>


Game::Game(GUI* gui)
{
	readConf();		
	board = new Board(config["width"], config["height"], config["cof"], config["diameter"], config["mass"], config["cueMass"], config["gravity"], gui);
	this->gui = gui;
	//gui->print(config["guiWidth"]);
	gui->setGuiCoef(config["guiCoef"]);
	//gui->print(config["guiCoef"]);
	gui->setGuiWidth(config["guiWidth"]);
	gui->setGuiHeight(config["guiWidth"] * config["height"] / config["width"]);
	gui->setGuiDiameter(config["diameter"] * config["guiWidth"]/ config["width"]);
	player1 = new Player(board);
	player2 = new Player(board);
	intervalTime = config["intervalTime"];
	board->setBalls();
}

void Game::draw()
{
	board->draw();
}

void Game::setScene(QGraphicsScene* scene)
{

}

void Game::start()
{

}
void Game::hit()
{

}
void Game::hit_tmp(double v0, double angle)
{
	double dt = 0.017;
	double t = 0;
	Ball* s = board->getBall(0);
	s->setAngle(angle * M_PI / 180);
	s->setV0(v0);
	while(s->isMoving())
	{
		s->setChanged(1);
		board->setBall(0, s->getX(t), s->getY(t));
		//gui->print(s->getX() + v0);
		gui->refresh();
		gui->delay(dt);
		//v0 = s->getVy(t);
		gui->print((int)v0);
		t = t + dt;
	}
}

void Game::readConf()
{
	std::ifstream fin;
	fin.open("C:\\Users\\Arkadiusz\\source\\repos\\BillardGUIApp\\BilardGUIApp\\config.cfg");
	if (!fin.good())
	{
		std::cout << "Unable to open config file!" << std::endl;
		return;
	}
	while (!fin.eof())
	{
		std::string confKey;
		std::string confCom; //no use - commentary
		fin >> confKey;
		fin >> config[confKey] >> confCom;
	}
}


