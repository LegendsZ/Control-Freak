#include "Game.h"

bool Game::gameActive = false;

Game::Game(int w, int h, int x, int y) : w(w), h(h)
{
	background = new Rect(w,h,x,y,24,233,240,255);
}

void Game::draw()
{
	background->draw();
}

void Game::pollEvents(SDL_Event& event)
{
}
