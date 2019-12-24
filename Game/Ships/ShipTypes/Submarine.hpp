#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP

#include "Game/Ships/IShip.hpp";


class Submarine : public IShip
{
public:
    Submarine();

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;


private:
    ShipType m_shipType;

};

#endif // SUBMARINE_HPP
