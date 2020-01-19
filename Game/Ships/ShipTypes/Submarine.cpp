#include "Game/Ships/ShipTypes/Submarine.hpp"

Submarine::Submarine(QVector<std::shared_ptr<Position>> coordinates) :
    m_shipType(ShipType::SubmarineType),
    m_shipSize(SUBMARINE_SIZE)
{
    if(coordinates.size() != SUBMARINE_SIZE)
    {

    }
    else
    {
        m_shipCoordinates = coordinates;
    }
}

int Submarine::GetShipSize()
{
    return m_shipSize;
}

void Submarine::SetShipOnPosition(int x, int y)
{

}

bool Submarine::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Submarine::GetShipType()
{
    return ShipType::SubmarineType;
}

ShipStatus Submarine::GetShipStatus()
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

    return status;
}

QVector<std::shared_ptr<Position>> Submarine::getShipPositions()
{
    return m_shipCoordinates;
}
