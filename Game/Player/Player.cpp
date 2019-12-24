#include "Game/Player/Player.hpp"

Player::Player(IBoard* board, PlayerType player)
    : m_board(board), m_player(player)
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
