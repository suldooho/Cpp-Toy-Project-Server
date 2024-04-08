#pragma once
#include "../Main/headers.h"

enum class PlayerLocation
{
	Lobby,
	Playing
};

class Player
{
public:
	Player() = delete;
	Player(std::string ip, std::string id);

private:
	std::string m_ip;
	std::string m_id;

	PlayerLocation m_playerLocation;

	unsigned int m_score;
};

