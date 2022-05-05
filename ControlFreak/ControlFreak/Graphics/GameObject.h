#pragma once
//#include "Window.h"
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream> //for debug

class GameObject{

private:

public:

	virtual void draw() = 0;
	virtual void pollEvents(SDL_Event& event) = 0;
};