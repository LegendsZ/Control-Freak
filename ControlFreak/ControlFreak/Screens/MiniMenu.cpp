#include "MiniMenu.h"

void btnSettings_Handler() {
	/*Lobby::status = !Lobby::status;
	Lobby::type = NONHOST;*/
}
void btnQuit_Handler() {
	ScreenStatus::StartingStatus = true;
	ScreenStatus::MiniMenuStatus = false;
	ScreenStatus::LobbyStatus = false;
}


bool MiniMenu::status = false;

MiniMenu::MiniMenu(SDL_Window* window, SDL_Renderer* renderer, int w, int h): _w(w), _h(h)
{
	background = new Rect(w, h, 0, 0, bkgdSettingsMenu_path);
	btnSettings = new ButtonV2(window, 200, 150, (w - 200) / 2, (h - 300) / 2, bkgdSettings_path, btnSettings_Handler);
	btnQuit = new ButtonV2(window, 200, 150, (w - 200) / 2, (h + 100) / 2, bkgdQuit_path, btnQuit_Handler);

}


MiniMenu::~MiniMenu()
{
	btnSettings->~ButtonV2();
	btnQuit->~ButtonV2();
	background->~Rect();
}

void MiniMenu::draw()
{
	background->draw();
	btnSettings->draw();
	btnQuit->draw();
	
}


void MiniMenu::pollEvents(SDL_Event event)
{
	btnQuit->pollEvents(event);
}

bool MiniMenu::getStatus()
{
	return status;
}