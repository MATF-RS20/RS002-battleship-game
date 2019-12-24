#ifndef CRUISER_HPP
#define CRUISER_HPP

#include "Game/Ships/IShip.hpp"

class Cruiser: public IShip
{
public:
    Cruiser();

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;


private:
    ShipType m_shipType;

};

#endif // CRUISER_HPP
