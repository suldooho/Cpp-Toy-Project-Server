#pragma once
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
};

