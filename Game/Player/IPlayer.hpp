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

class IPlayer
{
public:
    virtual ~IPlayer() {}

    virtual QString GetPlayerName() = 0;
    virtual PlayerType GetPlayerType() = 0;
    virtual IBoard* GetBoard() = 0;
    virtual void AddAttackedPosition(QPair<int, int> attackedPosition) = 0;
    virtual QVector<QPair<int, int>> GetAttackedPositions() = 0;
};

#endif // IPLAYER_HPP
