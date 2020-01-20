#include "Game/Ships/ShipTypes/Battleship.hpp"

Battleship::Battleship(QVector<std::shared_ptr<Position>> coordinates)
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

QVector<std::shared_ptr<Position>> Battleship::getShipPositions()
{
    return m_shipCoordinates;
}

void Battleship::UpdateShipPositions(ShipStatus status)
{
    if(status == ShipStatus::Sunken) {
        foreach (std::shared_ptr<Position> shipPosition, m_shipCoordinates) {
            shipPosition->m_status = PositionStatus::Destroyed;
        }
    }
}
