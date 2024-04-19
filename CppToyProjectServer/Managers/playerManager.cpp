#include "playerManager.h" 

PlayerManager::PlayerManager()
{
} 

void PlayerManager::addPlayer(Player* player)
{
	m_players.emplace_back(player);
}
