#pragma once

#include "..\Graphics\Button.h"
#include "..\Graphics\Window.h"
class ButtonV2 : GameObject
{
public:
	ButtonV2(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a);
	ButtonV2(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath);
	ButtonV2(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a, void (*handler)());
	ButtonV2(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath, void (*m_Handler)());
	~ButtonV2();
	bool setHandler(void (*handler)());
	Rect* m_Rect;
	Text* m_Text;
	bool _status;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = Window::renderer;
	void (*m_Handler)() = nullptr;
	bool inPoint(int x, int y);
	void pollEvents(SDL_Event& event);
	void draw();
};
