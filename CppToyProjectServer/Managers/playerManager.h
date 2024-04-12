#pragma once
#include "../Main/headers.h"

class PlayerManager
{
public:
    static PlayerManager& getInstance();

private:
    PlayerManager();

public:
    PlayerManager(const PlayerManager&) = delete;
    PlayerManager(PlayerManager&&) = delete;
     
private:
    std::vector<std::unique_ptr<Player>> m_players;

public:
    void addPlayer(Player* player);

};

