#include "Game/Ships/ShipTypes/Carrier.hpp"

Carrier::Carrier(QVector<std::shared_ptr<Position>> coordinates) :
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

    foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
        if(shipPosition->m_status == PositionStatus::Hit)
            status = ShipStatus::Damaged;
    }

    bool shipIsDestroyed = true;
    foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
        if(shipPosition->m_status != PositionStatus::Hit) {
            shipIsDestroyed = false;
        }
    }
    if (shipIsDestroyed)
        status = ShipStatus::Sunken;

    UpdateShipPositions(status);
    return status;
}

QVector<std::shared_ptr<Position>> Carrier::getShipPositions()
{
    return m_shipCoordinates;
}

void Carrier::UpdateShipPositions(ShipStatus status)
{
    if(status == ShipStatus::Sunken) {
        foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
            shipPosition->m_status = PositionStatus::Destroyed;
        }
    }
}
