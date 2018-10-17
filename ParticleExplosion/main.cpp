#include <iostream>
#include <SDL.h>
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
		// Check for messages/events

		if (screen.proccessEvents() == false)
			break;
	}

	screen.close();

	system("pause");
	return 0;
}