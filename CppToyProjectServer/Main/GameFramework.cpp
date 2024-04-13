#include "GameFramework.h"

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}