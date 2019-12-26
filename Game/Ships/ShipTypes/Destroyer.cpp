#include "Game/Ships/ShipTypes/Destroyer.hpp"

Destroyer::Destroyer()
    : m_shipType(ShipType::DestroyerType),
      m_shipSize(DESTROYER_SIZE)
{}


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
    return ShipStatus::OK;
}
