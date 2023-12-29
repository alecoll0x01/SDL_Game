#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include "SDL.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };
private:
	bool isRunning;
	int cnt;
	SDL_Window *window;
	SDL_Renderer* renderer;
};

#endif