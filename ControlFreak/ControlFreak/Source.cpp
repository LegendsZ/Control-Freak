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
#include "Screens/ScreenStatus.h"
#include "Screens/Settings.h"

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

	Window window("Control Freak | Menu", 1280, 720);
	window.setWindowIconFilePath(icon_path);
	SDL_ShowWindow(window.m_Window);
	Starting mainpage(&window, window.renderer, window.m_Width, window.m_Height);
	Lobby lobby(&window, window.renderer, window.m_Width, window.m_Height);
	Credits credit(&window, window.renderer, window.m_Width, window.m_Height);
	MiniMenu menu(&window, window.renderer, window.m_Width, window.m_Height);
	Settings settings(&window, window.renderer, window.m_Width, window.m_Height);
	Game* game = nullptr;
	
	while (!window.isClosed())
	{
		//polling calls here
		SDL_PollEvent(&event);
		if (ScreenStatus::MiniMenuStatus)
		{
			menu.pollEvents(event);
		}
		if (ScreenStatus::SettingsStatus)
		{
			settings.pollEvents(event);
		}
		else if (ScreenStatus::LobbyStatus)
		{
			lobby.pollEvents(event);
		}
		else if (ScreenStatus::CreditsStatus)
		{
			credit.pollEvents(event);
		}
		else if (ScreenStatus::StartingStatus)
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
			if (ScreenStatus::ResChanged)
			{
				window.updateSize();
				mainpage.changeRes();
				credit.changeRes();
				menu.changeRes();
				lobby.changeRes();
				ScreenStatus::ResChanged = false;
			}
			if (ScreenStatus::SettingsStatus)
			{
				settings.draw();
			}
			else if (ScreenStatus::LobbyStatus)
			{
				if (ScreenStatus::MiniMenuStatus)
				{
					menu.draw();
				}
				else
				{
					lobby.draw();
				}
			}
			else if (ScreenStatus::CreditsStatus)
			{
				credit.draw();
			}
			else if (ScreenStatus::StartingStatus)
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