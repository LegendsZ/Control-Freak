/*
	Authors: Akkshai. B, Roland. T
	Date creation: 3/6/2022
	Version: 1.0.0.0
*/
#include <iostream> //debugging/testing purposes
#include "Server/server.h"
const std::string version = "1.0.0.0";


void forAll(server* serverOBJ, std::string toFind) {
	std::vector<std::string> readyIPList;
	while (serverOBJ->getConnectionsCount() > 0 && readyIPList.size() < serverOBJ->getConnectionsCount()) {
		if (serverOBJ->recieved.size() > 0) {
			//std::string abc = serverOBJ->recieved.back();
			if (serverOBJ->recieved.back().find(toFind) != std::string::npos) {
				//std::string blah = serverOBJ->recieved.back();
				std::string tempIP = serverOBJ->recieved.back().substr(0, serverOBJ->recieved.back().size() - toFind.length());
				bool exists = false;
				for (int i = 0; i < readyIPList.size(); i++) {
					if (readyIPList[i] == tempIP) {
						exists = true;
						break;
					}
				}
				if (!exists) {
					readyIPList.push_back(tempIP);
				}
			}
			serverOBJ->recieved.pop_back();
		}
		//maybe a sleep?
	}
}


int main()
{
	std::string titleString = "title Control Freak SERVER v" + version;
	system(titleString.c_str());
	
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


	{
		std::vector<std::string> readyIPList;
		while (serverOBJ->getConnectionsCount() > 0 && readyIPList.size() < serverOBJ->getConnectionsCount()) {
			if (serverOBJ->recieved.size() > 0) {
				if (serverOBJ->recieved.back().find("V") != std::string::npos) {
					std::string tempIP = serverOBJ->recieved.back().substr(0, serverOBJ->recieved.back().find("V")); //serverOBJ->recieved.back().size() - 1
					bool exists = false;
					for (int i = 0; i < readyIPList.size(); i++) {
						if (readyIPList[i] == tempIP) {
							exists = true;
							break;
						}
					}
					if (!exists) {
						std::string clientVersion = serverOBJ->recieved.back().substr(serverOBJ->recieved.back().find("V")+1, std::string::npos); //serverOBJ->recieved.back().size() - 1
						int ind = -1;
						if (clientVersion.compare(version)) {
							for (int i = 0; i < serverOBJ->playerList.size(); i++) {
								if (serverOBJ->playerList[i]->getIP() == tempIP) {
									serverOBJ->sendData(i, "VERSIONGOOD");
									ind = i;
								}
							}
							if (ind == -1) {
								std::cout << "Something went wrong during version check!";
							}
						}
						else {
							serverOBJ->sendData(ind, "VERSIONBAD");
						}
						readyIPList.push_back(tempIP);
					}
				}
				serverOBJ->recieved.pop_back();
			}
			//maybe a sleep?
		}
	}



	forAll(serverOBJ, "ISREADY");
	serverOBJ->sendData(-1, "GAMESTART");
	forAll(serverOBJ, "GAMESTARTED");

	while (serverOBJ->getConnectionsCount() > 0) {
		if (serverOBJ->recieved.size() > 0) {
			std::string s = serverOBJ->recieved.back();
			if (serverOBJ->recieved.back().find("ISDCING") != std::string::npos) {
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