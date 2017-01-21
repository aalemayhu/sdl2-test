#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

// export SDL_VIDEODRIVER=directfb
int main(int argc, char *argv[])
{
	int posX = 0, posY = 0, width = 1334, height = 750;
	SDL_Renderer *renderer = NULL;
	SDL_Window *win = NULL;
	bool done = false;
	SDL_Event e;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("failed to initialize video sybsystem");
		exit(EXIT_FAILURE);
	}

	win = SDL_CreateWindow("sdl2test", posX, posY, width, height, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	while (!done) {
		SDL_SetRenderDrawColor(renderer, 0x33, 0x0, 0x66, 0xFF);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF,
				       SDL_ALPHA_OPAQUE);

		SDL_RenderDrawLine(renderer, posX, posY, width, height);
		SDL_RenderDrawLine(renderer, posX, height, width, posY);

		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&e))
			done = e.type == SDL_QUIT;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}
