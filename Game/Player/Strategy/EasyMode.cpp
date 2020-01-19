#include "EasyMode.hpp"
#include <QVector>

EasyMode::EasyMode()
{

}

QPair<int, int> EasyMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    QVector<QPair<int, int>> attackedPositions = attacker->GetAttackedPositions();
    int randX = 0;
    int randY = 0;
    QPair<int, int> position;
    do {
        randX = qrand() % 10;
        randY = qrand() % 10;
        position.first = randX;
        position.second = randY;
    } while(attackedPositions.contains(position));

    return QPair<int, int>(randX, randY);
}
