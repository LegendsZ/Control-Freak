#include "ListboxItem.h"

ListboxItem::ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h,int x, int y,std::string column): _w(w),_h(h),_x(x), _y(y)
{
	Text* item = new Text(renderer, fontPath, 25, column, { 255,0,0,255 });
	item->setPos(x, y);
	columns.push_back(item);
}

ListboxItem::ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x,int y, std::vector<std::string> columns):_w(w),_h(h),_x(x),_y(y)
{
	int xLocal = x;

	int totalLength = 0;
	for (int i = 0; i < columns.size(); i++) {
		totalLength += columns[i].length();
	}

	for (int i = 0; i < columns.size(); i++) {
		Text* item = new Text(renderer, fontPath, 20, columns[i], {255,0,0,255});
		this->columns.push_back(item);
		double t = ((double)columns[i].length() / (double)totalLength) * w;
		int adder = (t / 2) - (item->m_TextRect.w / 2);
		item->setPos(xLocal +adder, y);

		xLocal += (int)t;
	}
}

void ListboxItem::draw()
{
	for (int i = 0; i < columns.size(); i++) {
		columns[i]->draw();
	}
}

void ListboxItem::pollEvents(SDL_Event& event)
{
	
}

