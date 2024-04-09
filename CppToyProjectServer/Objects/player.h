#pragma once
#include "../Main/headers.h"

enum class PlayerLocation
{
	Lobby,
	Playing
};

struct HandleData
{
	SOCKET clientSocket;
	SOCKADDR_IN clientAddress;
};

class Player
{  
private:
	HandleData m_handleData;

private:
	std::string m_id;

	PlayerLocation m_playerLocation;

	unsigned int m_score;
};

