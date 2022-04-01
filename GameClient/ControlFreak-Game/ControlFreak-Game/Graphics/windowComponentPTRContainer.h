#pragma once
#include "Button.h"
#include <vector>

//ptrs to hold window components
class windowComponentPTRContainer {
private:
public:
	static std::vector<GameObject*> GameObjectList;

	static Window* windowPTR;
	static Rect* backgroundPTR;
	static Button* btnPlayPTR;
	static Button* btnResetPTR;
	static Button* btnCreditPTR;
};