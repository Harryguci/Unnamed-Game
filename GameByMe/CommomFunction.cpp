#include "CommomFunction.h"

namespace CommomFunction
{
	SDL_Surface* LoadImage(std::string file_name)
	{
		SDL_Surface* image = NULL;
		SDL_Surface* optimize = NULL;

		image = IMG_Load(file_name.c_str());
		if (image != NULL) optimize = image;

		if (optimize != NULL) optimize = SDL_DisplayFormat(image);
		SDL_FreeSurface(image);
		if (optimize != NULL)
		{
			UINT32 color_key = SDL_MapRGB(optimize->format, 0, 0xFF, 0xFF);
			SDL_SetColorKey(optimize, SDL_SRCCOLORKEY, color_key);
		}
		return optimize;
	}

	void ApplySurface(SDL_Surface* image, SDL_Surface* screen,int x,int y)
	{
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;

		if (image != NULL || screen != NULL)
			SDL_BlitSurface(image, NULL, screen, &rect);
	}
	void ApplySurface(SDL_Surface* image, SDL_Surface* screen, SDL_Rect _rect)
	{
		if (image != NULL || screen != NULL)
			SDL_BlitSurface(image, NULL, screen, &_rect);
	}
	void FreeSurface()
	{
		SDL_FreeSurface(g_background);
		SDL_FreeSurface(g_screen);
	}

	bool check_rect(SDL_Rect rect_obj, SDL_Rect rect_obs)
	{
		if (rect_obj.x + 50 == rect_obs.x)
		{
			for (int i = rect_obs.y; i <= rect_obs.y; i++)
			{
				for (int j = rect_obj.y; j <= rect_obj.y + 36; j++)
				{
					if (i == j)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
}