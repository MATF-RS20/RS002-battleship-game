#include "Template/Turn.hpp"

bool Turn::Play(IPlayer* attacker, IPlayer* defender)
{
    return true;
}

Shoot* Turn::CreateShoot()
{
    return new Shoot();
}

bool Turn::ExecuteShoot(IPlayer* attacker, IPlayer* defender, Position* shootPosition)
{
    return true;
}
