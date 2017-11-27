#pragma once

#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "Input.h"
#include "Graphics.h"

class Game 
{
public:
	Game();
	~Game();
private:

	//gameloop
	void gameLoop();

	//components
	void input(Input control);
	void update();
	void render();

	Input control;
	Graphics graphics;
	SDL_Event event;

	bool state;
};

#endif // !GAME_H
