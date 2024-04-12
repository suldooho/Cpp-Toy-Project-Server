#include "player.h" 

Player::Player(SOCKET clientSocket, SOCKADDR_IN clientAddress) : m_clientSocket(clientSocket), m_id(""), m_playerLocation(PlayerLocation::Lobby), m_score(0)
{
	memcpy(&m_clientAddress, &clientAddress, sizeof(clientAddress)); 
}
