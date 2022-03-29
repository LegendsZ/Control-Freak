#include "server.h"

server::server(int portG) : port(portG) {

};

bool server::autoStart() {
	initWinsock();
	createSocket();
	bindSocket();
	configSocket();
	startFindConnections();
	return true;
}

bool server::initWinsock() {
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	int wsOk = WSAStartup(ver, &wsData);

	if (wsOk) {
		return false;
	}
	return true;
}

bool server::createSocket() {
	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		return false;
	}
	return true;
}


bool server::bindSocket() {
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(listening, (sockaddr*)&hint, sizeof(hint));
	return true;
}

bool server::configSocket() {
	listen(listening, SOMAXCONN);
	FD_ZERO(&master);
	FD_SET(listening, &master);
	return true;
}

bool server::startFindConnections() {
	isFindingConnections = true;
	findingConnectionsThread = std::thread(&server::findConnectionsLoop, this);
	return true;
}

bool server::endFindConnections() {
	isFindingConnections = false;
	findingConnectionsThread.detach();
	return true;
}

void server::findConnectionsLoop() {
	while (isFindingConnections) {
		fd_set copy = master;
		int socketCnt = select(0, &copy, nullptr, nullptr, nullptr);
		for (int i = 0; i < socketCnt; i++) {
			if (!isFindingConnections) {
				return;
			}
			SOCKET sock = copy.fd_array[i];
			if (sock == listening) {
				//accept new conn

				SOCKADDR_IN client_info = { 0 };
				int addrsize = sizeof(client_info);

				//SOCKET client = accept(listening, nullptr, nullptr);
				SOCKET client = accept(listening, (struct sockaddr*)&client_info, &addrsize);

				//add new conn to list of connected sockets/clients
				FD_SET(client, &master);
				//reply back

				char host[NI_MAXHOST];
				char service[NI_MAXHOST];
				ZeroMemory(host, NI_MAXHOST);
				ZeroMemory(service, NI_MAXHOST);
				if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXHOST, 0) == 0) {
				}
				else {
					inet_ntop(AF_INET, &client_info.sin_addr, host, NI_MAXHOST);
				}

				player* playerOBJ = new player(std::string(host));
				playerList.push_back(playerOBJ);


				//std::string welcomeMSG = "You have joined.";
				//send(client, welcomeMSG.c_str(), welcomeMSG.size() + 1, 0);
			}
		}
	}
}

bool server::startListening() {
	isListening = true;
	listenThread = std::thread(&server::listenLoop, this);
	return true;
}

bool server::endListening() {
	isListening = false;
	listenThread.detach();
	return true;
}

void server::listenLoop() {
	while (isListening) {
		for (int i = 0; i < master.fd_count; i++) {
			SOCKET clientSocket = master.fd_array[i];
			ZeroMemory(buff, 4096);
			int bytesRecieved = recv(clientSocket, buff, 4096, 0);
			if (bytesRecieved == SOCKET_ERROR || bytesRecieved == 0) {
				continue;
			}
			recieved.push_back(getMsg(buff, bytesRecieved));

		}
	}
}

bool server::sendData(int index, std::string msgG) {
	if (index >= 0 && index < playerList.size()) {
		SOCKET clientSocket = master.fd_array[index];
		send(clientSocket, msgG.c_str(), msgG.size() + 1, 0);
		return true;
	}
	else if (index == -1) {
		for (int i = 0; i < playerList.size(); i++) {
			SOCKET clientSocket = master.fd_array[i];
			send(clientSocket, msgG.c_str(), msgG.size() + 1, 0);
		}
		return true;
	}
	return false;
}

bool server::Terminate() {
	WSACleanup();
	return true;
}

std::string server::getMsg(char* buffG, const int length) {
	std::string toRet = "";
	for (int i = 0; i < length; i++) {
		toRet += buffG[i];
	}
	return toRet;
}

int server::getConnectionsCount() {
	return playerList.size();
}