#include "Listbox.h"

Listbox::Listbox(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x, int y,std::string name): _w(w), _h(h), _x(x),_y(y), _renderer(renderer),_fontPath(fontPath)
{
	items.push_back(new ListboxItem(renderer,fontPath,w,25,x, items[items.size()-1]->_y+ items[items.size() - 1]->_h, name));//change the 25 later
}

void Listbox::addItem(std::vector<std::string> columns)
{
	items.push_back(new ListboxItem(_renderer,_fontPath,_w,25,_x, items[items.size() - 1]->_y + items[items.size() - 1]->_h,columns));//change the 25 later
}

void Listbox::removeItem(int index)
{
	delete items[index];
	items.erase(items.begin() + index - 1);
}

void Listbox::draw()
{
	for (int i = 0; i < items.size(); i++) {
		items[i]->draw();
	}
}

void Listbox::pollEvents(SDL_Event& event)
{
}
