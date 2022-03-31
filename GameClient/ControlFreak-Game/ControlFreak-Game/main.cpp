/*
	Authors: Akkshai. B, Roland. T
	Date creation: 3/6/2022
	Version: 1.0.0.0
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> //debugging/testing purposes
#include "Client/client.h"
#include "Graphics/Window.h"
#include "Graphics/windowComponentPTRContainer.h"

#include <SDL.h>
#undef main



struct IPv4
{
	unsigned char b1, b2, b3, b4;
};
bool getMyIP(IPv4& myIP)
{
	char szBuffer[1024];

#ifdef WIN32
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 0);
	if (::WSAStartup(wVersionRequested, &wsaData) != 0)
		return false;
#endif


	if (gethostname(szBuffer, sizeof(szBuffer)) == SOCKET_ERROR)
	{
#ifdef WIN32
		WSACleanup();
#endif
		return false;
	}

	struct hostent* host = gethostbyname(szBuffer);
	if (host == NULL)
	{
#ifdef WIN32
		WSACleanup();
#endif
		return false;
	}

	//Obtain the computer's IP
	myIP.b1 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b1;
	myIP.b2 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b2;
	myIP.b3 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b3;
	myIP.b4 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b4;

#ifdef WIN32
	WSACleanup();
#endif
	return true;
}



void btnPlay(SDL_Event& event) {
	std::cout << "there was an event!\n";
}


int main() {
	system("title CLIENT");
	const unsigned int FRAMESCAP = 60;

	windowComponentPTRContainer::windowPTR = new Window("Control Freak | Menu", 600, 500); 
	SDL_ShowWindow(windowComponentPTRContainer::windowPTR->m_Window);

	windowComponentPTRContainer::backgroundPTR = new Rect(300, 500, 150, 0, 255, 0, 0, 1);//background for menu;
	windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::backgroundPTR);
	windowComponentPTRContainer::btnPlayPTR = new Button(
		150,50,225,50,
		255,102,0,0,
		btnPlay
	);
	windowComponentPTRContainer::GameObjectList.push_back((GameObject*)windowComponentPTRContainer::btnPlayPTR);

	Uint32 iStart;
	while (!windowComponentPTRContainer::windowPTR->isClosed()) {
		iStart = SDL_GetTicks();
		
		for (int i = 0; i < windowComponentPTRContainer::GameObjectList.size(); i++) {//draws all components
			windowComponentPTRContainer::GameObjectList[i]->draw();
		}

		windowComponentPTRContainer::windowPTR->clear();
		SDL_Event event;
		SDL_PollEvent(&event);
		windowComponentPTRContainer::btnPlayPTR->pollEvents(event);

		if (1000 / FRAMESCAP > SDL_GetTicks() - iStart) { //to cap frames
			Uint32 toDelay = 1000 / FRAMESCAP - (SDL_GetTicks() - iStart);
			SDL_Delay(toDelay);
		}
	}



	std::string ipG;
	std::cout << "IP: ";
	std::getline(std::cin, ipG);

	std::string portG;
	std::cout << "PORT: ";
	std::getline(std::cin, portG);

	client* clientOBJ = new client(ipG, std::stoi(portG));

	if (!clientOBJ->autoStart()) {
		return 0; //error handle?
	}
	system("pause");
	std::string myIPV4 = "";
	IPv4 myIPV4TEMP;
	getMyIP(myIPV4TEMP);
	myIPV4 = std::to_string(myIPV4TEMP.b1) + "." + std::to_string(myIPV4TEMP.b2) + "." + std::to_string(myIPV4TEMP.b3) + "." + std::to_string(myIPV4TEMP.b4);
	
	clientOBJ->sendData(myIPV4 + "ISREADY");

	system("pause");

	while (true) {
		if (clientOBJ->recieved.size() > 0) {
			if (clientOBJ->recieved.back() == "") { //check for whatever data input

				clientOBJ->recieved.pop_back();
			}
		}
	}

	system("pause");
	//code below will tell server i am dc'ing
	clientOBJ->sendData(myIPV4 + "ISDCING");
	//garbage collections
	clientOBJ->Terminate();

	return 0;
}