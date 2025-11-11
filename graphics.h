#ifndef GRAPHICS
#define GRAPHICS
#include <SDL3/SDL.h>
#include <stdio.h>
struct SDL_initialize{
	SDL_Renderer * main_renderer;
	SDL_Window * main_window; 
};
struct SDL_initialize init();
void clean(struct SDL_initialize* init);
#endif
