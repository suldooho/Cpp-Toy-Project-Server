#include "headers.h"

int main()
{
	CommunicationManager& communicationManager = CommunicationManager::getInstance();
	communicationManager.initialization();



	communicationManager.playerAccept();
} 