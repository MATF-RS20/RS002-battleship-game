#ifndef CRUISER_HPP
#define CRUISER_HPP

#include "Game/Ships/IShip.hpp"
#include <QVector>

class Cruiser: public IShip
{
public:
    Cruiser(QVector<Position*> coordinates);

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

#endif // CRUISER_HPP