#pragma once
#include "../Main/headers.h"

enum class PlayerLocation
{
	Lobby,
	Playing
}; 

struct InputOutputData
{
	OVERLAPPED overlapped;
	WSABUF wsaBuffer;
	byte buffer[100]; // Test
};

class Player
{  
private:
	SOCKET m_clientSocket;
	SOCKADDR_IN m_clientAddress;

private:
	std::string m_id;

	PlayerLocation m_playerLocation;

	unsigned int m_score;

public:
	Player() = delete;
	Player(const Player&) = delete;
	Player(Player&&) = delete;

	Player(SOCKET clientSocket, SOCKADDR_IN clientAddress);
};

