/*
Basic Principle (Game Loop)

While the game is running:
	handle user input
	update all objects
	render changes to the display

*/


#include "SDL.h"
#include <iostream>

int cnt = 0;

bool running = false;
SDL_Window* window;
SDL_Renderer* renderer;

void handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;

	default:
		break;
	}
}

void updateObjects() {
	cnt++;
	std::cout << cnt << std::endl;
	static char white = true;
	if (cnt % 1000 == 0) {
		
		if (white){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); 
			white = false;
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			white = true;
		}
	}

}

void renderChanges() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

}

void clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	//Game Cleaned
}

int main(int argc, char* argv[]) {

	//Have a check for the 3 functions below (should return 0. else there is an error)
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		600, 400, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	running = true;

	while (running) { //game loop

		handleEvents();
		updateObjects();
		renderChanges();

	}

	clean();

	return 0;
}