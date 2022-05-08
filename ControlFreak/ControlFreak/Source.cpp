/*
	Authors: Akkshai. B, Roland. T
	Date creation: 5/3/2022
	Version: 1.0.0.0
*/

#pragma once
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> //debugging/testing purposes
#include "Graphics/Window.h"
#include "Graphics/windowComponentPTRContainer.h"
#include "SDL.h"
#include "Screens/Starting.h"
#include "Screens/MiniMenu.h"
#include "Screens/Game.h"

#undef main

int main() {
	std::string titleString = "title Control Freak v" + version;
	system(titleString.c_str());


	const unsigned int FRAMESCAP = 60; //set to ur screen refresh rate
	const unsigned int COMPCAP = 600; //set to 60 for now
	int FPS = 0;

	Uint32 lastFrame = SDL_GetTicks();
	Uint32 elapsedDraw = SDL_GetTicks();
	Uint32 elapsedComp = SDL_GetTicks();
	bool STARTACTIVE = true;
	SDL_Event event;

	Window window("Control Freak | Menu", 700, 600);
	window.setWindowIconFilePath(icon_path);
	
	SDL_ShowWindow(window.m_Window);
	Starting mainpage(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Lobby lobby(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Credits credit(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	MiniMenu menu(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Game* game = nullptr;
	
	while (!window.isClosed())
	{
		//polling calls here
		SDL_PollEvent(&event);
		if (mainpage.getLobbyStatus())
		{
			lobby.pollEvents(event);
			if (menu.getStatus())
			{
				menu.pollEvents(event);
			}
		}
		else if (mainpage.getCreditsStatus())
		{
			credit.pollEvents(event);
			if (menu.getStatus())
			{
				menu.pollEvents(event);
			}
		}
		else if (game == nullptr || !game->status)
		{
			mainpage.pollEvents(event);
		}
		else {
			game->pollEvents(event);
		}

		if (1000 / COMPCAP <= SDL_GetTicks() - elapsedComp) { //to cap computation
			//LOGIC CALLS HERE

			if (Connector::clientOBJ != nullptr) {//client below
				if (Connector::clientOBJ->recieved.size() > 0) {
					if (Game::gameActive) {
						
					}
					else {
						if (Connector::clientOBJ->recieved.back() == "VERSIONGOOD") { //check for whatever data input
							Connector::clientOBJ->sendData(Connector::myIPV4 + "ISREADY");
							int index = 0;
							Lobby::type = NONHOST;
							Lobby::status = !Lobby::status;
						}
						else if (Connector::clientOBJ->recieved.back() == "VERSIONBAD") { //check for whatever data input
							std::cout << "\n\nVersion is out of date! Please update.\n\n";
							system("pause");
						}
						else if (Connector::clientOBJ->recieved.back() == "GAMESTART") { //check for whatever data input
							game = new Game(window.m_Width, window.m_Height,0,0);
							Connector::clientOBJ->sendData(Connector::myIPV4 + "GAMESTARTED");
							Game::gameActive = true;
						}
					}
					Connector::clientOBJ->recieved.pop_back();
				}
			}
			else { //server below

			}

			elapsedComp = SDL_GetTicks();
		}
		if (1000 / FRAMESCAP <= SDL_GetTicks() - elapsedDraw) { //to cap frames
			//DRAW CALLS HERE
			if (mainpage.getLobbyStatus())
			{
				lobby.draw();
				if (menu.getStatus())
				{
					menu.draw();
				}
			}
			else if (mainpage.getCreditsStatus())
			{
				credit.draw();
				if (menu.getStatus())
				{
					menu.draw();
				}
			}
			else
			{
				mainpage.draw();
			}
			window.clear();
			FPS++;
			elapsedDraw = SDL_GetTicks();
		}

		if ((SDL_GetTicks() - lastFrame) / 1000.0 >= 1) {
			system("cls");
			std::cout << "FPS: " << FPS << "\n";
			FPS = 0;
			lastFrame = SDL_GetTicks();
		}
	}
	window.~Window();

	system("pause");
	return 0;
}