#include "Game/Ships/ShipTypes/Cruiser.hpp"

Cruiser::Cruiser(QVector<Position*> coordinates)
    : m_shipType(ShipType::CruiserType),
      m_shipSize(CRUISER_SIZE)
{
    if(coordinates.size() != 3)
    {

    }
    else
    {
        m_shipCoordinates = coordinates;
    }
}

int Cruiser::GetShipSize()
{
    return m_shipSize;
}

void Cruiser::SetShipOnPosition(int x, int y)
{

}

bool Cruiser::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Cruiser::GetShipType()
{
    return ShipType::CruiserType;
}

ShipStatus Cruiser::GetShipStatus()
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

QVector<Position*> Cruiser::getShipPositions()
{
    return m_shipCoordinates;
}
