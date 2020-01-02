#include "Game/Ships/ShipTypes/Battleship.hpp"

Battleship::Battleship(QVector<Position*> coordinates)
    : m_shipType(ShipType::BattleshipType),
      m_shipSize(BATTLESHIP_SIZE)
{
    if(coordinates.size() != 4)
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
    return ShipStatus::OK;
}

QVector<Position*> Battleship::getShipPositions()
{
    return m_shipCoordinates;
}
