#include "MiniMenu.h"

void btnSettings_Handler() {
	ScreenStatus::SettingsStatus = true;
	ScreenStatus::MiniMenuStatus = false;
	ScreenStatus::LobbyStatus = true;
}
void btnQuit_Handler() {
	ScreenStatus::StartingStatus = true;
	ScreenStatus::MiniMenuStatus = false;
	ScreenStatus::LobbyStatus = false;
}



MiniMenu::MiniMenu(Window* window, SDL_Renderer* renderer, int w, int h): _w(w), _h(h), _WINDOW(window)
{
	createElements();
}

void MiniMenu::createElements()
{
	background = new Rect(_WINDOW->m_Width, _WINDOW->m_Height, 0, 0, bkgdSettingsMenu_path);
	btnSettings = new ButtonV2(_WINDOW->m_Window, _WINDOW->m_Width / 4, _WINDOW->m_Height / 9 * 2, _WINDOW->m_Width / 16 * 6, _WINDOW->m_Height / 9 * 2, bkgdSettings_path, btnSettings_Handler);
	btnQuit = new ButtonV2(_WINDOW->m_Window, _WINDOW->m_Width / 4, _WINDOW->m_Height / 9 * 2, _WINDOW->m_Width / 16 * 6, _WINDOW->m_Height / 9 * 5, bkgdQuit_path, btnQuit_Handler);
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
	btnSettings->pollEvents(event);
	btnQuit->pollEvents(event);
}

void MiniMenu::changeRes()
{
	createElements();
}