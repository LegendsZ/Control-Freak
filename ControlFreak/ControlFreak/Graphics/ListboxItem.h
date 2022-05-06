#pragma once
#include "Rect.h"
#include "Text.h"
#include <vector>

class ListboxItem : GameObject{
private:
	std::vector<Text*> columns;
public:
	int _x=0;
	int _w=0;
	int _y=0;
	int _h=0;
	ListboxItem(SDL_Renderer* renderer, std::string fontPath,int w, int h, int x,int y,std::string column, int r, int g, int b,int a);
	ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h,int x,int y,std::vector<std::string> columns, int r, int g, int b, int a);

	void draw() override;
	void pollEvents(SDL_Event& event) override;
};