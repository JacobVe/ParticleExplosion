#include <iostream>
#include <SDL.h>
#include <math.h>
#undef main

#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"


using namespace std;

int main()
{
	srand(time(NULL));

	Screen screen;
	if (screen.init() == false)
		cout << "Error initialising SDL: " << SDL_GetError << endl;

	Swarm swarm;

	while (true)
	{
		// Update particles
		


		// Draw particles
		int elapsed = SDL_GetTicks();

		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;


		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, blue, green);
		}

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