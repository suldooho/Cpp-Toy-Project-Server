#pragma once 
#include "../Main/headers.h"

class ThreadManager
{
public:
	static ThreadManager& getInstance();

private:
	ThreadManager();

private:
	std::vector<std::jthread> jthreads;
};