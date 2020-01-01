#ifndef IBOARD_HPP
#define IBOARD_HPP

#include "Game/Ships/IShip.hpp"
#include "Game/Board/Position.hpp"
#include <QVector>

struct ShipCoordinates {

    ShipCoordinates(IShip* ship, QVector<Position*> coordinates)
    {
        m_ship = ship;
        m_coordinates = coordinates;
    }

    IShip* m_ship;
    QVector<Position*> m_coordinates;
};

class IBoard
{
public:
    virtual ~IBoard() {}

    virtual void InitializeBoard() = 0;
    virtual void CreateShips() = 0;
    virtual void PlaceShips(int x, int y) = 0;
    virtual int NumberOfAvailableShips() = 0;
    virtual void AttackOnCoordinates(int x, int y) = 0;
    virtual QVector<ShipCoordinates*> GetShips() = 0;
};

#endif // IBOARD_HPP
