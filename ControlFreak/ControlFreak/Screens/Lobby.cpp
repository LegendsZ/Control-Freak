#include "Lobby.h"

bool Lobby::status = false;
Lobby::Lobby(SDL_Window* window, SDL_Renderer* renderer, int w, int h)
{
	readyTitle = new Text(renderer, comicFont_path, 40, "THIS IS THE LOBBY", {0,5,0});
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