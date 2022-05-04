#include "Lobby.h"

Lobby::Lobby(SDL_Window* window, SDL_Renderer* renderer, int w, int h)
{
	readyTitle = new Text(renderer, "C:/Users/lalal/source/repos/Control-Freak/ControlFreak/ControlFreak/res/comic.ttf", 40, "THIS IS THE LOBBY", {0,5,0});
	std::cout << "./" + comicFont_path;
	readyTitle->setPos((w - 400) / 2, h / 20);
}

Lobby::~Lobby()
{

	readyTitle->~Text();
}

void Lobby::draw()
{

	readyTitle->draw();
}

void Lobby::pollEvents(SDL_Event& event)
{
	readyTitle->pollEvents(event);
}