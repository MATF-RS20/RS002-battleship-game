#ifndef CARRIER_HPP
#define CARRIER_HPP

#include "Game/Ships/IShip.hpp"
#include <QVector>

class Carrier : public IShip
{
public:
    Carrier(QVector<Position*> coordinates);

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;
    QVector<Position*> getShipPositions() override;

private:
    ShipType m_shipType;
    int m_shipSize;
    QVector<Position*> m_shipCoordinates;
};

#endif // CARRIER_HPP
