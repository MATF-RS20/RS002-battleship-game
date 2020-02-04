#include "Game/Ships/ShipTypes/Cruiser.hpp"

Cruiser::Cruiser(QVector<std::shared_ptr<Position>> coordinates)
    : m_shipType(ShipType::CruiserType),
      m_shipSize(CRUISER_SIZE)
{
    if(coordinates.size() != CRUISER_SIZE)
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
    UNUSED(x);
    UNUSED(y);

}

bool Cruiser::IsShipOnPosition(int x, int y)
{
    UNUSED(x);
    UNUSED(y);

    return false;
}

ShipType Cruiser::GetShipType()
{
    return ShipType::CruiserType;
}

ShipStatus Cruiser::GetShipStatus()
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

QVector<std::shared_ptr<Position>> Cruiser::getShipPositions()
{
    return m_shipCoordinates;
}

void Cruiser::UpdateShipPositions(ShipStatus status)
{
    if(status == ShipStatus::Sunken) {
        foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
            shipPosition->m_status = PositionStatus::Destroyed;
        }
    }
}
