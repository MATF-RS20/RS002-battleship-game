#include "Template/Shoot.hpp"

Shoot::Shoot(int x, int y) :
    m_position(new Position(x, y, PositionStatus::Unknown, AvailabilityStatus::Available))
{}

Position* Shoot::getPosition()
{
    return m_position;
}
