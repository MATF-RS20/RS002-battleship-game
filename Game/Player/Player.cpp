#include "Game/Player/Player.hpp"
#include "Game/Board/Board.hpp"

Player::Player(QString playerName, PlayerType playerType)
    : m_playerType(playerType),
      m_playerName(playerName),
      m_board(new Board())
{
    m_board->InitializeBoard();
}

QString Player::GetPlayerName()
{
    return m_playerName;
}

PlayerType Player::GetPlayerType()
{
    return m_playerType;
}

IBoard* Player::GetBoard()
{
    return m_board;
}
