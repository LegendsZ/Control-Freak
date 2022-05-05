#pragma once
#include "ListboxItem.h"

class Listbox : GameObject{
private:
	int _w;
	int _h;
	int _x;
	int _y;

public:
	Listbox(SDL_Renderer* renderer, std::string fontPath, int w, int h, int x, int y,std::string name);

	void addItem(std::vector<std::string> columns);
	void removeItem(int index);

	std::string _fontPath;
	SDL_Renderer* _renderer = nullptr;
	void draw() override;
	void pollEvents(SDL_Event& event) override;
	std::vector<ListboxItem*> items;
};