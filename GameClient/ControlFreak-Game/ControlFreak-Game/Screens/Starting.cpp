#include "Starting.h"

Starting::Starting(SDL_Window* window, SDL_Renderer *renderer, int w ,int h): _window(window), _w(w), _h(h)
{
	gameTitle = new Text(renderer, "C:\\Users\\lalal\\source\\repos\\Control-Freak\\GameClient\\ControlFreak-Game\\ControlFreak-Game\\res\\comic.ttf", 45, "CONTROL FREAK", { 0, 50, 0 });
	gameTitle->setPos(((w - 350) / 2), h / 12);
	createButtons();
}

Starting::~Starting()
{
	gameTitle->~Text();
}


void Starting::draw()
{
	gameTitle->draw();
	playButton->draw();
	credits->draw();
}

void Starting::createButtons()
{
	playButton = new ReadyButton(_window, 70, 70, (_w - 35) / 2, _h / 4, 50, 0, 50, 1);
	credits = new CreditsButton(_window, 70, 70, (_w - 35) / 2, _h / 4 * 3, 50, 0, 50, 1);
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