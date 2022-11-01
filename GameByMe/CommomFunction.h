#ifndef COMMOM_FUNCTION_H_
#define COMMOM_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <Windows.h>
#include <string>
#undef main

const int g_SCREEN_WIDTH = 480;
const int g_SCREEN_HEIGHT = 800;
const int BPP = 32;

static SDL_Surface* g_background = NULL;
static SDL_Surface* g_screen = NULL;
static SDL_Event g_event;

namespace CommomFunction
{
	SDL_Surface* LoadImage(std::string file_name);
	void ApplySurface(SDL_Surface* image, SDL_Surface* screen, int x, int y);
	void ApplySurface(SDL_Surface* image, SDL_Surface* screen, SDL_Rect _rect);
	void FreeSurface();

	bool check_rect(SDL_Rect rect_obj, SDL_Rect rect_obs);
}

#endif // !COMMOM_FUNCTION_H_
