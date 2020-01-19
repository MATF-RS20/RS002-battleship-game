#include "Game/Ships/ShipTypes/Battleship.hpp"

Battleship::Battleship(QVector<Position*> coordinates)
    : m_shipType(ShipType::BattleshipType),
      m_shipSize(BATTLESHIP_SIZE)
{
    if(coordinates.size() != BATTLESHIP_SIZE)
    {

    }
    else
    {
        m_shipCoordinates = coordinates;
    }
}

int Battleship::GetShipSize()
{
    return m_shipSize;
}

void Battleship::SetShipOnPosition(int x, int y)
{

}

bool Battleship::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Battleship::GetShipType()
{
    return ShipType::BattleshipType;
}

ShipStatus Battleship::GetShipStatus()
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

QVector<Position*> Battleship::getShipPositions()
{
    return m_shipCoordinates;
}