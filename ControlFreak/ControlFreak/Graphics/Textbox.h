#pragma once
#include "Button.h"

class Textbox : GameObject{
private:
	bool m_Selected = false;

public:
	Textbox(int w, int h, int x, int y, SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message, void (*m_ClickEvent)());
	~Textbox() {
		m_Rect->~Rect();
		m_Text->~Text();
	}

	void draw() override;

	void pollEvents(SDL_Event& event) override {
		if (event.type == SDL_MOUSEBUTTONUP) {
			if (Window::mousePos[0] >= m_Rect->getPos()[0] && Window::mousePos[0] <= m_Rect->getPos()[0] + m_Rect->m_Width && Window::mousePos[1] >= m_Rect->getPos()[1] && Window::mousePos[1] <= m_Rect->getPos()[1] + m_Rect->m_Height) {
				m_Selected = true;
				SDL_StartTextInput();
			}
			else {
				m_Selected = false;
				SDL_StopTextInput();
			}
			//SDL_SetTextInputRect(&m_Text->m_TextRect);
		}
		else if (m_Selected && event.type == SDL_TEXTINPUT) {
			m_Text->setText(m_Text->text.substr(1) + event.text.text);
			//m_Text->setPos(m_Text->getPos()[0] - 1, m_Text->getPos()[1]);
			//m_Text->m_FontSize+=50;
		}
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_RETURN) {
				if (m_ClickEvent != nullptr) {
					m_ClickEvent();
				}
			}
		}
	}

	void (*m_ClickEvent)() = nullptr;;
	Rect* m_Rect = nullptr;
	Text* m_Text = nullptr;;
};