#include "Game/Ships/ShipTypes/Carrier.hpp"

Carrier::Carrier() :
    m_shipType(ShipType::Carrier)
{}

int Carrier::GetShipSize()
{
    return 0;
}

void Carrier::SetShipOnPosition(int x, int y)
{

}

bool Carrier::IsShipOnPosition(int x, int y)
{
    return false;
}

ShipType Carrier::GetShipType()
{
    return ShipType::Carrier;
}

ShipStatus Carrier::GetShipStatus()
{
    return ShipStatus::OK;
}
