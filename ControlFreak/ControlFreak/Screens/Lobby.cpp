#pragma once
#include "Lobby.h"



bool Lobby::status = false;
int Lobby::type = 0;
Lobby::Lobby(Window* window, SDL_Renderer* renderer, int w, int h): _WINDOW(window), _renderer(renderer)
{
	createElements();
}

void Lobby::createElements()
{
	background = new Rect(_WINDOW->m_Width, _WINDOW->m_Height, 0, 0, bkgdMenuV2_path);
	readyTitle = new Text(_renderer, comicFont_path, 40, "THIS IS THE LOBBY", { 0,5,0 }, { 0xff,0xff,0xff });
	sampleHostText = new Text(_renderer, comicFont_path, 40, "ONLY HOST CAN SEE THIS", { 0,5,0 }, { 0xff,0xff,0xff });
	readyTitle->setPos((_WINDOW->m_Width - 400) / 2, _WINDOW->m_Height / 20);
	sampleHostText->setPos((_WINDOW->m_Width - 400) / 2, _WINDOW->m_Height / 10);
	//btnSettings = new ButtonV2(window, 50, 50, 25, h - 50, "./res/gear.png", btnSettings_Handler);

	listbox = new Listbox(_renderer, comicFont_path, 400, 150, (_WINDOW->m_Width / 2) - (200), 150, "LISTBOX", 255, 255, 255, 255);
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
	//btnSettings->~ButtonV2();
	if (type == HOST)
	{
		sampleHostText->~Text();
	}
}

void Lobby::draw()
{
	background->draw();
	readyTitle->draw();
	//btnSettings->draw();
	listbox->draw();
	if (type == HOST)
	{
		sampleHostText->draw();
	}
}

void Lobby::pollEvents(SDL_Event& event)
{
	//btnSettings->pollEvents(event);

	if (event.key.keysym.sym == SDLK_ESCAPE && event.type == SDL_KEYDOWN)
	{
		ScreenStatus::MiniMenuStatus = !ScreenStatus::MiniMenuStatus;
	}
	
}

void Lobby::changeRes()
{
	createElements();
}