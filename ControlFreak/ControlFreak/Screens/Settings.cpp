#include "Settings.h"

Settings::Settings(SDL_Window* window, SDL_Renderer* renderer, int w, int h)
{
	background = new Rect(w, h, 0, 0, 45, 179, 222, 255);
	resolution = new Text(renderer, comicFont_path, 45, "RESOLUTION", { 255, 255, 255 }, { 0xeb,0x1c,0x36 });
	resolution->setPos(100, 100);
}

Settings::~Settings()
{
	background->~Rect();
	resolution->~Text();
}


void Settings::draw()
{
	background->draw();
	resolution->draw();
}

void Settings::pollEvents(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
	{
		ScreenStatus::SettingsStatus = false;
		ScreenStatus::LobbyStatus = true;
	}
}