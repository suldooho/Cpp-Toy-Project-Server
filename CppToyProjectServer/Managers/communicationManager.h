#pragma once
#include "../Main/headers.h"

class CommunicationManager
{  
public:
	CommunicationManager();
	CommunicationManager(const CommunicationManager&) = delete;
	CommunicationManager(CommunicationManager&&) = delete;

private:
	const unsigned int m_port = 2139;

	HANDLE m_completionPort; 
	SOCKET m_serverSocket;

public:
	HANDLE initialize();
	Player* playerAccept();
	HANDLE getCompletionPort();

};

