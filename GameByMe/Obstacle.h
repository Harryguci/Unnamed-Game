#ifndef OBSTACLE_H_
#define OBSTACLE_H_
#include "CommomFunction.h"

#define WIDTH_OBSTACLE 100;
#define HEIGHT_OBSTACLE 344;

class Obstacle
{
public:
	SDL_Surface* obstacle_img;
	SDL_Rect rect_;
	int distance_;
	void Is_rect(SDL_Rect rect, bool &check_rect);

	Obstacle();
	~Obstacle();
	

};

#endif // !OBSTACLE_H_
