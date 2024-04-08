#pragma once
#include "../Main/headers.h"

class PlayerManager
{
private:
    static PlayerManager* m_instance;

    PlayerManager* getInstance()
    {
        if (!m_instance)
        {
            m_instance = this;
        }

        return m_instance;
    }

private:
    std::vector<Player> players;



};

