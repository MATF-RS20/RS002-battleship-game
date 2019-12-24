#include "Game/Ships/ShipTypes/Battleship.hpp"

Battleship::Battleship()
    : m_shipType(ShipType::BattleshipType)
{}


int Battleship::GetShipSize()
{
    return 0;
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

