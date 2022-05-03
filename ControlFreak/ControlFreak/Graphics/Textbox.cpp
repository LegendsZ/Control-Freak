#include "Textbox.h"

Textbox::Textbox(int w, int h, int x, int y, SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message, void (*m_ClickEvent)()):
	m_ClickEvent(m_ClickEvent)
{
	m_Rect = new Rect(w, h, x, y, 255,255,255,1);
	m_Text = new Text(renderer, font_path, font_size, message, {0,0,0});
	m_Text->setRenderer(renderer);
	m_Text->setPos(x + w / 2 - m_Text->m_TextRect.w / 2, y + h / 2 - m_Text->m_TextRect.h / 2);
}

void Textbox::draw()
{
	m_Rect->draw();
	m_Text->draw();
}

