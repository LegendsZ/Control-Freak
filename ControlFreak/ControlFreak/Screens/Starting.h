#pragma once
#include "Lobby.h"
#include "Credits.h"
#include "..//Graphics/Textbox.h";
#include "ScreenStatus.h"

class Starting
{
public:
	Starting(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~Starting();

	ButtonV2* btnCredits;

	ButtonV2* btnJoin;
	static Textbox* txtJoin;
	static bool txtJoinVisible;
	ButtonV2* btnHost;
	static Textbox* txtHost;
	static bool txtHostVisible;

	Rect* background;
	int _w;
	int _h;
	static bool status;

public:
	void draw();
	void createButtons(SDL_Renderer* renderer);
	void pollEvents(SDL_Event event);
	bool getLobbyStatus();
	bool getCreditsStatus();
public:
	SDL_Window* _window = nullptr;

};