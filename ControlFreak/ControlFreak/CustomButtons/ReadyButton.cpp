#include "ReadyButton.h"

ReadyButton::ReadyButton(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, r, g, b, a);
	m_Text = nullptr;
}

ReadyButton::ReadyButton(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, filePath);
	m_Text = nullptr;
}

ReadyButton::~ReadyButton()
{
	m_Rect->~Rect();
	m_Text->~Text();
}

bool ReadyButton::inPoint(int x, int y)
{
	if ((x >= m_Rect->getPos()[0] && x <= m_Rect->getPos()[0] + m_Rect->m_Width) && y >= m_Rect->getPos()[1] && y <= m_Rect->getPos()[1] + m_Rect->m_Height)
	{
		return true;
	}
	return false;
}

void ReadyButton::pollEvents(SDL_Event& event)
{
	if (inPoint(event.motion.x, event.motion.y))
	{
		switch (event.type)
		{
		case SDL_MOUSEBUTTONUP:
			_status = true;
		}
	}
}

void ReadyButton::draw()
{
	m_Rect->draw();
	if (m_Text != nullptr) {
		m_Text->draw();
	}
}

/*	auto play = [](SDL_Event& event) {
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			std::cout << "Something was done";
		}

	};
	playButton = new Button(70, 70, (_w - 35) / 2, _h / 4, 50, 0, 50, 1, play);*/