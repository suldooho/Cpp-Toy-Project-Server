#pragma once
#include "../Main/headers.h"
  
std::vector<HANDLE> createThreades()
{
	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);
	CommunicationManager& communicationManager = CommunicationManager::getInstance();
	std::vector<HANDLE> handles;

	for (int i = 0; i < systemInfo.dwNumberOfProcessors; ++i)
	{
		HANDLE handle = (HANDLE)_beginthreadex(NULL, 0, communicationThread, NULL, 0, NULL); // Test
		handles.emplace_back(handle);
	}

	return handles;
}

void terminateThreades(std::vector<HANDLE> handles)
{
	for (auto& handle : handles)
	{
		CloseHandle(handle);
	}  
}

unsigned __stdcall communicationThread(LPVOID param)
{  
	while (true)
	{
	}
}