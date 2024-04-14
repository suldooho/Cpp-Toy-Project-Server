#pragma once 
#include "../Main/headers.h"

class ThreadManager
{
public:
	ThreadManager();
	ThreadManager(const ThreadManager&) = delete;
	ThreadManager(ThreadManager&&) = delete;

private:
	std::vector<std::jthread> m_jthreads;

private:
	void work(HANDLE completionPort);

public:
	void initialize(HANDLE completionPort);
};