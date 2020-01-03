#include "Template/TurnTypes/ComputerTurn.hpp"

ComputerTurn::ComputerTurn()
{

}

Shoot* ComputerTurn::CreateShoot()
{
    Shoot* shoot = new Shoot(0, 0);
    return shoot;
}
