#ifndef HUMAN_H_
#define HUMAN_H_

#include "Bird.h"
#include "CommomFunction.h"

enum Status
{
	UP, DOWN, LEFT, RIGHT
};

class Human : Bird {
public :
	void HandleMove(SDL_Event &events);
	SDL_Surface* A[16]{};
	void SetImgHuman(std::string* StrArr);
	void SetLocation(const int& x, const int& y);
	void DisPlay();
	void UpdateLocation();
	//int CountLongS(SDL_Event &events);
	SDL_Rect GetRectHuman();
	int status;
	int status_Temp;
	int k;
	int speed = 1;
	double S = 0;
};

#endif // !HUMAN_H_
