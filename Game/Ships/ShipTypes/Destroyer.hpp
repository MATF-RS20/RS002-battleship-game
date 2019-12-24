#ifndef DESTROYER_HPP
#define DESTROYER_HPP

#include "Game/Ships/IShip.hpp"

class Destroyer : public IShip
{
public:
    Destroyer();

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;

private:
    ShipType m_shipType;

};


#endif // DESTROYER_HPP
