#pragma once

#include "Rect.h"
#include "Text.h"
#include "Window.h"
class Button : GameObject {
public:
	Button(int w, int h, int x, int y, int r, int g, int b, int a, SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message, const SDL_Color& color, void(*handler)(SDL_Event&));
	Button(int w, int h, int x, int y, const std::string& img_path, SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message, const SDL_Color& color, void(*handler)(SDL_Event&));
	Button(Rect* rect, Text* text, void(*handler)(SDL_Event&));
	Button(int w, int h, int x, int y, const std::string& img_path, void(*handler)(SDL_Event&));
	Button(int w, int h, int x, int y, int r, int g, int b, int a, void(*handler)(SDL_Event&));
	~Button();

	void pollEvents(SDL_Event& event) override;

	bool setPos(int x, int y);
	bool pointIn(int x, int y);
	int* getPos();


	void draw() override;

	Rect* m_Rect;
	Text* m_Text;

	void (*m_Handler)(SDL_Event&);
private:
};