#include "Button.h"

Button::Button(int w, int h, int x, int y, int r, int g, int b, int a, SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message, const SDL_Color& color, void(*handler)(SDL_Event&) ) :
	m_Handler(handler)
{
	m_Rect = new Rect(w, h, x, y, r, g, b, a);
	m_Text = new Text(renderer, font_path, font_size, message, color);
	m_Text->setRenderer(renderer);
	m_Text->setPos(x + w / 2 - m_Text->m_TextRect.w / 2, y + h / 2 - m_Text->m_TextRect.h/2);
}

Button::Button(int w, int h, int x, int y, const std::string& img_path, SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message, const SDL_Color& color, void(*handler)(SDL_Event&)):
	m_Handler(handler)
{
	m_Rect = new Rect(w, h, x, y, img_path);
	m_Text = new Text(renderer, font_path, font_size, message, color);
	m_Text->setRenderer(renderer);
	m_Text->setPos(x + w / 2 - m_Text->m_TextRect.w / 2, y + h / 2 - m_Text->m_TextRect.h / 2);
}

Button::Button(Rect* rect, Text* text, void(*handler)(SDL_Event&)):
	m_Handler(handler)
{
	m_Rect = rect;
	m_Text = text;
}

Button::Button(int w, int h, int x, int y, const std::string& img_path, void(*handler)(SDL_Event&)):
	m_Handler(handler)
{
	m_Rect = new Rect(w, h, x, y, img_path);
	m_Text = nullptr;
}

Button::Button(int w, int h, int x, int y, int r, int g, int b, int a, void(*handler)(SDL_Event&)):
	m_Handler(handler)
{
	m_Rect = new Rect(w, h, x, y, r,g,b,a);
	m_Text = nullptr;
}

Button::~Button()
{
	m_Rect->~Rect();
	m_Text->~Text();
}


void Button::pollEvents(SDL_Event& event)
{
	m_Handler(event);
}

bool Button::setPos(int x, int y)
{
	m_Rect->setPos(x, y);
	if (m_Text != nullptr) {
		m_Text->setPos(x +m_Rect->m_Width / 2 - m_Text->m_TextRect.w / 2, y + m_Rect->m_Height / 2 - m_Text->m_TextRect.h / 2);
	}
	return true;
}

int* Button::getPos()
{
	return m_Rect->getPos();
}

void Button::draw()
{
	m_Rect->draw();
	if (m_Text != nullptr) {
		m_Text->draw();
	}
}
