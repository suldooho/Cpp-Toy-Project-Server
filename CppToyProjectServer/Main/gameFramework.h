#pragma once
#include "../Main/headers.h"

class GameFramework
{
public:
    static GameFramework& getInstance();

private:
    GameFramework();

public:
    GameFramework(const GameFramework&) = delete;
    GameFramework(GameFramework&&) = delete;

private:
    std::unique_ptr<class CommunicationManager> m_communicationManager;
    std::unique_ptr<class ThreadManager> m_threadManager;
    std::unique_ptr<class PlayerManager> m_playerManager;

public: 
    void run();
};


