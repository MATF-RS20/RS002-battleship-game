#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP

#include "Game/Ships/IShip.hpp";
#include <QVector>


class Submarine : public IShip
{
public:
    Submarine(QVector<Position*> coordinates);

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

#endif // SUBMARINE_HPP
