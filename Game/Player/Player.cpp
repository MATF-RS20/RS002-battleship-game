#include "Game/Player/Player.hpp"

Player::Player(QString playerName, PlayerType player)
    : m_playerName(playerName), m_player(player)
{}

QString Player::GetPlayerName()
{
    return "";
}

PlayerType Player::GetPlayerType()
{
    return m_player;
}

IBoard* Player::GetBoard()
{
    return m_board;
}
