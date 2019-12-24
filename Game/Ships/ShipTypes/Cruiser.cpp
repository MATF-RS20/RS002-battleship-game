#include "Game/Ships/ShipTypes/Cruiser.hpp"

Cruiser::Cruiser()
    : m_shipType(ShipType::CruiserType)
{}

int Cruiser::GetShipSize()
{
    return 0;
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
