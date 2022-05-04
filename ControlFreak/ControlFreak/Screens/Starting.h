#pragma once
#include "..\\Graphics\Window.h"
#include "..\\Graphics\Button.h"
#include "..\\Graphics\Rect.h"
#include "..\\Graphics\Text.h"
#include "..\fileLocations.h"
#include "Lobby.h"
#include "Credits.h"

#include "..\\CustomButtons\ButtonV2.h"
//#include "..\\CustomButtons\Handlers.h"
class Starting
{
public:
	Starting(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~Starting();

	ButtonV2* btnCredits;
	ButtonV2* btnJoin;
	ButtonV2* btnHost;
	Rect* background;
	int _w;
	int _h;
	static bool status;

public:
	void draw();
	void createButtons();
	void pollEvents(SDL_Event event);
	bool getLobbyStatus();
	bool getCreditsStatus();
public:
	SDL_Window* _window = nullptr;

};