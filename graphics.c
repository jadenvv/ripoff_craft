#include "graphics.h"
struct SDL_initialize init()
{
	SDL_Init(SDL_INIT_VIDEO);
	int display_count;
	const SDL_DisplayID * displays = SDL_GetDisplays(&display_count);
	if(!displays)
	{
		printf("no displays?");
	}
	const SDL_DisplayMode * mode = SDL_GetCurrentDisplayMode(displays[0]);
	if(!mode){
		printf("failed to get mode: %s \n", SDL_GetError());
	}
	struct SDL_initialize return_val = {NULL, NULL};
	return_val.main_window = SDL_CreateWindow("RipCraft", mode->w, mode->h, 0); 
	if(!return_val.main_window )
	{
		printf("the main window: %s\n", SDL_GetError());
	}
	return_val.main_renderer = SDL_CreateRenderer(return_val.main_window, NULL);
	if(!return_val.main_renderer)
	{
		printf("the main renderer: %s\n", SDL_GetError());
	}
	return return_val;


	
}
void clean(struct SDL_initialize* init)
{
	SDL_DestroyRenderer(init->main_renderer);
	SDL_DestroyWindow(init->main_window);
	init->main_renderer =NULL; 
	init->main_window = NULL;
	SDL_Quit();
} 
