#include "Game/Ships/ShipTypes/Carrier.hpp"

Carrier::Carrier(QVector<Position*> coordinates) :
    m_shipType(ShipType::CarrierType),
    m_shipSize(CARRIER_SIZE)
{
    if(coordinates.size() != CARRIER_SIZE)
    {

    }
    else
    {
        m_shipCoordinates = coordinates;
    }
}

int Carrier::GetShipSize()
{
    return m_shipSize;
}

void Carrier::SetShipOnPosition(int x, int y)
{

}

bool Carrier::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Carrier::GetShipType()
{
    return ShipType::CarrierType;
}

ShipStatus Carrier::GetShipStatus()
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


QVector<Position*> Carrier::getShipPositions()
{
    return m_shipCoordinates;
}
