#pragma once
#include "..\\Graphics\Window.h"
#include "..\\Graphics\Button.h"
#include "..\\Graphics\Rect.h"
#include "..\\Graphics\Text.h"
#include "..\fileLocations.h"
#include "..\\CustomButtons\ReadyButton.h"
#include "Lobby.h"
#include "..\\CustomButtons\CreditsButton.h"
class Starting
{
public:
	Starting(SDL_Window *window, SDL_Renderer *renderer, int w, int h);
	~Starting();

	ReadyButton* playButton;
	CreditsButton* credits;
	Text* gameTitle;
	int _w;
	int _h;
	bool status = true;


public:
	void draw();
	void createButtons();
	void pollEvents(SDL_Event event);
	bool getLobbyStatus();
	bool getCreditsStatus();
public:
	SDL_Window* _window = nullptr;
	
};