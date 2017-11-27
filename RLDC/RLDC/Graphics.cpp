
#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"


/* Graphics class
Holds all information dealing with graphics for the game
*/

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "RLDC");

}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	if (_spriteSheets.count(filePath) == 0) {
		_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return _spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle, int x, int y)
{
	updateCamera(x, y);
	SDL_RenderCopy(_renderer, texture, sourceRectangle, _camera);
}

void Graphics::render()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(_renderer);
}

void Graphics::updateCamera(int x, int y)
{
	int w = 16;
	int h = 16;

	//Center the camera over the dot
	_camera->x = (x + w / 2) - globals::SCREEN_WIDTH / 2;
	_camera->y = (y + h / 2) - globals::SCREEN_HEIGHT / 2;

	//Keep the camera in bounds
	if (_camera->x < 0)
	{
		_camera->x = 0;
	}
	if (_camera->y < 0)
	{
		_camera->y = 0;
	}
	if (_camera->x > globals::LEVEL_WIDTH - globals::SCREEN_WIDTH)
	{
		_camera->x = globals::LEVEL_WIDTH - globals::SCREEN_WIDTH;
	}
	if (_camera->y > globals::LEVEL_HEIGHT - globals::SCREEN_HEIGHT)
	{
		_camera->y = globals::LEVEL_HEIGHT - globals::SCREEN_HEIGHT;
	}

	//_camera->x = 0;
	//_camera->y = 0;
	_camera->w = globals::SCREEN_WIDTH;
	_camera->h = globals::SCREEN_HEIGHT;

}


SDL_Renderer* Graphics::getRenderer() const
{
	return _renderer;
}