#include "Game/Ships/ShipTypes/Carrier.hpp"

Carrier::Carrier() :
    m_shipType(ShipType::CarrierType),
    m_shipSize(CARRIER_SIZE)
{}

int Carrier::GetShipSize()
{
    return m_shipSize;
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
