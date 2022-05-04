#include "ButtonV2.h"

ButtonV2::ButtonV2(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, r, g, b, a);
	m_Text = nullptr;
}

ButtonV2::ButtonV2(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, filePath);
	m_Text = nullptr;
}

ButtonV2::ButtonV2(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a, void(*handler)()) : m_Handler(handler)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, r, g, b, a);
	m_Text = nullptr;
}

ButtonV2::ButtonV2(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath, void(*handler)()): m_Handler(handler)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, filePath);
	m_Text = nullptr;
}

ButtonV2::~ButtonV2()
{
	m_Rect->~Rect();
	m_Text->~Text();
}

bool ButtonV2::setHandler(void(*handler)())
{
	m_Handler = handler;
	return true;
}

bool ButtonV2::inPoint(int x, int y)
{
	if ((x >= m_Rect->getPos()[0] && x <= m_Rect->getPos()[0] + m_Rect->m_Width) && y >= m_Rect->getPos()[1] && y <= m_Rect->getPos()[1] + m_Rect->m_Height)
	{
		return true;
	}
	return false;
}

void ButtonV2::pollEvents(SDL_Event& event)
{
	if (inPoint(event.motion.x, event.motion.y))
	{
		switch (event.type)
		{
		case SDL_MOUSEBUTTONUP:
			_status = true;
			if (m_Handler != nullptr) {
				m_Handler();
			}
		}
	}
}

void ButtonV2::draw()
{
	m_Rect->draw();
	if (m_Text != nullptr) {
		m_Text->draw();
	}
}