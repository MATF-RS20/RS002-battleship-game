#ifndef IBOARD_HPP
#define IBOARD_HPP

#include "Game/Ships/IShip.hpp"
#include <QVector>

enum PositionStatus
{
    Unknown = 0,
    Hit,
    Miss
};

class IBoard
{
public:
    virtual ~IBoard() {}

    virtual void InitializeBoard() = 0;
    virtual void CreateShips(int x, int y);
    virtual void PlaceShips(int x, int y);
    virtual int NumberOfAvailableShips() = 0;
    virtual void SetXYStatus(int x, int y, PositionStatus xyStatus);
    virtual QVector<IShip> GetShips() = 0;
};

#endif // IBOARD_HPP
