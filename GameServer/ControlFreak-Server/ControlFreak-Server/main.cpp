/*
	Authors: Akkshai. B, Roland. T
	Date creation: 3/6/2022
	Version: 1.0.0.0
*/

#include <iostream> //debugging/testing purposes

#include "ServerClient/client.h"
#include "ServerClient/server.h"



//FOR PRINTING TO SERVER
void FprintStuffS(bool* updateScreenG, server* serverG) {
	while (*updateScreenG) {
		if (serverG->recieved.size() != 0) {
			std::cout << "Console: " << serverG->recieved.front() << "\n> ";
			serverG->recieved.erase(serverG->recieved.begin());
		}
	}
}



//ENTRY POINT
int main() {
	system("title SERVER");

	server* serverOBJ = nullptr;

	//BELOW CODE IS FOR SERVER INITIALIZATION
	std::cout << "Enter port number: ";
	std::string input;
	std::getline(std::cin,input);
	serverOBJ = new server(std::stoi(input));
	if (!serverOBJ->autoStart()) {
		return 0;
	}
	std::cout << "Created server on port [" << input << "]!\n";
	std::cout << "Once you are done accepting, ";
	system("pause");
	std::cout << "Stopped accepting clients!\n\n";
	serverOBJ->endFindConnections();
	serverOBJ->startListening();
	bool* updateScreen = new bool;
	std::thread updateScreenThread(FprintStuffS, updateScreen, serverOBJ);
	//ABOVE CODE IS FOR SERVER INITIALIZATION




	system("pause");
	*updateScreen = false;
	serverOBJ->Terminate(); //garbage collec / termination
	delete serverOBJ;
	delete updateScreen;
}