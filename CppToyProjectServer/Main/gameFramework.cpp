#include "GameFramework.h"

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}

GameFramework::GameFramework()
{
	m_communicationManager = std::make_unique<CommunicationManager>();
	m_threadManager = std::make_unique<ThreadManager>(m_communicationManager->getCompletionPort());
	m_playerManager = std::make_unique<PlayerManager>(); 
}

void GameFramework::run()
{
	// Test
	while (true)
	{ 
		Player* player = m_communicationManager->playerAccept();
		m_playerManager->addPlayer(player);
	} 
}
