/*
	Authors: Akkshai. B, Roland. T
	Date creation: 5/3/2022
	Version: 1.0.0.0
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> //debugging/testing purposes
#include "Client/ClientData.h"
#include "Graphics/Window.h"
#include "Graphics/windowComponentPTRContainer.h"
#include "fileLocations.h"
#include "SDL.h"
#undef main

const std::string version = "1.0.0.0"; //version control

int main() {
	std::string titleString = "title Control Freak v" + version;
	system(titleString.c_str());






	system("pause");
}