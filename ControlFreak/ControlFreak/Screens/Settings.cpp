#include "Settings.h"

SDL_Window* Settings::_window = nullptr;

void btnRes2560_Handler() {
	std::cout << "Join clicked\n";
	SDL_SetWindowSize(Settings::_window, 2560, 1440);
	ScreenStatus::ResChanged = true;
	/*Lobby::status = !Lobby::status;
	Lobby::type = NONHOST;*/
}

Settings::Settings(Window *window, SDL_Renderer* renderer, int w, int h)
{
	Settings::_window = window->m_Window;
	background = new Rect(window->m_Width, window->m_Height, 0, 0, 45, 179, 222, 255);
	resolution = new Text(renderer, comicFont_path, 45, "RESOLUTION", { 255, 255, 255 }, { 0xeb,0x1c,0x36 });
	resolution->setPos(100, 100);
	btnRes2560 = new ButtonV2(_window, 200, 200, h / 2, h / 2, bkgdbtn2560, btnRes2560_Handler);
}

Settings::~Settings()
{
	background->~Rect();
	resolution->~Text();
	btnRes2560->~ButtonV2();
}


void Settings::draw()
{
	background->draw();
	resolution->draw();
	btnRes2560->draw();
}

void Settings::pollEvents(SDL_Event event)
{
	btnRes2560->pollEvents(event);
	if (event.key.keysym.sym == SDLK_ESCAPE)
	{
		ScreenStatus::SettingsStatus = false;
		ScreenStatus::LobbyStatus = true;
	}
	if (ScreenStatus::ResChanged)
	{
		background->m_Width = 2560;
		background->m_Height = 1440;
		SDL_SetWindowPosition(_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		ScreenStatus::ResChanged = false;
	}
}