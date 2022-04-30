/*
	Authors: Akkshai. B, Roland. T
	Date creation: 3/6/2022
	Version: 1.0.0.0
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> //debugging/testing purposes
#include "Client/ClientData.h"
#include "Graphics/Window.h"
#include "Graphics/windowComponentPTRContainer.h"
#include "fileLocations.h"

#include <SDL.h>
#undef main

const std::string version = "1.0.0.0";


void pollEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);


	if (event.type == SDL_MOUSEMOTION) {
		Window::mousePos[0] = event.motion.x <= windowComponentPTRContainer::windowPTR->m_Width? event.motion.x : Window::mousePos[0];
		Window::mousePos[1] = event.motion.y <= windowComponentPTRContainer::windowPTR->m_Height ? event.motion.y : Window::mousePos[1];
	}


	for (int i = 0; i < windowComponentPTRContainer::GameObjectList.size(); i++) {//draws all components
		windowComponentPTRContainer::GameObjectList[i]->pollEvents(event);
	}
}



void btnPlay(SDL_Event& event) {
	//std::cout << "there was an event!\n";
}
void btnCredit(SDL_Event& event) {
	//std::cout << "there was an event!\n";
}
void txtIPPEnter() {
	//do some checking and sort ip/port somewhere
	if (Connector::connectIP == "") {
		Connector::connectIP = windowComponentPTRContainer::txtIPPTR->m_Text->text;
		windowComponentPTRContainer::txtIPPTR->m_Text->setText("PORT=");
	}
	else {
		Connector::port = std::stoi(windowComponentPTRContainer::txtIPPTR->m_Text->text);
		windowComponentPTRContainer::txtIPPTR->m_Text->setText("CONNECTING");



		Connector::clientOBJ = new client(Connector::connectIP, Connector::port);
		if (!Connector::clientOBJ->autoStart()) {
			return; //error handle?
		}
		IPv4 myIPV4TEMP;
		getMyIP(myIPV4TEMP);
		Connector::myIPV4 = std::to_string(myIPV4TEMP.b1) + "." + std::to_string(myIPV4TEMP.b2) + "." + std::to_string(myIPV4TEMP.b3) + "." + std::to_string(myIPV4TEMP.b4);
		//Connector::clientOBJ->sendData(Connector::myIPV4 + "ISREADY");
		Connector::clientOBJ->sendData(Connector::myIPV4 + "V"+version);


		/*int index = 0;
		for (int i = 0; i < windowComponentPTRContainer::GameObjectList.size(); i++) {
			if (windowComponentPTRContainer::GameObjectList[i] == (GameObject*)windowComponentPTRContainer::txtIPPTR) {
				index = i;
				break;
			}
		}
		windowComponentPTRContainer::GameObjectList.erase(windowComponentPTRContainer::GameObjectList.begin() + index);*/
	}
	
	windowComponentPTRContainer::txtIPPTR->m_Text->text = "";
}


int main() {
	std::string titleString = "title Control Freak GAME v" + version;
	system(titleString.c_str());


	const unsigned int FRAMESCAP = 60; //set to ur screen refresh rate
	bool gameActive = false;

	windowComponentPTRContainer::windowPTR = new Window("Control Freak | Menu", 600, 500); 
	SDL_ShowWindow(windowComponentPTRContainer::windowPTR->m_Window);

	//windowComponentPTRContainer::backgroundPTR = new Rect(300, 500, 150, 0, 255, 0, 0, 1);//background for menu;
	windowComponentPTRContainer::backgroundPTR = new Rect(600,500,0,0,bkgdMenu_path);//background for menu;
	windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::backgroundPTR);

	windowComponentPTRContainer::btnPlayPTR = new Button(
		175,75,213,25,
		bkgdbtnPlay_path,
		btnPlay
	);
	windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::btnPlayPTR);

	windowComponentPTRContainer::btnCreditPTR = new Button(
		175, 75, 213, 400, //y = 175?
		bkgdbtnCredit_path,
		btnCredit
	);
	windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::btnCreditPTR);


	windowComponentPTRContainer::txtIPPTR = new Textbox(
		300, 50,
		150, 125,
		windowComponentPTRContainer::windowPTR->renderer,
		comicFont_path, 40,
		"IP=",
		txtIPPEnter
	);
	windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::txtIPPTR);


	Uint32 iStart;
	while (!windowComponentPTRContainer::windowPTR->isClosed()) {
		iStart = SDL_GetTicks();

		for (int i = 0; i < windowComponentPTRContainer::GameObjectList.size(); i++) {//draws all components
			windowComponentPTRContainer::GameObjectList[i]->draw();
		}


		if (Connector::clientOBJ != nullptr) {
			if (Connector::clientOBJ->recieved.size() > 0) {
				if (gameActive) {
					//game checks
				}
				else {
					if (Connector::clientOBJ->recieved.back() == "VERSIONGOOD") { //check for whatever data input
						Connector::clientOBJ->sendData(Connector::myIPV4 + "ISREADY");
						int index = 0;
						for (int i = 0; i < windowComponentPTRContainer::GameObjectList.size(); i++) {
							if (windowComponentPTRContainer::GameObjectList[i] == (GameObject*)windowComponentPTRContainer::txtIPPTR) {
								index = i;
								break;
							}
						}
						windowComponentPTRContainer::GameObjectList.erase(windowComponentPTRContainer::GameObjectList.begin() + index);
					}else if (Connector::clientOBJ->recieved.back() == "VERSIONBAD") { //check for whatever data input
						std::cout << "\n\nVersion is out of date! Please update.\n\n";
						system("pause");
					}
					else if (Connector::clientOBJ->recieved.back() == "GAMESTART") { //check for whatever data input
						windowComponentPTRContainer::GameObjectList.clear();
						windowComponentPTRContainer::gameBackgroundPTR = new Rect(600, 500, 0, 0, bkgdGameMenu_path);//background for menu;
						windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::gameBackgroundPTR);
						Connector::clientOBJ->sendData(Connector::myIPV4 + "GAMESTARTED");
						gameActive = true;
					}
				}
				Connector::clientOBJ->recieved.pop_back();
			}
		}



		windowComponentPTRContainer::windowPTR->clear();
		pollEvents();
		if (1000 / FRAMESCAP > SDL_GetTicks() - iStart) { //to cap frames
			Uint32 toDelay = 1000 / FRAMESCAP - (SDL_GetTicks() - iStart);
			SDL_Delay(toDelay);
		}
	}

	//code below will tell server i am dc'ing
	Connector::clientOBJ->sendData(Connector::myIPV4 + "ISDCING");
	//garbage collections
	Connector::clientOBJ->Terminate();

	return 0;
}