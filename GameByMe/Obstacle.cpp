#include "Obstacle.h"
#include "CommomFunction.h"


Obstacle::Obstacle()
{
	rect_.x = 0;
	rect_.y = 0;
	distance_ = 55;
}
Obstacle::~Obstacle()
{
	if (obstacle_img != NULL)
	{
		SDL_FreeSurface(obstacle_img);
	}
}

//void Obstacle::Is_rect(SDL_Rect is, bool &check_rect)				// obs.rect.x - WIDTH/2 < rect.x < obs.rect.x + WIDTH/2
//{
//	;
//}
