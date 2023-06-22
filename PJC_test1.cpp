#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include <cmath>
#include "Map.h"
#include "Game.h"

using std::cout;
using std::endl;


int main()
{

	Game game(4,8,4,0,2);

	while (game.running())
	{
		game.update();
		game.draw();
	}

	return 0;
}


