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
#include "Screens/MiniMenu.h"
#undef main

const std::string version = "1.0.0.0"; //version control

int main() {
	std::string titleString = "title Control Freak v" + version;
	system(titleString.c_str());


	const unsigned int FRAMESCAP = 60; //set to ur screen refresh rate
	const unsigned int COMPCAP = 600; //set to 60 for now
	int FPS = 0;

	Uint32 lastFrame = SDL_GetTicks();
	UINT32 elapsedDraw = SDL_GetTicks();
	UINT32 elapsedComp = SDL_GetTicks();

	bool gameActive = false;
	bool STARTACTIVE = true;
	SDL_Event event;

	Window window("Control Freak | Menu", 700, 600);
	window.setWindowIconFilePath(icon_path);
	
	SDL_ShowWindow(window.m_Window);
	Starting mainpage(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Lobby lobby(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	Credits credit(window.m_Window, window.renderer, window.m_Width, window.m_Height);
	MiniMenu menu(window.m_Window, window.renderer, window.m_Width, window.m_Height);

	
	while (!window.isClosed())
	{
		//Original here you can delete this once u feel comfortable with what we have here.
		/*while (SDL_PollEvent(&event))
		{
			if (mainpage.getLobbyStatus())
			{
				lobby.draw();
				lobby.pollEvents(event);
			}else if (mainpage.getCreditsStatus())
			{
				credit.draw();
				credit.pollEvents(event);
			}
			else
			{
				mainpage.draw();
				mainpage.pollEvents(event);
			}
			
			window.clear();
		}*/
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
		
		else
		{
			mainpage.pollEvents(event);
		}

		if (1000 / COMPCAP <= SDL_GetTicks() - elapsedComp) { //to cap computation
			//LOGIC CALLS HERE
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
			//FPS = 0;
			lastFrame = SDL_GetTicks();
		}

	}


	system("pause");
	return 0;
}