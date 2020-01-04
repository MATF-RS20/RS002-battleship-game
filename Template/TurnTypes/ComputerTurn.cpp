#include "Template/TurnTypes/ComputerTurn.hpp"

ComputerTurn::ComputerTurn()
{

}

Shoot* ComputerTurn::CreateShoot()
{
    srand(time(0));
    int randX = rand() % 10;
    int randY = rand() % 10;
    Shoot* shoot = new Shoot(randX, randY);
    return shoot;
}
