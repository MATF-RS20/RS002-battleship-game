#ifndef CARRIER_HPP
#define CARRIER_HPP

#include "Game/Ships/IShip.hpp"

class Carrier : public IShip
{
public:
    Carrier();

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;

private:
    ShipType m_shipType;
    int m_shipSize;
};

#endif // CARRIER_HPP
