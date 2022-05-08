#pragma once
#include "client.h"

struct Connector {
public:
	static std::string connectIP;
	static int port;
	static client* clientOBJ;
	static std::string myIPV4;
};

struct IPv4
{
	unsigned char b1, b2, b3, b4;
};

bool getMyIP(IPv4& myIP);