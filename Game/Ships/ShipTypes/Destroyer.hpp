#ifndef DESTROYER_HPP
#define DESTROYER_HPP

#include "Game/Ships/IShip.hpp"
#include <QVector>
#include "Game/Board/Position.hpp"


class Destroyer : public IShip
{
public:
    Destroyer(QVector<Position*> coordinates);

    int GetShipSize() override;
    void SetShipOnPosition(int x, int y) override;
    bool IsShipOnPosition(int x, int y) override;
    ShipType GetShipType() override;
    ShipStatus GetShipStatus() override;

private:
    ShipType m_shipType;
    int m_shipSize;
    QVector<Position*> m_shipCoordinates;
};


#endif // DESTROYER_HPP
