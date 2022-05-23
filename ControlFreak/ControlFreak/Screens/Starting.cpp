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
void btnSettings_Handler2() {
	std::cout << "Settings clicked\n";
	ScreenStatus::SettingsStatus = true;
	/*Lobby::status = !Lobby::status;
	Lobby::type = NONHOST;*/
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

Starting::Starting(Window* window, SDL_Renderer* renderer, int w, int h) : _window(window->m_Window), _w(w), _h(h), _renderer(renderer)
{
	WINDOW = window;
	createElements(renderer);
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
	btnSettings->~ButtonV2();
	background->~Rect();
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
	btnSettings->draw();
	title->draw();
}

void Starting::createElements(SDL_Renderer* renderer)
{
	background = new Rect(WINDOW->m_Width, WINDOW->m_Height, 0, 0, 22, 157, 196, 255);
	title = new Rect(WINDOW->m_Width / 2, WINDOW->m_Height / 2, WINDOW->m_Width / 4, WINDOW->m_Height / 9, bkgdMenuV3_path);
	int btnWidth = WINDOW->m_Width / 8;
	int btnHeight = WINDOW->m_Height / 9;
	//int numBtns = 3;
	int spaceInBetween = WINDOW->m_Width / 16; //quick maths
	int spaceBelow = WINDOW->m_Height / 9;
	std::cout << "Height: " + std::to_string(WINDOW->m_Height) + "\n";
	std::cout << "Width: " + std::to_string(WINDOW->m_Width) + "\n";
	btnHost = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 2.5, WINDOW->m_Height - 2 * spaceBelow, bkgdbtnHost_path, btnHost_Handler);
	btnJoin = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 5.5, WINDOW->m_Height - 2 * spaceBelow, bkgdbtnJoin_path,btnJoin_Handler);
	btnCredits = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 8.5, WINDOW->m_Height - 2 * spaceBelow, bkgdbtnCredit_path, btnCredits_Handler);
	btnSettings = new ButtonV2(_window, btnWidth, btnHeight, spaceInBetween * 11.5, WINDOW->m_Height - 2 * spaceBelow, bkgdbtnSettings_path, btnSettings_Handler2);
	txtHost = new Textbox(btnWidth, btnHeight, spaceInBetween * 2.5, WINDOW->m_Height - 2 * spaceBelow, renderer, comicFont_path, 25, "PORT=     ", txtHost_Handler, { 255,255,255 }, { 255,0,0 });
	txtJoin = new Textbox(btnWidth, btnHeight, spaceInBetween * 5.5, WINDOW->m_Height - 2 * spaceBelow, renderer, comicFont_path, 25, "IP=      ", txtJoin_Handler, { 255,255,255 }, { 255,0,0 });
}


void Starting::pollEvents(SDL_Event event)
{
	btnSettings->pollEvents(event);
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

void Starting::changeRes()
{
	createElements(_renderer);
}