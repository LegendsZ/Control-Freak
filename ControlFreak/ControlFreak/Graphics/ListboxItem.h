#pragma once
#include "GameObject.h"
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
	ListboxItem(SDL_Renderer* renderer, std::string fontPath,int w, int h, int x,int y,std::string column);
	ListboxItem(SDL_Renderer* renderer, std::string fontPath, int w, int h,int x,int y,std::vector<std::string> columns);

	void draw() override;
	void pollEvents(SDL_Event& event) override;
};