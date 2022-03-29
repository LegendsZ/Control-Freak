#pragma once

#include <WS2tcpip.h>
#include <string>
#include <thread>
#include <vector>
#include "../Data/player.h"

#pragma comment(lib,"WS2_32")

class server {
private:

	SOCKET listening = NULL;
	int port;
	fd_set master;
	char buff[4096];

	std::thread findingConnectionsThread;
	std::thread listenThread;
	bool isFindingConnections = false;
	bool isListening = false;

public:
	std::vector<std::string> recieved;
	std::vector<player*> playerList;

	server(int portG);

	bool autoStart();

	bool initWinsock();

	bool createSocket();

	bool bindSocket();

	bool configSocket();

	bool startFindConnections();

	bool endFindConnections();

	void findConnectionsLoop();

	bool startListening();

	bool endListening();

	void listenLoop();

	bool sendData(int index, std::string msgG);

	bool Terminate();

	std::string getMsg(char* buffG, const int length);

	int getConnectionsCount();
};