#include "Game/Player/Player.hpp"
#include "Game/Board/Board.hpp"

Player::Player(QString playerName, PlayerType playerType, PlayerStrategy playerStrategy)
    : m_mutex(),
      m_playerName(playerName),
      m_playerType(playerType),
      m_playerStrategy(playerStrategy),
      m_board(new Board()),
      m_attackedPositions()
{
    m_board->InitializeBoard();
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

void Player::AddAttackedPosition(std::shared_ptr<Position> attackedPosition)
{
    QMutexLocker lock(&m_mutex);
    m_attackedPositions.append(attackedPosition);
}

QVector<std::shared_ptr<Position>> Player::GetAttackedPositions()
{
    QMutexLocker lock(&m_mutex);
    return m_attackedPositions;
}
