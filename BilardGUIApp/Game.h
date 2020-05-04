#pragma once
#include <iostream>
#include <map>
#include "Player.h"
#include "Board.h"
#include "GUI.h"
class GUI;
class Game
{
private:
	Board* board;
	Player *player1;
	Player *player2;
	int intervalTime; //ms
	std::map < std::string, double> config;
	GUI* gui;
public:
	Game(GUI* gui);
	void draw();
	void setScene(QGraphicsScene* scene);
	void start();
	void hit();
	void hit_tmp(double v0);
	void readConf();

};

