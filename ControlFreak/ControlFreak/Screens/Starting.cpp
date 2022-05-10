#include "Starting.h"

bool Starting::status = true;
bool Starting::txtJoinVisible=false;
bool Starting::txtHostVisible=false;
Textbox* Starting::txtJoin = nullptr;
Textbox* Starting::txtHost = nullptr;
void btnJoin_Handler() {
	std::cout << "Join clicked\n";
	Starting::txtJoinVisible = true;
	/*Lobby::status = !Lobby::status;
	Lobby::type = NONHOST;*/
}
void btnHost_Handler() {
	std::cout << "Host clicked\n";
	Starting::txtHostVisible = true;
	/*Lobby::status = !Lobby::status;
	Lobby::type = HOST;*/
}
void btnCredits_Handler() {
	std::cout << "Credits clicked\n";
	ScreenStatus::CreditsStatus = !ScreenStatus::CreditsStatus;
}

void txtHost_Handler() {
	server::serverOBJ = new server(atoi(Starting::txtHost->m_Text->text.c_str()));
	if (!server::serverOBJ->autoStart()) {
		return; //error handle this
	}
	ScreenStatus::LobbyStatus = true;
	Lobby::type = HOST;
}
void txtJoin_Handler() {
	if (Connector::connectIP == "") {
		Connector::connectIP = Starting::txtHost->m_Text->text;
		Starting::txtHost->m_Text->setText("PORT=");
	}
	else {
		Connector::port = atoi(Starting::txtHost->m_Text->text.c_str());
		Starting::txtHost->m_Text->setText("CONNECTING...");

		Connector::clientOBJ = new client(Connector::connectIP, Connector::port);
		if (!Connector::clientOBJ->autoStart()) {
			return; //error handle?
		}
		IPv4 myIPV4TEMP;
		getMyIP(myIPV4TEMP);
		Connector::myIPV4 = std::to_string(myIPV4TEMP.b1) + "." + std::to_string(myIPV4TEMP.b2) + "." + std::to_string(myIPV4TEMP.b3) + "." + std::to_string(myIPV4TEMP.b4);
		//Connector::clientOBJ->sendData(Connector::myIPV4 + "ISREADY");
		Connector::clientOBJ->sendData(Connector::myIPV4 + "V" + version);
	}
}

Starting::Starting(SDL_Window* window, SDL_Renderer* renderer, int w, int h) : _window(window), _w(w), _h(h)
{
	background = new Rect(w, h, 0, 0, bkgdMenuV2_path);
	createButtons(renderer);
}

Starting::~Starting()
{
	background->~Rect();
	btnCredits->~ButtonV2();
	btnHost->~ButtonV2();
	btnJoin->~ButtonV2();
	if (txtHostVisible) {
		txtHost->~Textbox();
	}
	if (txtJoinVisible) {
		txtJoin->~Textbox();
	}
}


void Starting::draw()
{
	background->draw();
	btnCredits->draw();
	if (txtJoinVisible) {
		txtJoin->draw();
	}
	else {
		btnJoin->draw();
	}

	if (txtHostVisible) {
		txtHost->draw();
	}
	else {
		btnHost->draw();
	}
}

void Starting::createButtons(SDL_Renderer* renderer)
{
	int btnWidth = 200;
	int btnHeight = 100;
	int numBtns = 3;
	int spaceInBetween = (_w - (numBtns * btnWidth)) / (numBtns + 1); //quick maths
	int spaceBelow = 25;

	btnHost = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween, _h - (btnHeight + spaceBelow), bkgdbtnHost_path, btnHost_Handler);
	btnJoin = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 2 + btnWidth, _h - (btnHeight + spaceBelow), bkgdbtnJoin_path,btnJoin_Handler);
	btnCredits = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 3 + 2*btnWidth, _h - (btnHeight + spaceBelow), bkgdbtnCredit_path, btnCredits_Handler);

	txtHost = new Textbox(btnWidth, btnHeight, spaceInBetween, _h - (btnHeight + spaceBelow), renderer, comicFont_path, 25, "PORT=     ", txtHost_Handler);
	txtJoin = new Textbox(btnWidth, btnHeight, spaceInBetween * 2 + btnWidth, _h - (btnHeight + spaceBelow), renderer, comicFont_path, 25, "IP=      ", txtJoin_Handler);
}


void Starting::pollEvents(SDL_Event event)
{
	btnCredits->pollEvents(event);
	if (!Starting::txtJoinVisible)
	{
		btnJoin->pollEvents(event);
	}
	else
	{
		txtJoin->pollEvents(event);
	}
	if (!Starting::txtHostVisible)
	{
		btnHost->pollEvents(event);
	}
	else
	{
		txtHost->pollEvents(event);
	}
	ScreenStatus::StartingStatus = !ScreenStatus::LobbyStatus && !ScreenStatus::CreditsStatus;
	switch (event.key.keysym.sym)
	{
	
	

	}
}


bool Starting::getLobbyStatus()
{
	return Lobby::status;
}

bool Starting::getCreditsStatus()
{
	return Credits::status;
}

