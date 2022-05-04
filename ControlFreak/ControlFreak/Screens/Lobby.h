#pragma once

#include "..\\Graphics\Window.h"
#include "..\\Graphics\Text.h"
#include "..\\Graphics\Button.h"
#include "../fileLocations.h"
class Lobby : GameObject
{
public:
	Lobby(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~Lobby();

	void pollEvents(SDL_Event& event) override;
	void draw() override;

public:
	static bool status;

private:
	Text* readyTitle = nullptr;
	Text* map = nullptr;
	Text* player1 = nullptr;
	Text* player2 = nullptr;
	Text* player3 = nullptr;
	Text* player4 = nullptr;
	Rect* randombox = nullptr;
	/*	Button* kickp1 = nullptr;
		Button* kickp2 = nullptr;
		Button* kickp3 = nullptr;
		Button* kickp4 = nullptr;
		Button* mapToggleMenu = nullptr;
		Button* leave = nullptr;
		Button* readyButton = nullptr;*/

};