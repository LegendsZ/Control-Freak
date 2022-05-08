#include "player.h"


player::player(std::string ip) : ip(ip) {

}

std::string& player::getIP() {
	return ip;
}
bool player::isReady() {
	return readyToPlay;
}

bool player::setIP(std::string value) {
	ip = value;
	return true;
}
bool player::setReady(bool value) {
	readyToPlay = value;
	return true;
}