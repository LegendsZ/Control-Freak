#include "ListboxItem.h"

ListboxItem::ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h,int x, int y,std::string column): _w(w),_h(h),_x(x), _y(y)
{
	Text* item = new Text(renderer, fontPath, 25, column, { 255,0,0,255 });
	item->setPos(x, y);
}

ListboxItem::ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x,int y, std::vector<std::string> columns):_w(w),_h(h),_x(x),_y(y)
{
	int wLocal = columns.size() / w;
	for (int i = 0; i < columns.size(); i++) {
		Text* item = new Text(renderer, fontPath, 25, columns[i], {255,0,0,255});
		item->setPos(i * wLocal + x, y);
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

