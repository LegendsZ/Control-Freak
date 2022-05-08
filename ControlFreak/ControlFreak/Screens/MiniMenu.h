#pragma once
#include "..\\Graphics\Window.h"
#include "..\\Graphics\Rect.h"
#include "..\\Graphics\Text.h"
#include "..\fileLocations.h"
#include "..\\Graphics\ButtonV2.h"


class MiniMenu
{
public:
	MiniMenu(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~MiniMenu();

	Rect* m_rect;
	Text* options;
	Text* placeholder1;
	int _w;
	int _h;
	static bool status;
	void draw();
	void createButtons();
	void pollEvents(SDL_Event event);
	bool getStatus();
private:
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

};