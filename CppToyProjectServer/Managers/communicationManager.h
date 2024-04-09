#pragma once
#include "../Main/headers.h"


class CommunicationManager
{  
public:
	static CommunicationManager& getInstance();

private: 
	CommunicationManager();
    // Test All Constructer Disalbe

private:
	const unsigned int m_port = 2139;

	HANDLE m_completionPort; 
	SOCKET m_serverSocket;

public:
	void initialization();
	void playerAccept();


};

