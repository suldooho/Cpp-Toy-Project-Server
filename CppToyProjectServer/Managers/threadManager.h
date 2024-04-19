#pragma once 
#include "../Main/headers.h"

class ThreadManager
{
public:
	ThreadManager(HANDLE completionPort);

	ThreadManager() = delete;
	ThreadManager(const ThreadManager&) = delete;
	ThreadManager(ThreadManager&&) = delete;

private:
	std::vector<std::jthread> m_jthreads;

private:
	void work(HANDLE completionPort);
	 
};