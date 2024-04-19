#include "communicationManager.h" 

CommunicationManager::CommunicationManager() 
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

Player* CommunicationManager::playerAccept()
{
	SOCKADDR_IN clientAddress;
	int length = sizeof(clientAddress);
	SOCKET clientSocket = accept(m_serverSocket, (SOCKADDR*)&clientAddress, &length);
	
	Player* player = new Player(clientSocket, clientAddress); 
	
	CreateIoCompletionPort((HANDLE)clientSocket, m_completionPort, (ULONG_PTR)player, 0);

	return player;
}

HANDLE CommunicationManager::getCompletionPort()
{
	return m_completionPort;
}
