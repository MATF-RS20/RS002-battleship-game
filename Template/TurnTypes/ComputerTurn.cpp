#include "Template/TurnTypes/ComputerTurn.hpp"

Shoot* ComputerTurn::CreateShoot()
{
    Shoot* shoot = new Shoot();
    return shoot;
}
