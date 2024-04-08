#include "player.h"

Player::Player(std::string ip, std::string id) : m_ip(ip), m_id(id), m_playerLocation(PlayerLocation::Lobby), m_score(0)
{
}
