#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

using namespace std;



class Screen
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

	Screen();
	bool init();
	bool proccessEvents();
	void close();


};
