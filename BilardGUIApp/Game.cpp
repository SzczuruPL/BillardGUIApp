#include "Game.h"
#include "Board.h"
#include <fstream>


Game::Game(GUI* gui)
{
	readConf();		
	board = new Board(config["guiCoef"], config["width"], config["height"], config["cof"], config["diameter"], config["mass"], config["cueMass"], config["gravity"], gui);
	this->gui = gui;
	gui->print(config["guiWidth"]);
	gui->setGuiCoef(config["guiCoef"]);
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

void Game::hit(double v0)
{
	Ball* s = board->getBall(0);
	while(v0>0)
	{
		s->setChanged(1);
		board->setBall(0, s->getX() + v0, s->getY());
		gui->refresh();
		v0 = v0 - 1;
		gui->delay(17);
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


