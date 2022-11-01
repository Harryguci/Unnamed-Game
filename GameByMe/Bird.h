#ifndef BIRD_H_
#define BIRD_H_
#include "CommomFunction.h"

#define WIDTH_BIRD 50
#define HEIGHT_BIRD 36

class Bird
{
public : 
	Bird();
	~Bird();
	bool Set_Surface(std::string file_name);
	SDL_Surface* Get_Surface();
	SDL_Rect Set_Rect(const int &x,const int &y);

	void HandleActionInput(SDL_Event events);
	void HandleMove();
	void HandleDead();
	void Demo();
//private : 
	int x_val_;
	int y_val_;
	SDL_Rect rect_;
	SDL_Surface* obj_img;
};

#endif // BIRD
