#pragma once
#include "Lobby.h"

void btnSettings_Handler() {
	MiniMenu::status = true;
}


bool Lobby::status = false;
int Lobby::type = 0;
Lobby::Lobby(SDL_Window* window, SDL_Renderer* renderer, int w, int h)
{
	background = new Rect(w, h, 0, 0, bkgdMenu_path);
	readyTitle = new Text(renderer, comicFont_path, 40, "THIS IS THE LOBBY", {0,5,0}, { 0xff,0xff,0xff });
	sampleHostText = new Text(renderer, comicFont_path, 40, "ONLY HOST CAN SEE THIS", { 0,5,0 }, { 0xff,0xff,0xff });
	readyTitle->setPos((w - 400) / 2, h / 20);
	sampleHostText->setPos((w - 400) / 2, h / 10 );
	btnSettings = new ButtonV2(window, 50, 50, 25, h - 50, "./res/gear.png", btnSettings_Handler);

	listbox = new Listbox(renderer, comicFont_path, 400, 150, (w/2) - (200), 150, "LISTBOX",255,255,255,255);
	std::vector<std::string> rowTest = { "1","192.168.0.31","READY" };
	std::vector<std::string> rowTestTwo = { "2","192.168.0.68","UNREADY" };
	listbox->addItem(rowTestTwo);
	listbox->addItem(rowTest);
	listbox->addItem(rowTestTwo);
	listbox->addItem(rowTestTwo);

}

Lobby::~Lobby()
{
	readyTitle->~Text();
	background->~Rect();
	btnSettings->~ButtonV2();
	if (type == HOST)
	{
		sampleHostText->~Text();
	}
}

void Lobby::draw()
{
	background->draw();
	readyTitle->draw();
	btnSettings->draw();
	listbox->draw();
	if (type == HOST)
	{
		sampleHostText->draw();
	}
}

void Lobby::pollEvents(SDL_Event& event)
{
	btnSettings->pollEvents(event);
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	{
		status = false;
		break;
	}
	case SDLK_p:
	{

	}

	}
}