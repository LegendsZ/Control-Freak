#include "Credits.h"

bool Credits::status = false;

Credits::Credits(SDL_Window* window, SDL_Renderer* renderer, int w, int h) : _window(window), _w(w), _h(h)
{
	background = new Rect(w, h, 0, 0, bkgdMenuV2_path);
	creator1 = new Text(renderer, comicFont_path, 45, "Akkshai B.", { 255, 50, 0 }, { 0xff,0xff,0xff });
	creator2 = new Text(renderer, comicFont_path, 45, "Roland T.", { 255, 50, 0 }, { 0xff,0xff,0xff });
	creator3 = new Text(renderer, comicFont_path, 45, "Jack J.", { 255, 50, 0 }, { 0xff,0xff,0xff });
	creator1->setPos(((w - 200) / 2), h / 15 * 4);
	creator2->setPos(((w - 200) / 2), h / 15 * 8);
	creator3->setPos(((w - 200) / 2), h / 15 * 12);
}

Credits::~Credits()
{
	background->~Rect();
	creator1->~Text();
	creator2->~Text();
	creator3->~Text();
}


void Credits::pollEvents(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	{
		ScreenStatus::CreditsStatus = false;
		ScreenStatus::StartingStatus = true;
		break;
	}
	}
}

void Credits::draw()
{
	background->draw();
	creator1->draw();
	creator2->draw();
	creator3->draw();
}

