#include "Credits.h"

bool Credits::status = false;

Credits::Credits(Window* window, SDL_Renderer* renderer, int w, int h) : _WINDOW(window), _w(w), _h(h), _renderer(renderer)
{
	createElements();

}

void Credits::createElements()
{
	background = new Rect(_WINDOW->m_Width, _WINDOW->m_Height, 0, 0, bkgdMenuV2_path);
	creator1 = new Text(_renderer, comicFont_path, 45, "Akkshai B.", { 255, 50, 0 }, { 0xff,0xff,0xff });
	creator2 = new Text(_renderer, comicFont_path, 45, "Roland T.", { 255, 50, 0 }, { 0xff,0xff,0xff });
	creator3 = new Text(_renderer, comicFont_path, 45, "Jack J.", { 255, 50, 0 }, { 0xff,0xff,0xff });
	creator1->setPos(_WINDOW->m_Width / 8, _WINDOW->m_Height / 9);
	creator2->setPos(_WINDOW->m_Width / 8, _WINDOW->m_Height / 9 * 4);
	creator3->setPos(_WINDOW->m_Width / 8, _WINDOW->m_Height / 9 * 7);
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

void Credits::changeRes()
{
	createElements();
}