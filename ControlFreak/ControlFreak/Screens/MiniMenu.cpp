#include "MiniMenu.h"

bool MiniMenu::status = false;

MiniMenu::MiniMenu(SDL_Window* window, SDL_Renderer* renderer, int w, int h): _w(w), _h(h)
{
	options = new Text(renderer, comicFont_path, 20, "Options", { 100, 50, 0 }, { 0xff,0xff,0xff });
	options->setPos(25, h - 75);
	placeholder1 = new Text(renderer, comicFont_path, 20, "Placeholder", { 100, 50, 0 }, { 0xff,0xff,0xff });
	placeholder1->setPos(25, h - 100);
}


MiniMenu::~MiniMenu()
{
	options->~Text();
	placeholder1->~Text();
}

void MiniMenu::draw()
{
	options->draw();
	placeholder1->draw();
}


void MiniMenu::pollEvents(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_o)
	{
		status = false;
	}
}

bool MiniMenu::getStatus()
{
	return status;
}