#pragma once
#include "..\\Graphics\Window.h"
#include "..\\Graphics\Rect.h"
#include "..\\Graphics\Text.h"
#include "..\fileLocations.h"
#include "..\\Graphics\ButtonV2.h"
#include "ScreenStatus.h"

class Settings
{
public:
	Settings(Window* window, SDL_Renderer* renderer, int w, int h);
	~Settings();
	void draw();
	void pollEvents(SDL_Event event);
	Rect* background;
	Text* resolution;

	static SDL_Window* _window;
	ButtonV2* btnRes2560;

};