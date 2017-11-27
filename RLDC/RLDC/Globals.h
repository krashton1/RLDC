#pragma once

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

//some constants to use regularily
namespace globals
{
	const int SCREEN_WIDTH = 1366;
	const int SCREEN_HEIGHT = 768;

	const int LEVEL_WIDTH = 1366;
	const int LEVEL_HEIGHT = 768;

}

//the sides to a rectangle
namespace sides {
	enum Side {
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE
	};

	//if two rectangles are colliding, their opposite sides are touching
	inline Side getOppositeSide(Side side) {
		return
			side == TOP ? BOTTOM :
			side == BOTTOM ? TOP :
			side == LEFT ? RIGHT :
			side == RIGHT ? LEFT :
			NONE;
	}
}

//the 4 cardinal directions
enum Direction {
	LEFT, RIGHT, UP, DOWN
};

//simple structure of a 2 value vector. Commonly used as coordinates x and y
struct Vector2
{
	int x, y;

	//default constuctor
	Vector2() :
		x(0), y(0)
	{}

	//normal constructor
	Vector2(int x, int y) :
		x(x), y(y)
	{}

	//returns a zero vector
	Vector2 zero() //not currently utilized
	{
		return Vector2(0, 0);
	}
};

#endif //GLOBALS_H