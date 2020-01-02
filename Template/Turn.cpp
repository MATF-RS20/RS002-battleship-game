#include "Template/Turn.hpp"

bool Turn::Play(IPlayer* attacker, IPlayer* defender, Shoot* shoot)
{
    bool isHit = false;
    PositionStatus status;

    int x = shoot->getPosition()->m_coordinateX;
    int y = shoot->getPosition()->m_coordinateY;

    defender->GetBoard()->AttackOnCoordinates(x, y);
    status = defender->GetBoard()->GetPositionStatus(x, y);

    if (status == PositionStatus::Hit)
        isHit = true;

    return isHit;
}

Shoot* Turn::CreateShoot()
{
    return new Shoot(0, 0);
}

bool Turn::ExecuteShoot(IPlayer* attacker, IPlayer* defender, Position* shootPosition)
{
    return true;
}
