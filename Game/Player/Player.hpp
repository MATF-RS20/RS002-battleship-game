#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Game/Player/IPlayer.hpp"

class Player : public IPlayer
{
public:
    Player(QString playerName, PlayerType playerType, PlayerStrategy playerStrategy);

    QString GetPlayerName() override;
    PlayerType GetPlayerType() override;
    PlayerStrategy GetPlayerStrategy() override;
    IBoard* GetBoard() override;
    void AddAttackedPosition(QPair<int, int> attackedPosition) override;
    QVector<QPair<int, int>> GetAttackedPositions() override;

private:
    QString m_playerName;
    PlayerType m_playerType;
    PlayerStrategy m_playerStrategy;
    IBoard* m_board;
    QVector<QPair<int, int>> m_attackedPositions;
};

#endif // PLAYER_HPP
