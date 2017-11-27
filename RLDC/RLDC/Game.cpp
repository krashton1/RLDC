#include <SDL.h>

#include "Game.h"
#include "Input.h"

namespace
{
	//FPS limits
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game()
{
}

void Game::gameLoop()
{
	state = true;

	Input control;

	//gameloop
	while (state==true) {
		input(control);
		update();
		render();
	}
}

void Game::input(Input control)
{
	control.beginNewFrame();

	//Handle key down and up and exit button
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.repeat == 0) {
				control.keyDownEvent(event);
			}
		}
		else if (event.type == SDL_KEYUP) {
			control.keyUpEvent(event);
		}
		else if (event.type == SDL_QUIT) {
			state = false;
			return;
		}
	}

	//esc to quit
	if (control.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
		state = false;
		return;
	}

	//W,A,S,D to move
	if (control.isKeyHeld(SDL_SCANCODE_W) == true) {
		//UP
		
	}else if (control.isKeyHeld(SDL_SCANCODE_A) == true) {
		//LEFT
		
	}else if (control.isKeyHeld(SDL_SCANCODE_S) == true) {
		//DOWN

	}else if (control.isKeyHeld(SDL_SCANCODE_D) == true) {
		//RIGHT

	}
}

void Game::update()
{
}

void Game::render()
{
	//clear graphics
	graphics.clear();

	//add objects to graphics

	//render graphics to screen
	graphics.render();
}
