#include "Template/Turn.hpp"

bool Turn::Play(IPlayer* attacker, IPlayer* defender)
{
    Shoot* shoot = CreateShoot();
    int x = shoot->getPosition()->m_coordinateX;
    int y = shoot->getPosition()->m_coordinateY;

    attacker->AddAttackedPosition(QPair<int, int>(x, y));
    return ExecuteShoot(attacker, defender, shoot->getPosition());
}

bool Turn::ExecuteShoot(IPlayer* attacker, IPlayer* defender, Position* shootPosition)
{
    bool isHit = false;
    PositionStatus status;

    int x = shootPosition->m_coordinateX;
    int y = shootPosition->m_coordinateY;
    defender->GetBoard()->AttackOnCoordinates(x, y);
    status = defender->GetBoard()->GetPositionStatus(x, y);

    if (status == PositionStatus::Hit)
        isHit = true;

    return isHit;
}
