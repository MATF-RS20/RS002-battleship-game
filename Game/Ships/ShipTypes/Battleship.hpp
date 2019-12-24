#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "Game/Ships/IShip.hpp"

class Battleship : public IShip
{
public:
    Battleship();

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;

private:
    ShipType m_shipType;
};

#endif // BATTLESHIP_HPP
