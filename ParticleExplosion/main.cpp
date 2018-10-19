#include <iostream>
#include <SDL.h>
#include <math.h>
#undef main

#include "Screen.h"

using namespace std;

int main()
{

	Screen screen;
	if (screen.init() == false)
		cout << "Error initialising SDL: " << SDL_GetError << endl;


	while (true)
	{
		// Update particles

		// Draw particles
		int elapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;


		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
				screen.setPixel(x, y, red, green, blue);

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (screen.proccessEvents() == false)
			break;
	}


	screen.close();

	system("pause");
	return 0;
}