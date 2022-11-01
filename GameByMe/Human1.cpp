#include "Human1.h"

void Human::HandleMove(SDL_Event& events)
{
	switch (events.type)
	{
		case SDL_KEYDOWN:
		{
			switch (events.key.keysym.sym)
			{
			case SDLK_UP: status = UP; this->y_val_ -= this->speed; if (status_Temp != status) this->DisPlay(); break;
			case SDLK_DOWN: status = DOWN; this->y_val_ += this->speed; if (status_Temp != status) this->DisPlay(); break;
			case SDLK_LEFT: status = LEFT; this->x_val_ -= this->speed; if (status_Temp != status) this->DisPlay(); break;
			case SDLK_RIGHT:status = RIGHT; this->x_val_ += this->speed; if (status_Temp != status) this->DisPlay(); break;
			default: break;
			}
			break;
		}
		/*case SDL_OBJECTMOVE:
		{
			switch (events.key.keysym.sym)
			{
			case SDLK_UP: status = UP; this->y_val_ -= 2; if (status_Temp != status) this->DisPlay(); break;
			case SDLK_DOWN: status = DOWN; this->y_val_ += 2; if (status_Temp != status) this->DisPlay(); break;
			case SDLK_LEFT: status = LEFT; this->x_val_ -= 2; if (status_Temp != status) this->DisPlay(); break;
			case SDLK_RIGHT:status = RIGHT; this->x_val_ += 2; if (status_Temp != status) this->DisPlay(); break;
			default: break;
			}
			break;
		}*/
		case SDL_KEYUP:
		{
			switch (events.key.keysym.sym)
			{
			case SDLK_UP: this->y_val_ = 0; break;
			case SDLK_DOWN:this->y_val_ = 0; break;
			case SDLK_LEFT:this->x_val_ = 0; break;
			case SDLK_RIGHT:this->x_val_ = 0; break;
			default: break;
			}
			events.type = SDL_OBJECTMOVE;
			break;
		}
	}
}

void Human::SetImgHuman(std::string* StrArr)
{
	for (int i = 0; i < 16; i++)
	{
		this->A[i] = CommomFunction::LoadImage(StrArr[i]);
	}
}

void Human::DisPlay()
{
	//int k;
	status_Temp = status;
	switch (status)
	{
	case UP: k = 0; break;
	case DOWN: k = 4; break;
	case LEFT: k = 8; break;
	case RIGHT: k = 12; break;
	default:
		break;
	}
}

SDL_Rect Human::GetRectHuman()
{
	SDL_Rect Temp;
	Temp.x = rect_.x;
	Temp.y = rect_.y;
	return Temp;
}

void Human::UpdateLocation()
{
	this->rect_.x += this->x_val_;
	this->rect_.y += this->y_val_;
}

void Human::SetLocation(const int& x, const int& y)
{
	this->rect_.x = x;
	this->rect_.y = y;
}
