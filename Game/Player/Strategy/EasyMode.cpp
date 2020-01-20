#include "EasyMode.hpp"
#include <QVector>

EasyMode::EasyMode()
{

}

std::shared_ptr<Position> EasyMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    int randX = 0;
    int randY = 0;
    std::shared_ptr<Position> position = std::make_shared<Position>();

    bool playAgain;
    do {
        playAgain = false;
        randX = qrand() % 10;
        randY = qrand() % 10;

        for(int i=0; i<attackedPositions.size(); ++i) {
            if(attackedPositions[i]->m_coordinateX == randX &&
               attackedPositions[i]->m_coordinateY == randY)
            {
                playAgain = true;
                break;
            }
        }
    } while(playAgain == true);

    position->m_coordinateX = randX;
    position->m_coordinateY = randY;
    attacker->AddAttackedPosition(position);

    return position;
}
