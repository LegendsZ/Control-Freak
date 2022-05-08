#include "ListboxItem.h"

ListboxItem::ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h,int x, int y,std::string column, int r, int g, int b, int a): _w(w),_h(h),_x(x), _y(y)
{
	Text* item = new Text(renderer, fontPath, 25, column, { 255,255,255,255 }, {(Uint8)r,(Uint8)g,(Uint8)b,(Uint8)a});
	item->setPos(x, y);
	columns.push_back(item);
}

ListboxItem::ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x,int y, std::vector<std::string> columns, int r, int g, int b, int a):_w(w),_h(h),_x(x),_y(y)
{
	int xL = x;
	for (int i = 0; i < columns.size(); i++) {
		Text* item = new Text(renderer, fontPath, 20, columns[i], { 255,0,0,255 }, { (Uint8)r,(Uint8)g,(Uint8)b,(Uint8)a });


		item->setPos(xL, y);
		this->columns.push_back(item);
		xL = xL == x ? xL + w / 5 : xL + w/2;
	}

	/*int xLocal = x; //this algo below is good for separating row lengths based off # of row and size of each.
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
	}*/
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

