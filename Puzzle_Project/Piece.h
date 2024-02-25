#pragma once
#include "TextureManager.h"
#include "Game.h"

class Piece {
public:
	Piece(int x, int y, int width, int length, int position);
	

private:
	int width;
	int length;
	int x;
	int y;
	int position;
	const int space = 10;
};
