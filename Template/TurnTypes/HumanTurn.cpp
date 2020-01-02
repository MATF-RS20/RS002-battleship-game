#include "Template/TurnTypes/HumanTurn.hpp"

Shoot* HumanTurn::CreateShoot()
{
    Shoot* shoot = new Shoot(0, 0);
    return shoot;
}
