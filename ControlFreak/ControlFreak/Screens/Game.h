#pragma once
#include "../Graphics/Rect.h"
class Game : GameObject {
private:
public:
	bool status = false;
	static bool gameActive;
	Rect* background=nullptr;
	Game(int w, int h, int x, int y);
	int w, h;
	void draw() override;
	void pollEvents(SDL_Event& event) override;
};