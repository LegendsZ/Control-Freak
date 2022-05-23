#pragma once

//graphics stuff
#include "../Graphics/Listbox.h"
#include "MiniMenu.h"
#include "../fileLocations.h"
#include "../Graphics/ButtonV2.h"
#include "ScreenStatus.h"

//networking stuff
#include "../Client/ClientData.h"
//#include "../Client/client.h"
#include "../Server/server.h"

#define HOST 1
#define NONHOST 2
class Lobby : GameObject
{
public:
	Lobby(Window* WINDOW, SDL_Renderer* renderer, int w, int h);
	~Lobby();

	void pollEvents(SDL_Event& event) override;
	void draw() override;

public:
	Window* _WINDOW;
	Rect* background;
	static bool status;
	static int type;
	ButtonV2* btnSettings = nullptr;
	SDL_Window* _window;
	void changeRes();
private:
	SDL_Renderer* _renderer;
	void createElements();
	ButtonV2* btnUp = nullptr;
	ButtonV2* btnDown = nullptr;
	Listbox* listbox = nullptr;
	Text* readyTitle = nullptr;
	Text* sampleHostText = nullptr;
	Text* map = nullptr;

	Text* player1 = nullptr;
	Text* player2 = nullptr;
	Text* player3 = nullptr;
	Text* player4 = nullptr;
	Rect* randombox = nullptr;


	server* serverOBJ = nullptr;




	/*	Button* kickp1 = nullptr;
		Button* kickp2 = nullptr;
		Button* kickp3 = nullptr;
		Button* kickp4 = nullptr;
		Button* mapToggleMenu = nullptr;
		Button* leave = nullptr;
		Button* readyButton = nullptr;*/

};