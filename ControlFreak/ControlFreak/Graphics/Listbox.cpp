#include "Listbox.h"

Listbox::Listbox(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x, int y,std::string name): _w(w), _h(h), _x(x),_y(y), _renderer(renderer),_fontPath(fontPath)
{
	this->name = new Text(renderer, fontPath, 25, name, { 255,0,0,255 });
	this->name->setPos(x + (w / 2) - (this->name->m_TextRect.w / 2), y);
	backgroundRect = new Rect(w, h, x, y, 0, 0, 0, 0);
	visibleItemCount = (_h - this->name->m_TextRect.h) / (25);
}

void Listbox::addItem(std::vector<std::string> columns)
{
	if (items.size() != 0) {
		items.push_back(new ListboxItem(_renderer,_fontPath,_w,25,_x, items[items.size() - 1]->_y + items[items.size() - 1]->_h,columns));//change the 25 later //the "15" is an adjustment value
	}
	else {
		items.push_back(new ListboxItem(_renderer, _fontPath, _w, 25, _x, _y + name->m_TextRect.h+10, columns));//change the 25 later
	}
	//visibleItemCount = (_h - this->name->m_TextRect.h) / (items[0]->_h);
	if (visibleItems.size() < visibleItemCount) {
		visibleItems.push_back(items[items.size() - 1]);
	}
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
	for (int i = 0; i < visibleItems.size(); i++) {
		visibleItems[i]->draw();
	}
}

void Listbox::pollEvents(SDL_Event& event)
{
}

void Listbox::scrollUp(int count)
{
	while (count-- != 0) {
		if (visibleItemIndex > 0) {
			visibleItems.insert(visibleItems.begin(), items[visibleItemIndex - 1]);
			visibleItems.push_back(items[visibleItemIndex + visibleItems.size()]);
			visibleItems.erase(visibleItems.begin() + visibleItems.size()-1);
			visibleItemIndex--;
		}
	}
}

void Listbox::scrollDown(int count)
{
	while (count-- != 0) {
		if (visibleItemIndex + visibleItems.size() < items.size()) {
			visibleItems.push_back(items[visibleItemIndex + visibleItems.size()]);
			visibleItems.erase(visibleItems.begin());
			visibleItemIndex++;
		}
	}
}
