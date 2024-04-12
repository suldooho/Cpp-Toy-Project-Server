#include "playerManager.h"

PlayerManager& PlayerManager::getInstance()
{
	static PlayerManager playerManager;
	return playerManager;
}

void PlayerManager::addPlayer(Player* player)
{
	m_players.emplace_back(player);
}
