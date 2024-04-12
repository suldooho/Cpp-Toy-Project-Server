#include "threadManager.h"

ThreadManager& ThreadManager::getInstance()
{
	static ThreadManager threadManager;
	return threadManager;
}

ThreadManager::ThreadManager()
{
}
