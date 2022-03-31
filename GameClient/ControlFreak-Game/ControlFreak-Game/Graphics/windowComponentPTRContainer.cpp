#include "windowComponentPTRContainer.h"

Window* windowComponentPTRContainer::windowPTR = nullptr;
Rect* windowComponentPTRContainer::backgroundPTR = nullptr;
Button* windowComponentPTRContainer::btnPlayPTR = nullptr;



std::vector<GameObject*> windowComponentPTRContainer::GameObjectList;