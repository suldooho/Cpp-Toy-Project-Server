#include "threadManager.h" 

ThreadManager& ThreadManager::getInstance()
{
	static ThreadManager threadManager;
	return threadManager;
}

ThreadManager::ThreadManager()
{
}

void ThreadManager::work()
{
	HANDLE completionPort = CommunicationManager::getInstance().getCompletionPort();
	DWORD bytesSize;
	Player* player;
	InputOutputData* inputOutputData;
	
	GetQueuedCompletionStatus(completionPort, &bytesSize, (PULONG_PTR)&player, (LPOVERLAPPED*)&inputOutputData, INFINITE);
}

void ThreadManager::initialization()
{
	unsigned int threadCount = std::thread::hardware_concurrency();

	for (unsigned int i = 0; i < threadCount; ++i)
	{ 
		m_jthreads.emplace_back(std::jthread(&ThreadManager::work, this));
	}
}
