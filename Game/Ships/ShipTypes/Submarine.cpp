#include "Game/Ships/ShipTypes/Submarine.hpp"


Submarine::Submarine() :
    m_shipType(ShipType::SubmarineType)
{}

int Submarine::GetShipSize()
{
    return 0;
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
    return ShipStatus::OK;
}
