#include "Game/Ships/ShipTypes/Destroyer.hpp"

Destroyer::Destroyer(QVector<std::shared_ptr<Position>> coordinates)
    : m_shipType(ShipType::DestroyerType),
      m_shipSize(DESTROYER_SIZE)
{
    if(coordinates.size() != DESTROYER_SIZE)
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

    foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
        if(shipPosition->m_status == PositionStatus::Hit)
            status = ShipStatus::Sunken;
    }

    foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
        if(shipPosition->m_status == PositionStatus::Unknown)
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

QVector<std::shared_ptr<Position>> Destroyer::getShipPositions()
{
    return m_shipCoordinates;
}

void Destroyer::UpdateShipPositions(ShipStatus status)
{
    if(status == ShipStatus::Sunken) {
        foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
            shipPosition->m_status = PositionStatus::Destroyed;
        }
    }
}
