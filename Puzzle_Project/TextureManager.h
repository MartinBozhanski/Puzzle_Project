// TextureManager.h
#pragma once
#include "Game.h"
#include <string>
#include <map>
#include <vector>

class TextureManager {
public:
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);
	void drawTexture(std::string id,
		int x, int y,
		int width, int height,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawOneFrameFromTexture(std::string id,
		int x, int y,
		int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	//void divideImageIntoSquares(SDL_Texture* texture, int squareSize, SDL_Renderer* ren, int width, int height);

	std::vector<SDL_Texture*> dividedParts(SDL_Renderer* renderer, SDL_Texture* texture, int squareSize);
	void initializeDividedParts(std::vector<SDL_Texture*> dividedPartsArr, int space, int squareSize, SDL_Renderer* renderer);

	void drawLeftBoard(SDL_Renderer* renderer, int squareSize);

	static TextureManager* Instance() { // TextureManager is a singleton, only one instance allowed
		if (instance == 0) {
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}

private:
	std::map<std::string, SDL_Texture*> textureMap;
	TextureManager() {} // TextureManager is a singleton, the constructor is a private field
	static TextureManager* instance;
	const int space = 10;
};
