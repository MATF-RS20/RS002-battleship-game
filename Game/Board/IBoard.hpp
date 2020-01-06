#ifndef IBOARD_HPP
#define IBOARD_HPP

#include "Game/Ships/IShip.hpp"
#include "Game/Board/Position.hpp"
#include <QVector>

class IBoard
{
public:
    virtual ~IBoard() {}

    virtual void InitializeBoard() = 0;
    virtual void CreateShips() = 0;
    virtual void SetShipOnPositions(ShipType ship, QVector<QPair<int, int>> positions) = 0;
    virtual int NumberOfAvailableShips() = 0;
    virtual void AttackOnCoordinates(int x, int y) = 0;
    virtual PositionStatus GetPositionStatus(int x, int y) = 0;
    virtual QVector<IShip*> GetShips() = 0;
};

#endif // IBOARD_HPP
