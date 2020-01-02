#include "Game/Ships/ShipTypes/Destroyer.hpp"

Destroyer::Destroyer(QVector<Position*> coordinates)
    : m_shipType(ShipType::DestroyerType),
      m_shipSize(DESTROYER_SIZE)
{
    if(coordinates.size() != 2)
    {

    }
    else
    {
        m_shipCoordinates = coordinates;
    }
}


int Destroyer::GetShipSize()
{
    return m_shipSize;
}

void Destroyer::SetShipOnPosition(int x, int y)
{

}

bool Destroyer::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Destroyer::GetShipType()
{
    return ShipType::DestroyerType;
}

ShipStatus Destroyer::GetShipStatus()
{
    ShipStatus status = ShipStatus::OK;

    foreach (Position* shipPosition, m_shipCoordinates) {
        if(shipPosition->m_status == PositionStatus::Hit)
            status = ShipStatus::Sunken;
    }

    foreach (Position* shipPosition, m_shipCoordinates) {
        if(shipPosition->m_status == PositionStatus::Unknown)
            status = ShipStatus::Damaged;
    }

    return status;
}

QVector<Position*> Destroyer::getShipPositions()
{
    return m_shipCoordinates;
}
