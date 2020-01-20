#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game/Player/IPlayer.hpp"
#include <QMutexLocker>
#include <memory>

class Player : public IPlayer
{
public:
    Player(QString playerName, PlayerType playerType, PlayerStrategy playerStrategy);

    QString GetPlayerName() override;
    PlayerType GetPlayerType() override;
    PlayerStrategy GetPlayerStrategy() override;
    IBoard* GetBoard() override;

    void AddAttackedPosition(std::shared_ptr<Position> attackedPosition) override;
    QVector<std::shared_ptr<Position>> GetAttackedPositions() override;

private:
    QMutex m_mutex;
    QString m_playerName;
    PlayerType m_playerType;
    PlayerStrategy m_playerStrategy;
    IBoard* m_board;
    QVector<std::shared_ptr<Position>> m_attackedPositions;
};

#endif // PLAYER_HPP
