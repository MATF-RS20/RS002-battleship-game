#include "Game/Ships/ShipTypes/Carrier.hpp"

Carrier::Carrier() :
    m_shipType(ShipType::CarrierType)
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
    return ShipType::CarrierType;
}

ShipStatus Carrier::GetShipStatus()
{
    return ShipStatus::OK;
}
