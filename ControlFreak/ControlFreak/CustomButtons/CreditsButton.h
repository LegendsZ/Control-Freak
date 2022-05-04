#pragma once

#include "..\Graphics\Button.h"
#include "..\Graphics\Window.h"
#include "..\Screens\Lobby.h"
#include "../Screens/Credits.h"

class CreditsButton : GameObject
{
public:
	CreditsButton(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a);
	CreditsButton(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath);
	~CreditsButton();
	Rect* m_Rect;
	Text* m_Text;
	bool _status;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = Window::renderer;

	bool inPoint(int x, int y);
	void pollEvents(SDL_Event& event);
	void draw();
};
