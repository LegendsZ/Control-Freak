#pragma once

#include "..\\Graphics\Window.h"
#include "..\\Graphics\Text.h"
#include "..\\Graphics\Button.h"
#include "../fileLocations.h"
#include "MiniMenu.h"
#include "../Graphics/Listbox.h"

#define HOST 1
#define NONHOST 2
class Lobby : GameObject
{
public:
	Lobby(SDL_Window* window, SDL_Renderer* renderer, int w, int h);
	~Lobby();

	void pollEvents(SDL_Event& event) override;
	void draw() override;

public:
	Rect* background;
	static bool status;
	static int type;
	ButtonV2* btnSettings = nullptr;
private:

	ButtonV2* btnUp = nullptr;
	ButtonV2* btnDown = nullptr;


	Listbox* listbox = nullptr;
	//make new component for listbox. the two buttons should be redirected to the listbox's up/down function.
	//^ make listboxitem component for listbox^



	Text* readyTitle = nullptr;
	Text* sampleHostText = nullptr;

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