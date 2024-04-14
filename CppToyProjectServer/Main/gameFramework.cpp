#include "GameFramework.h"

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}

GameFramework::GameFramework()
{
	m_communicationManager = std::make_unique<CommunicationManager>();
	m_threadManager = std::make_unique<ThreadManager>();
	m_playerManager = std::make_unique<PlayerManager>();


	HANDLE completionPort = m_communicationManager->initialize();
	m_threadManager->initialize(completionPort);
	m_playerManager->initialize();
}
