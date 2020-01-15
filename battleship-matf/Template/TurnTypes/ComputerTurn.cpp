#include "Template/TurnTypes/ComputerTurn.hpp"
#include <QTime>

ComputerTurn::ComputerTurn(std::shared_ptr<IPlayer> attacker)
    : m_attacker(attacker)
{

}

Shoot* ComputerTurn::CreateShoot()
{
    QVector<QPair<int, int>> attackedPositions = m_attacker->GetAttackedPositions();
    int randX = 0;
    int randY = 0;
    QPair<int, int> position;
    do {
        randX = qrand() % 10;
        randY = qrand() % 10;
        position.first = randX;
        position.second = randY;
    } while(attackedPositions.contains(position));

    Shoot* shoot = new Shoot(randX, randY);
    return shoot;
}