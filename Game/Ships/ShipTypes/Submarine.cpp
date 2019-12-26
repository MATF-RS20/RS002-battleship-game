#include "Game/Ships/ShipTypes/Submarine.hpp"


Submarine::Submarine() :
    m_shipType(ShipType::SubmarineType),
    m_shipSize(SUBMARINE_SIZE)
{}

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
    return ShipStatus::OK;
}
