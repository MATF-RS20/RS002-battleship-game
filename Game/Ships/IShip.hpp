#ifndef ISHIP_HPP
#define ISHIP_HPP

#include "Game/Board/Position.hpp"
#include <QVector>
#include <memory>

#define CARRIER_SIZE 5
#define BATTLESHIP_SIZE 4
#define CRUISER_SIZE 3
#define SUBMARINE_SIZE 3
#define DESTROYER_SIZE 2

#define UNUSED(x) (void(x))

enum ShipType {
    CarrierType = 0,
    BattleshipType,
    CruiserType,
    SubmarineType,
    DestroyerType
};

enum ShipStatus {
    OK = 0,
    Damaged,
    Sunken
};

class IShip
{
public:
    virtual ~IShip() {}

    virtual int GetShipSize() = 0;
    virtual void SetShipOnPosition(int x, int y) = 0;
    virtual bool IsShipOnPosition(int x, int y) = 0;
    virtual ShipType GetShipType() = 0;
    virtual ShipStatus GetShipStatus() = 0;
    virtual QVector<std::shared_ptr<Position>> getShipPositions() = 0;
 };

#endif // ISHIP_HPP
