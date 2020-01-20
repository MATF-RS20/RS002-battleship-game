#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "Game/Board/IBoard.hpp"
#include <QString>
#include <QPair>
#include <QVector>

enum PlayerType {
    Human = 0,
    Computer
};

enum PlayerStrategy {
    Easy = 0,
    Hard
};

class IPlayer
{
public:
    virtual ~IPlayer() {}

    virtual QString GetPlayerName() = 0;
    virtual PlayerType GetPlayerType() = 0;
    virtual PlayerStrategy GetPlayerStrategy() = 0;
    virtual IBoard* GetBoard() = 0;
    virtual void AddAttackedPosition(std::shared_ptr<Position> attackedPosition) = 0;
    virtual QVector<std::shared_ptr<Position>> GetAttackedPositions() = 0;
};

#endif // IPLAYER_HPP
