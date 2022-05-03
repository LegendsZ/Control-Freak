#pragma once

#include "..\Graphics\Button.h"
#include "..\Graphics\Window.h"
#include "..\Screens\Lobby.h"
class ReadyButton : GameObject
{
public:
	ReadyButton(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a);
	~ReadyButton();
	Rect* m_Rect;
	Text* m_Text;
	bool _status;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = Window::renderer;

	bool inPoint(int x, int y);
	void pollEvents(SDL_Event& event);
	void draw();
};
