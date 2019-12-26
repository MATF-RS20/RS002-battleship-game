#include "Game/Ships/ShipTypes/Cruiser.hpp"

Cruiser::Cruiser()
    : m_shipType(ShipType::CruiserType),
      m_shipSize(CRUISER_SIZE)
{}

int Cruiser::GetShipSize()
{
    return m_shipSize;
}

void Cruiser::SetShipOnPosition(int x, int y)
{

}

bool Cruiser::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Cruiser::GetShipType()
{
    return ShipType::CruiserType;
}

ShipStatus Cruiser::GetShipStatus()
{
    return ShipStatus::OK;
}
