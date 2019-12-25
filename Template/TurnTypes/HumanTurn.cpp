#include "Template/TurnTypes/HumanTurn.hpp"

Shoot* HumanTurn::CreateShoot()
{
    Shoot* shoot = new Shoot();
    return shoot;
}
