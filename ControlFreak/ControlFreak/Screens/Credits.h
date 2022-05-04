#pragma once

#include "..\\Graphics\Window.h"
#include "..\\Graphics\Button.h"
#include "..\\Graphics\Rect.h"
#include "..\\Graphics\Text.h"
#include "..\fileLocations.h"
#include "..\\CustomButtons\ReadyButton.h"
#include "Lobby.h"

class Credits
{
public:
	Credits(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~Credits();
	int _w;
	int _h;
	static bool status;
	Text* creator1;
	Text* creator2;

	void draw();
	void createButtons();
	void pollEvents(SDL_Event event);
	SDL_Window* _window = nullptr;

};

