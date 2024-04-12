#pragma once 
#include "../Main/headers.h"

class ThreadManager
{
public:
	static ThreadManager& getInstance();

private:
	ThreadManager();

public:
	ThreadManager(const ThreadManager&) = delete;
	ThreadManager(ThreadManager&&) = delete;

private:
	std::vector<std::jthread> m_jthreads;

private:
	void work();

public:
	void initialization();
};