#include "Credits.h"

Credits::Credits(SDL_Window* window, SDL_Renderer* renderer, int w, int h) : _window(window), _w(w), _h(h)
{
	creator1 = new Text(renderer, "C:/Users/lalal/source/repos/Control-Freak/ControlFreak/ControlFreak/res/comic.ttf", 45, "Akkshai B.", { 0, 50, 0 });
	creator2 = new Text(renderer, "C:/Users/lalal/source/repos/Control-Freak/ControlFreak/ControlFreak/res/comic.ttf", 45, "Roland T.", { 0, 50, 0 });
	creator1->setPos(((w - 200) / 2), h / 15 * 5);
	creator2->setPos(((w - 200) / 2), h / 15 * 10);
}

Credits::~Credits()
{
	creator1->~Text();
	creator2->~Text();
}




void Credits::draw()
{
	creator1->draw();
	creator2->draw();
}

