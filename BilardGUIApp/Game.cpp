#include "Game.h"
#include "Board.h"
#include <fstream>


Game::Game()
{
	readConf();		
	board = new Board(config["guiWidth"], config["guiHeight"], config["guiCoef"], config["width"], config["height"], config["cof"], config["diameter"], config["mass"], config["cueMass"]);
	player1 = new Player(board);
	player2 = new Player(board);
	intervalTime = config["intervalTime"];
	board->setBalls();
}

void Game::draw(QGraphicsScene* scene)
{
	board->draw(scene);
}

void Game::start()
{

}

void Game::readConf()
{
	std::ifstream fin;
	fin.open("C:\\Users\\Arkadiusz\\Source\\Repos\\Bilard\\Bilard\\config.cfg");
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

