#pragma once
#include <string>

struct player {
private:
	std::string ip = "";
	bool readyToPlay = false;
	//any other info goes here
public:
	player(std::string ip);
	std::string& getIP();
	bool isReady();
	bool setIP(std::string value);
	bool setReady(bool value);
};