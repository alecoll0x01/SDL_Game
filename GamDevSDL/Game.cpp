#include "Game.hpp"



Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;

	if (fullscreen = true) {
		flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems init!" << std::endl;

		SDL_Window *window = SDL_CreateWindow(title, x, y, width, height, 0);

		if (window) {
			std::cout << "Tela iniciada!";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Render feito!";
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	
	}

}

void Game::update() {
	cnt++;
	std::cout << "Counter is: " << cnt;

}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Limpo!";
}