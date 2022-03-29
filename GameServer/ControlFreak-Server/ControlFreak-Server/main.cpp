/*
	Authors: Akkshai. B, Roland. T
	Date creation: 3/6/2022
	Version: 1.0.0.0
*/
#include <iostream> //debugging/testing purposes
#include "Server/server.h"


int main()
{
	system("title SERVER");
	
	std::string portG;
	std::cout << "PORT: ";
	std::getline(std::cin, portG);

	server* serverOBJ = new server(std::stoi(portG));
	

	if (!serverOBJ->autoStart()) {
		return 0; //error handle this
	}
	std::cout << "Once you are done accepting, ";
	system("pause");
	serverOBJ->endFindConnections();
	std::cout << "Stopped accepting clients!\n\n";

	serverOBJ->startListening();

	bool allPlayersReady = false;
	int* readyPlayers = new int();
	*readyPlayers = 0;
	while (serverOBJ->getConnectionsCount() > 0 && !allPlayersReady) {
		if (serverOBJ->recieved.size() > 0) {
			if (serverOBJ->recieved.back().find("ISREADY") != std::string::npos) {
				std::string tempIP = serverOBJ->recieved.back().substr(0, serverOBJ->recieved.back().size() - 8);
				for (int i = 0; i < serverOBJ->playerList.size(); i++) {
					if (serverOBJ->playerList[i]->getIP() == tempIP && !serverOBJ->playerList[i]->isReady()) {
						serverOBJ->playerList[i]->setReady(true);
						*readyPlayers = *readyPlayers + 1;
						break;
					}
				}
				serverOBJ->recieved.pop_back();
				if (*readyPlayers == serverOBJ->playerList.size()) {
					break;
				}
			}
		}
		//maybe a sleep?
	}


	while (serverOBJ->getConnectionsCount() > 0) {
		if (serverOBJ->recieved.size() > 0) {
			if (serverOBJ->recieved.back().find("ISDCING")) {
				std::string tempIP = serverOBJ->recieved.back().substr(0, serverOBJ->recieved.back().size() - 8);
				for (int i = 0; i < serverOBJ->playerList.size(); i++) {
					if (serverOBJ->playerList[i]->getIP() == tempIP) {
						serverOBJ->playerList.erase(serverOBJ->playerList.begin() + i);
						break;
					}
				}
			}
		}
		//maybe a sleep?
	}
	
	system("pause");
	
	//garbage collection
	serverOBJ->Terminate();
	delete serverOBJ;

	return 0;
}