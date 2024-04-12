#include "communicationManager.h"

CommunicationManager& CommunicationManager::getInstance()
{  
	static CommunicationManager communicationManager;
	return communicationManager; 
}

CommunicationManager::CommunicationManager() : m_completionPort(NULL), m_serverSocket(NULL)
{ 
}

void CommunicationManager::initialization()
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		// Test
	}

	m_completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	m_serverSocket = WSASocket(PF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	//u_long nonBlockingMode = 1;
	//ioctlsocket(m_serverSocket, FIONBIO, &nonBlockingMode); // Test Non Blocking listen socket

	SOCKADDR_IN serverAddress;
	ZeroMemory(&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(m_port);

	bind(m_serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));
	listen(m_serverSocket, SOMAXCONN);
}

void CommunicationManager::playerAccept()
{
	while (true)
	{ 
		SOCKADDR_IN clientAddress;
		int length = sizeof(clientAddress);
		SOCKET clientSocket = accept(m_serverSocket, (SOCKADDR*)&clientAddress, &length);

		Player* player = new Player(clientSocket, clientAddress);
		PlayerManager::getInstance().addPlayer(player);

		CreateIoCompletionPort((HANDLE)clientSocket, m_completionPort, (DWORD)player, 0);
	}
}

HANDLE CommunicationManager::getCompletionPort()
{
	return m_completionPort;
}
