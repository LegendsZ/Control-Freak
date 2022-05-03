#pragma once

class GameObject{

private:

public:

	virtual void draw() = 0;
	virtual void pollEvents(SDL_Event& event) = 0;
};