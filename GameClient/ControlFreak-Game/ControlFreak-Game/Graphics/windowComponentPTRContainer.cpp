#include "windowComponentPTRContainer.h"

Window* windowComponentPTRContainer::windowPTR = nullptr;
Rect* windowComponentPTRContainer::backgroundPTR = nullptr;
Button* windowComponentPTRContainer::btnPlayPTR = nullptr;
Button* windowComponentPTRContainer::btnResetPTR = nullptr;
Button* windowComponentPTRContainer::btnCreditPTR = nullptr;


std::vector<GameObject*> windowComponentPTRContainer::GameObjectList;