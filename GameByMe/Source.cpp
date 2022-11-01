#include "CommomFunction.h"
#include "Bird.h"
#include "Obstacle.h"
#include <ctime>
#include "Human1.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
	g_screen = SDL_SetVideoMode(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, BPP, SDL_SWSURFACE);
	return true;
}

std::string Count(long long& S)
{
	int len = floor(log10(S) + 1);
	std::string result;
	char temp;
	while (S)
	{
		temp = char(int(S / pow(10, len)) + '0');
		S %= (long long)pow(10, len);
		len--;
		result.push_back(temp);
	}
	return result;
}

//std::vector<SDL_Surface> HandleNumberImage(std::string &Num, std::string &Result)
//{
//	return NULL;
//}
int main(int arc, char* agrv[])
{
	bool is_quit = false;
	Init();
	if (Init() == false) return 0;
	Human Adam;
	Adam.status = LEFT;

	std::string StrArr[] = { "up1.png", "up2.png", "up3.png", "up4.png"
		,"down1.png", "down2.png", "down3.png", "down4.png",
	"left1.png", "left2.png", "left3.png", "left4.png",
	"right1.png", "right2.png", "right3.png", "right4.png" };

	// up : 0 - 3
	// down : 4 - 7
	// left : 8 - 11
	// right : 12 - 15
	
	//std::string Number[] = { "", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png" };

	Adam.SetImgHuman(StrArr);
	Adam.status = LEFT;
	g_background = CommomFunction::LoadImage("Greenbackground.jpg");
	int k = Adam.k;
	int speed = 0;
	Adam.SetLocation(g_SCREEN_WIDTH / 2 - 20, g_SCREEN_HEIGHT / 2 + 20);
	SDL_Rect temp_rect = Adam.GetRectHuman();

	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			Adam.HandleMove(g_event);
		}

		// Speed is speed of animation
		if (speed++ == 20) {
			k++;
			speed = 0;
		}

		//Handle if change Adam.k;
		if (abs(Adam.k - k) > 3 || k > Adam.k + 3) k = Adam.k;

		CommomFunction::ApplySurface(g_background, g_screen, 0, 0);	// Display the background

		//temp = Adam.GetRectHuman();	// location of the Human

		//CommomFunction::ApplySurface(Adam.A[k], g_screen, Adam., temp.y);	
		Adam.UpdateLocation();
		if (temp_rect.x != Adam.GetRectHuman().x || temp_rect.y != Adam.GetRectHuman().y)
		{
			Adam.S += 0.1;
		}
		std::cout << Adam.S << "\n";
		CommomFunction::ApplySurface(Adam.A[k], g_screen, Adam.GetRectHuman()); // Reload Main object's image on screen
		temp_rect = Adam.GetRectHuman();
		if (SDL_Flip(g_screen) == -1) return 0;	// Check
	}
	std::cout << "FINAL : " << Adam.S << "\n";

	CommomFunction::FreeSurface();
	SDL_Quit();

	return 0;
}

// g_SCREEN_WIDTH/2 + 50 >= wall1.rect_.x >= (g_SCREEN_WIDTH / 2) - 50
// bird1.rect_y + HEIGHT_BIRD <
// 330 - 370