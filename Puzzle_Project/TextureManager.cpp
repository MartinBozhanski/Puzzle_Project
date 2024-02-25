#include "TextureManager.h"
#include <iostream>

bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {

	SDL_Surface* tempSurface = IMG_Load(fileName); // fileName is the file path from the project directory to the image

	if (tempSurface == 0)
		return false;  // something went wrong

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tex != 0) { // if texture creation successful, save the texture in the map
		textureMap[id] = tex; // id is a unique identifier/name for each texture, the texture can be accessed later using this id
		return true;
	}

	return false; // something went wrong

}

void TextureManager::drawTexture(std::string id,
	int x, int y,
	int width, int height,
	SDL_Renderer* ren,
	SDL_RendererFlip flip) {

	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawOneFrameFromTexture(std::string id, // id of texture to draw
	int x, int y,	// window x,y to draw at;
	int width, int height,  // width and height of texture
	int currentRow, int currentFrame, //row starts from 1
	SDL_Renderer* ren,
	SDL_RendererFlip flip) { // flag to flip texture

	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);

}

std::vector<SDL_Texture*> TextureManager::dividedParts(SDL_Renderer* renderer, SDL_Texture* texture, int squareSize)
{
	int textureWidth, textureHeight;
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

	std::vector<SDL_Texture*> textureVector;

	for (int y = 0; y < textureHeight; y += squareSize + space) {
		for (int x = 0; x < textureWidth; x += squareSize + space) {
			SDL_Rect sourceRect = { x, y, squareSize, squareSize };
			SDL_Texture* slicedTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
				SDL_TEXTUREACCESS_TARGET, squareSize, squareSize);
			SDL_SetRenderTarget(renderer, slicedTexture);
			SDL_RenderCopy(renderer, texture, &sourceRect, NULL);
			SDL_SetRenderTarget(renderer, NULL);
			textureVector.push_back(slicedTexture);
		}
	}

	return textureVector;
}

void TextureManager::initializeDividedParts(std::vector<SDL_Texture*> dividedPartsArr, int space, int squareSize, SDL_Renderer* ren)
{
	int x = 650;
	int y = 0;
	for (SDL_Texture* slicedTexture : dividedPartsArr) {
		SDL_Rect piece = { x, y, squareSize, squareSize };
		SDL_RenderCopy(ren, slicedTexture, NULL, &piece);

		x += squareSize + space;
		if (x + squareSize + space > 1200) {
			x = 650;
			y += squareSize + space;
		}
		if (y + squareSize + space > 900) {
			break;  
		}
	}
}

void TextureManager::drawLeftBoard(SDL_Renderer* ren, int squareSize)
{
	if (squareSize == 100) {
		SDL_Rect outlineRect = { 0, 250, 600 , 400 };
		SDL_SetRenderDrawColor(ren, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawRect(ren, &outlineRect);

		SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(ren, 0, 350, 600, 350);
		SDL_RenderDrawLine(ren, 0, 450, 600, 450);
		SDL_RenderDrawLine(ren, 0, 550, 600, 550);
		SDL_RenderDrawLine(ren, 100, 250, 100, 650);
		SDL_RenderDrawLine(ren, 200, 250, 200, 650);
		SDL_RenderDrawLine(ren, 300, 250, 300, 650);
		SDL_RenderDrawLine(ren, 400, 250, 400, 650);
		SDL_RenderDrawLine(ren, 500, 250, 500, 650);
		
	}
	else if (squareSize == 150)
	{
		SDL_Rect outlineRect = { 0, 250, 600 , 450 };
		SDL_SetRenderDrawColor(ren, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawRect(ren, &outlineRect);

		SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(ren, 150, 250, 150, 700);
		SDL_RenderDrawLine(ren, 300, 250, 300, 700);
		SDL_RenderDrawLine(ren, 450, 250, 450, 700);
		
		SDL_RenderDrawLine(ren, 0, 400, 600, 400);
		SDL_RenderDrawLine(ren, 0, 550, 600, 550);
	}
}

	TextureManager* TextureManager::instance = 0;



