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
			//serverG->recieved.erase(serverG->recieved.begin()); //dont remove for now
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
	
	while (serverOBJ->getConnectionsCount() < 2) {
		system("cls");
		system("pause");
	}
	system("cls");

	std::cout << "Stopped accepting clients!\n\n";
	serverOBJ->endFindConnections();
	serverOBJ->startListening();
	bool* updateScreen = new bool;
	//std::thread updateScreenThread(FprintStuffS, updateScreen, serverOBJ); //keep commented for now
	//ABOVE CODE IS FOR SERVER INITIALIZATION

	if (!serverOBJ->sendData(NULL, "READYTOSTART")) {
		std::cout << "Failed to send message!";
		return 0; //? idk how to error handle this
	}

	//figure out how to check if all players are ready
	//
	while (true) {
		std::cout << "Console: " << serverOBJ->recieved.front() << "\n> ";
		std::string first = serverOBJ->recieved.front();
		serverOBJ->recieved.erase(serverOBJ->recieved.begin());
		//if (first == "STARTGAME")
	}



	system("pause");
	*updateScreen = false;
	serverOBJ->Terminate(); //garbage collec / termination
	delete serverOBJ;
	delete updateScreen;
}