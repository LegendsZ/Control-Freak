#include "CreditsButton.h"

CreditsButton::CreditsButton(SDL_Window* window, int w, int h, int x, int y, int r, int g, int b, int a)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, r, g, b, a);
	m_Text = nullptr;
}

CreditsButton::CreditsButton(SDL_Window* window, int w, int h, int x, int y, const std::string& filePath)
{
	_status = false;
	m_Rect = new Rect(w, h, x, y, filePath);
	m_Text = nullptr;
}

CreditsButton::~CreditsButton()
{
	m_Rect->~Rect();
	m_Text->~Text();

}

bool CreditsButton::inPoint(int x, int y)
{
	if ((x >= m_Rect->getPos()[0] && x <= m_Rect->getPos()[0] + m_Rect->m_Width) && y >= m_Rect->getPos()[1] && y <= m_Rect->getPos()[1] + m_Rect->m_Height)
	{
		return true;
	}
	return false;
}

void CreditsButton::pollEvents(SDL_Event& event)
{
	if (inPoint(event.motion.x, event.motion.y))
	{
		switch (event.type)
		{
		case SDL_MOUSEBUTTONUP:
			_status = true;
			std::cout << "FALSE NOW BABY";

		}
	}
}

void CreditsButton::draw()
{
	m_Rect->draw();
	//m_Text->draw();
}

/*	auto play = [](SDL_Event& event) {
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			std::cout << "Something was done";
		}

	};
	playButton = new Button(70, 70, (_w - 35) / 2, _h / 4, 50, 0, 50, 1, play);*/