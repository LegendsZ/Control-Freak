#include "Starting.h"

Starting::Starting(SDL_Window* window, SDL_Renderer* renderer, int w, int h) : _window(window), _w(w), _h(h)
{
	//gameTitle = new Text(renderer, comicFont_path, 45, "CONTROL FREAK", { 0, 50, 0 });
	//gameTitle->setPos(((w - 350) / 2), h / 12);
	background = new Rect(w, h, 0, 0, bkgdMenu_path);
	createButtons();
}

Starting::~Starting()
{
	//gameTitle->~Text();
	background->~Rect();
	playButton->~ReadyButton();
	credits->~CreditsButton();
}


void Starting::draw()
{
	background->draw();
	//gameTitle->draw();
	playButton->draw();
	credits->draw();
}

void Starting::createButtons()
{
	int btnWidth = 300;
	int btnHeight = 100;
	int spaceInBetween = (_w - (btnWidth*2)) / 3;
	//playButton = new ReadyButton(_window, 70, 70, (_w - 35) / 2, _h / 4, 50, 0, 50, 1);
	//credits = new CreditsButton(_window, 70, 70, (_w - 35) / 2, _h / 4 * 3, 50, 0, 50, 1);
	playButton = new ReadyButton(_window, btnWidth, btnHeight, spaceInBetween, _h-(btnHeight+25), bkgdbtnPlay_path);
	credits = new CreditsButton(_window, btnWidth, btnHeight, spaceInBetween *2 + btnWidth, _h -(btnHeight+25), bkgdbtnCredit_path);
	 
	//playButton = new Button(70, 70, (_w - 35) / 2, _h / 4, 50, 0, 50, 1, play);

/*	auto credit = [](SDL_Event& event)
	{
		std::cout << "Made by B. Akkshai, T. Roland";
	};
	credits = new Button(70, 70, (_w - 35) / 2, _h / 10 * 8, 50, 0, 50, 1, credit);*/
}


void Starting::pollEvents(SDL_Event event)
{
	//gameTitle->pollEvents(event);
	playButton->pollEvents(event);
	credits->pollEvents(event);
	status = !playButton->_status && !credits->_status;
}


bool Starting::getLobbyStatus()
{
	return playButton->_status;
}

bool Starting::getCreditsStatus()
{
	return credits->_status;
}