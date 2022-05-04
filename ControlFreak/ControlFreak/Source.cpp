/*
	Authors: Akkshai. B, Roland. T
	Date creation: 5/3/2022
	Version: 1.0.0.0
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> //debugging/testing purposes
#include "Client/ClientData.h"
#include "Graphics/Window.h"
#include "Graphics/windowComponentPTRContainer.h"
#include "fileLocations.h"
#include "SDL.h"
#include "Screens/Starting.h"
#undef main

const std::string version = "1.0.0.0"; //version control

int main() {
	std::string titleString = "title Control Freak v" + version;
	system(titleString.c_str());


	const unsigned int FRAMESCAP = 60; //set to ur screen refresh rate
	bool gameActive = false;
	bool STARTACTIVE = true;
	SDL_Event event;
	Window window("Control Freak | Menu", 700, 600);
	window.setWindowIconFilePath(icon_path);
	
	SDL_ShowWindow(window.m_Window);
	Starting mainpage(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Lobby lobby(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Credits credit(window.m_Window, window.renderer, window.m_Width, window.m_Height);

	while (true)
	{
		while (SDL_PollEvent(&event))
		{
			if (mainpage.status)
			{
				mainpage.draw();
				mainpage.pollEvents(event);
			}else if (mainpage.getLobbyStatus())
			{
				lobby.draw();
				lobby.pollEvents(event);
			}else if (mainpage.getCreditsStatus())
			{
				credit.draw();
				credit.pollEvents(event);

			}
			window.clear();
		}
	}







	system("pause");
}