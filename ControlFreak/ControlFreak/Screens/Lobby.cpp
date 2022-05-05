
#include "Lobby.h"

bool Lobby::status = false;
int Lobby::type = 0;
Lobby::Lobby(SDL_Window* window, SDL_Renderer* renderer, int w, int h)
{
	readyTitle = new Text(renderer, comicFont_path, 40, "THIS IS THE LOBBY", {0,5,0});
	sampleHostText = new Text(renderer, comicFont_path, 40, "ONLY HOST CAN SEE THIS", { 0,5,0 });
	readyTitle->setPos((w - 400) / 2, h / 20);
	sampleHostText->setPos((w - 400) / 2, h / 10 );
}

Lobby::~Lobby()
{
	readyTitle->~Text();
	if (type == HOST)
	{
		sampleHostText->~Text();
	}
}

void Lobby::draw()
{

	readyTitle->draw();
	if (type == HOST)
	{
		sampleHostText->draw();
	}
}

void Lobby::pollEvents(SDL_Event& event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	{
		status = false;
	}

	}
}