#pragma once
#include "../Main/headers.h"

struct ThreadParameters
{
	bool isServerUser; 
};

DWORD WINAPI communicationThread(ThreadParameters threadParameters)
{
	if (threadParameters.isServerUser)
	{
		SOCKET serverSocket = WSASocket(PF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
		u_long nonBlockingMode = 1;
		ioctlsocket(serverSocket, FIONBIO, &nonBlockingMode); // Non Blocking listen socket

		SOCKADDR_IN serverAddress;
		ZeroMemory(&serverAddress, sizeof(serverAddress));
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
		serverAddress.sin_port = htons(1959); // Test 

		bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));
		listen(serverSocket, SOMAXCONN);
	}

	while (true)
	{
	}
}