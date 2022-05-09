#pragma once

#include "MiniMenu.h"
#include "ScreenStatus.h"
class Credits
{
public:
	Credits(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~Credits();
	int _w;
	int _h;
	static bool status;
	Rect* background;
	Text* creator1;
	Text* creator2;
	Text* creator3;

	void draw();
	void pollEvents(SDL_Event event);
	SDL_Window* _window = nullptr;

};

