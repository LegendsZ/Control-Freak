#include "Listbox.h"

Listbox::Listbox(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x, int y, std::string name) : _w(w), _h(h), _x(x), _y(y), _renderer(renderer), _fontPath(fontPath)
{
	backgroundRect = new Rect(w, h, x, y, 50, 50, 50, 0);
	this->name = new Text(renderer, fontPath, 25, name, { 255,0,0,255 }, {(Uint8)backgroundRect->m_R, (Uint8)backgroundRect->m_G, (Uint8)backgroundRect->m_B, (Uint8)backgroundRect->m_A});
	this->name->setPos(x + (w / 2) - (this->name->m_TextRect.w / 2), y);
	//SDL_Surface* surface = SDL_CreateRGBSurface(0, this->name->m_TextRect.w, this->name->m_TextRect.h, 32,0, 0, 0, 0);
	//visibleItemCount = (_h - this->name->m_TextRect.h) / (25);
}

void Listbox::addItem(std::vector<std::string> columns)
{
	if (items.size() != 0 && items.size() < 4) {
		items.push_back(new ListboxItem(_renderer,_fontPath,_w,25,_x, items[items.size() - 1]->_y + items[items.size() - 1]->_h,columns,  (Uint8)backgroundRect->m_R, (Uint8)backgroundRect->m_G, (Uint8)backgroundRect->m_B, (Uint8)backgroundRect->m_A ));//change the 25 later //the "15" is an adjustment value
	}
	else if (items.size() == 0) {
		items.push_back(new ListboxItem(_renderer, _fontPath, _w, 25, _x, _y + name->m_TextRect.h+10, columns, (Uint8)backgroundRect->m_R, (Uint8)backgroundRect->m_G, (Uint8)backgroundRect->m_B, (Uint8)backgroundRect->m_A));//change the 25 later
	}
	//visibleItemCount = (_h - this->name->m_TextRect.h) / (items[0]->_h);
}

void Listbox::removeItem(int index)
{
	delete items[index];
	items.erase(items.begin() + index - 1);
}

void Listbox::draw()
{
	backgroundRect->draw();
	name->draw();
	for (int i = 0; i < items.size(); i++) {
		items[i]->draw();
	}
}

void Listbox::pollEvents(SDL_Event& event)
{
}