#include <cstdlib>
#include <iostream>
#include "Game.h"

int main()
{
	Game bilard;
	bilard.readConf();
	bilard.start();
	return 0;
}