#include "Game/Player/Player.hpp"
#include "Game/Board/Board.hpp"

Player::Player(QString playerName, PlayerType playerType, PlayerStrategy playerStrategy)
    : m_playerName(playerName),
      m_playerType(playerType),
      m_playerStrategy(playerStrategy),
      m_board(new Board()),
      m_attackedPositions()
{
    m_board->InitializeBoard();
    if(playerType == PlayerType::Computer)
        m_board->CreateShips();
}

QString Player::GetPlayerName()
{
    return m_playerName;
}

PlayerType Player::GetPlayerType()
{
    return m_playerType;
}

PlayerStrategy Player::GetPlayerStrategy()
{
    return m_playerStrategy;
}

IBoard* Player::GetBoard()
{
    return m_board;
}

void Player::AddAttackedPosition(QPair<int, int> attackedPosition)
{
    m_attackedPositions.append(attackedPosition);
}

QVector<QPair<int, int>> Player::GetAttackedPositions()
{
    return m_attackedPositions;
}
