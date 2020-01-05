#include "Template/TurnTypes/ComputerTurn.hpp"

ComputerTurn::ComputerTurn(IPlayer* attacker)
    : m_attacker(attacker)
{

}

Shoot* ComputerTurn::CreateShoot()
{
    QVector<QPair<int, int>> attackedPositions = m_attacker->GetAttackedPositions();
    srand(time(0));
    int randX = 0;
    int randY = 0;
    QPair<int, int> position;
    do {
        randX = rand() % 10;
        randY = rand() % 10;
        position.first = randX;
        position.second = randY;
    } while(attackedPositions.contains(position));

    Shoot* shoot = new Shoot(randX, randY);
    return shoot;
}
