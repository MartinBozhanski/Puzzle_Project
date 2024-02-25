//Game.cpp
#include "Game.h"
#include <iostream>
#include <vector>
#include "Piece.h"

static bool cash = false;
static bool castle = false;
static bool eiffelTower = false;
static bool flower = false;
static bool town = false;
static bool tree = false;
int msx, msy;
int squareSize = 0;
std::vector<SDL_Texture*> dividedPartsArr;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				// use the TextureManager to load textures
				TextureManager::Instance()->loadTexture("assets/town.bmp", "town", renderer);
				TextureManager::Instance()->loadTexture("assets/cash.bmp", "cash", renderer);
				TextureManager::Instance()->loadTexture("assets/eiffelTower.bmp", "eiffelTower", renderer);
				TextureManager::Instance()->loadTexture("assets/flower.bmp", "flower", renderer);
				TextureManager::Instance()->loadTexture("assets/castle.bmp", "castle", renderer);
				TextureManager::Instance()->loadTexture("assets/tree.bmp", "tree", renderer);

				SDL_Surface* surface1 = SDL_LoadBMP("assets/town.bmp");
				texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
				SDL_FreeSurface(surface1);

				SDL_Surface* surface2 = SDL_LoadBMP("assets/cash.bmp");
				texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
				SDL_FreeSurface(surface2);

				SDL_Surface* surface3 = SDL_LoadBMP("assets/eiffelTower.bmp");
				texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
				SDL_FreeSurface(surface3);

				SDL_Surface* surface4 = SDL_LoadBMP("assets/flower.bmp");
				texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
				SDL_FreeSurface(surface4);

				SDL_Surface* surface5 = SDL_LoadBMP("assets/castle.bmp");
				texture5 = SDL_CreateTextureFromSurface(renderer, surface4);
				SDL_FreeSurface(surface4);

				SDL_Surface* surface6 = SDL_LoadBMP("assets/tree.bmp");
				texture6 = SDL_CreateTextureFromSurface(renderer, surface4);
				SDL_FreeSurface(surface4);
			}
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	TextureManager::Instance()->drawTexture("town", 0, 0, 600, 300, renderer, SDL_FLIP_HORIZONTAL);
	TextureManager::Instance()->drawTexture("cash", 600, 0, 600, 300, renderer, SDL_FLIP_VERTICAL);
	TextureManager::Instance()->drawTexture("eiffelTower", 0, 300, 600, 300, renderer, SDL_FLIP_HORIZONTAL);
	TextureManager::Instance()->drawTexture("flower", 600, 300, 600, 300, renderer, SDL_FLIP_VERTICAL);
	TextureManager::Instance()->drawTexture("castle", 0, 600, 600, 300, renderer, SDL_FLIP_HORIZONTAL);
	TextureManager::Instance()->drawTexture("tree", 600, 600, 600, 300, renderer, SDL_FLIP_HORIZONTAL);

	if (town == true)
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
		SDL_RenderClear(renderer);
		
		TextureManager::Instance()->drawLeftBoard(renderer, squareSize);
		dividedPartsArr = TextureManager::Instance()->dividedParts(renderer, texture1, squareSize);
		TextureManager::Instance()->initializeDividedParts(dividedPartsArr, 10, squareSize, renderer);
	}
	else if (cash == true) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
		SDL_RenderClear(renderer);

		TextureManager::Instance()->drawLeftBoard(renderer, squareSize);
		dividedPartsArr = TextureManager::Instance()->dividedParts(renderer, texture2, squareSize);
		TextureManager::Instance()->initializeDividedParts(dividedPartsArr, 10, squareSize, renderer);
	}
	else if (eiffelTower == true) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
		SDL_RenderClear(renderer);

		TextureManager::Instance()->drawLeftBoard(renderer, squareSize);
		dividedPartsArr = TextureManager::Instance()->dividedParts(renderer, texture3, squareSize);
		TextureManager::Instance()->initializeDividedParts(dividedPartsArr, 10, squareSize, renderer);
	}
	else if (flower == true) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
		SDL_RenderClear(renderer);
		TextureManager::Instance()->drawLeftBoard(renderer, squareSize);
		dividedPartsArr = TextureManager::Instance()->dividedParts(renderer, texture4, squareSize);
		TextureManager::Instance()->initializeDividedParts(dividedPartsArr, 10, squareSize, renderer);
	}
	else if (castle == true) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
		SDL_RenderClear(renderer);
		TextureManager::Instance()->drawLeftBoard(renderer, squareSize);
		dividedPartsArr = TextureManager::Instance()->dividedParts(renderer, texture5, squareSize);
		TextureManager::Instance()->initializeDividedParts(dividedPartsArr, 10, squareSize, renderer);
	}
	else if (tree == true) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
		SDL_RenderClear(renderer);
		TextureManager::Instance()->drawLeftBoard(renderer, squareSize);
		dividedPartsArr = TextureManager::Instance()->dividedParts(renderer, texture6, squareSize);
		TextureManager::Instance()->initializeDividedParts(dividedPartsArr, 10, squareSize, renderer);
	}
	
	SDL_RenderPresent(renderer);
}

bool Game::isClickableTextureClicked(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp) {
	int tw, th;
	SDL_QueryTexture(t, 0, 0, &tw, &th);

	// 't' is rendered on the screen and lies within the coordinates below
	//(r->x)--------(r->x + tw)
	//     |        |
	//     |        |
	//(r->y)--------(r->y + th)

	// checks if the cursor position during the click time is inside the coordinates
	if ((xDown > r->x && xDown < (r->x + tw)) && (xUp > r->x && xUp < (r->x + tw)) &&
		(yDown > r->y && yDown < (r->y + th)) && (yUp > r->y && yUp < (r->y + th))) {
		// if all coordinates fall inside the rendered texture, the texture is clicked
		return true;
	}
	// the click was outside the texture
	return false;
}

int Game::randomNumberOfParts()
{
	int n = 0;

	while (n != 24 && n != 12)
	{
		n = 10 + (rand() % 30);
	}

	if (n == 24)
	{
		return squareSize = 100;
	}
	else if (n == 12) {
		return squareSize = 150;
	}
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false;
			break;
		case SDL_MOUSEBUTTONDOWN: {
			
			if (event.button.button == SDL_BUTTON_LEFT) {
				// When the left mouse button is pressed down, record the cursor position
				// to be used when checking if a texture was clicked;
				SDL_GetMouseState(&msx, &msy);
				mouseDownX = msx;
				mouseDownY = msy;
			}
		}; break;
		case SDL_MOUSEBUTTONUP: {
			
			if (event.button.button == SDL_BUTTON_LEFT) {
				// When the left mouse button is let go, check if the texture was pressed and log the result
				SDL_GetMouseState(&msx, &msy);
				if (isClickableTextureClicked(texture1, &clickableRect1, mouseDownX, mouseDownY, msx, msy)) {
					town = true;
				}
				else if (isClickableTextureClicked(texture2, &clickableRect2, mouseDownX, mouseDownY, msx, msy))
				{
					cash = true;
				}
				else if (isClickableTextureClicked(texture3, &clickableRect3, mouseDownX, mouseDownY, msx, msy))
				{
					eiffelTower = true;
				}
				else if (isClickableTextureClicked(texture4, &clickableRect4, mouseDownX, mouseDownY, msx, msy))
				{
					flower = true;
					
				}
				else if (isClickableTextureClicked(texture5, &clickableRect5, mouseDownX, mouseDownY, msx, msy))
				{
					castle = true;

				}
				else if (isClickableTextureClicked(texture6, &clickableRect6, mouseDownX, mouseDownY, msx, msy))
				{
					tree = true;

				}
				else
				{
					std::cout << "NOT CLICKED" << std::endl;
				}

			}
		}; break;
		default: break;
		}
	}
}

void Game::update() {
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Game::running;
}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 0;
}

Game::~Game() {

}
