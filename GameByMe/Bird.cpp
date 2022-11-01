#include "Bird.h"

Bird::Bird()
{
	x_val_ = 0;
	y_val_ = 0;
	rect_.x = g_SCREEN_WIDTH/2 - 50;
	rect_.y = 500;
	rect_.w = WIDTH_BIRD;
	rect_.y = HEIGHT_BIRD;
	obj_img = NULL;
}

Bird::~Bird()
{
	if (obj_img != NULL)
	SDL_FreeSurface(obj_img);
}

bool Bird::Set_Surface(std::string file_name)
{
	if (obj_img == NULL)
		obj_img = CommomFunction::LoadImage(file_name);
	else return false;

	if (obj_img == NULL) return false;
	return true;
}

SDL_Surface* Bird::Get_Surface()
{
	return obj_img;
}

SDL_Rect Bird::Set_Rect(const int& x, const int& y)
{
	rect_.x = x;
	rect_.y = y;

	return rect_;
}

void Bird::HandleActionInput(SDL_Event events)
{
	switch (events.type)
	{
	case SDL_KEYDOWN: switch (events.key.keysym.sym)
	{
	case SDLK_UP:y_val_ -= 8; break;
	case SDLK_DOWN: y_val_ += 8; break;
	default: break;
	}break;

	case SDL_KEYUP: y_val_ = 0; break;
	}
}

void Bird::HandleMove()
{
	rect_.y += y_val_;
	if (rect_.y < 0)
	{
		rect_.y = 0;
	}
	if (rect_.y >= 412) { rect_.y = 412; }
	else if (rect_.y + HEIGHT_BIRD > 590)
	{
		rect_.y = 590 - HEIGHT_BIRD;
	}
}

void Bird::HandleDead()
{
	while (1)
	{
	if (rect_.y >= 590) break;
	rect_.y += 10;
	}
}