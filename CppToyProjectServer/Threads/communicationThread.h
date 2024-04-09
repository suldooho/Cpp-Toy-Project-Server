#pragma once
#include "../Main/headers.h"

struct ThreadParameters
{
	bool bServerUser; 
};

DWORD WINAPI communicationThread(ThreadParameters threadParameters)
{
	if (threadParameters.bServerUser)
	{


	}

	while (true)
	{
	}
}