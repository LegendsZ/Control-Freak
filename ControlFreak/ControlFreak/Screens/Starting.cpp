#include "Starting.h"

bool Starting::status = true;


void btnJoin_Handler() {
	std::cout << "Join clicked\n";
}
void btnHost_Handler() {
	std::cout << "Host clicked\n";
}
void btnCredits_Handler() {
	std::cout << "Credits clicked\n";
	Credits::status = !Credits::status;
}


Starting::Starting(SDL_Window* window, SDL_Renderer* renderer, int w, int h) : _window(window), _w(w), _h(h)
{
	background = new Rect(w, h, 0, 0, bkgdMenu_path);
	createButtons();
}

Starting::~Starting()
{
	background->~Rect();
	btnCredits->~ButtonV2();
	btnHost->~ButtonV2();
	btnJoin->~ButtonV2();
}


void Starting::draw()
{
	background->draw();
	btnJoin->draw();
	btnHost->draw();
	btnCredits->draw();
}

void Starting::createButtons()
{
	int btnWidth = 200;
	int btnHeight = 100;
	int numBtns = 3;
	int spaceInBetween = (_w - (numBtns * btnWidth)) / (numBtns + 1); //quick maths
	int spaceBelow = 25;

	btnHost = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween, _h - (btnHeight + spaceBelow), bkgdbtnHost_path, btnJoin_Handler);
	btnJoin = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 2 + btnWidth, _h - (btnHeight + spaceBelow), bkgdbtnHost_path,btnHost_Handler);
	btnCredits = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 3 + 2*btnWidth, _h - (btnHeight + spaceBelow), bkgdbtnCredit_path, btnCredits_Handler);
}


void Starting::pollEvents(SDL_Event event)
{
	btnCredits->pollEvents(event);
	btnJoin->pollEvents(event);
	btnHost->pollEvents(event);
	//status = !btnPlay->_status && !btnCredits->_status;
}


bool Starting::getLobbyStatus()
{
	return Lobby::status;
}

bool Starting::getCreditsStatus()
{
	return Credits::status;
}