#ifndef ISHIP_HPP
#define ISHIP_HPP

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
};

#endif // ISHIP_HPP
