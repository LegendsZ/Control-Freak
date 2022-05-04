#include "Credits.h"

bool Credits::status = false;

Credits::Credits(SDL_Window* window, SDL_Renderer* renderer, int w, int h) : _window(window), _w(w), _h(h)
{
	creator1 = new Text(renderer, comicFont_path, 45, "Akkshai B.", { 255, 50, 0 });
	creator2 = new Text(renderer, comicFont_path, 45, "Roland T.", { 255, 50, 0 });
	creator3 = new Text(renderer, comicFont_path, 45, "Jack J.", { 255, 50, 0 });
	creator1->setPos(((w - 200) / 2), h / 15 * 4);
	creator2->setPos(((w - 200) / 2), h / 15 * 8);
	creator3->setPos(((w - 200) / 2), h / 15 * 12);
}

Credits::~Credits()
{
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
		Starting::status = true;
		status = false;
	}

	}
}

void Credits::draw()
{
	creator1->draw();
	creator2->draw();
	creator3->draw();
}

