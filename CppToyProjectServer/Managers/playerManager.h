#pragma once
#include "../Main/headers.h"

class PlayerManager
{
public:
    PlayerManager();
    PlayerManager(const PlayerManager&) = delete;
    PlayerManager(PlayerManager&&) = delete;
     
private:
    std::vector<std::unique_ptr<class Player>> m_players;
     
public:
    void initialize();
    void addPlayer(Player* player);

};

