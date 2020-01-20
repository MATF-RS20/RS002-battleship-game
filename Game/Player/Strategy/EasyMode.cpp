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

    bool playAgain = false;
    do {
        randX = qrand() % 10;
        randY = qrand() % 10;
        position->m_coordinateX = randX;
        position->m_coordinateY = randY;

        for(int i=0; i<attackedPositions.size(); ++i) {
            if(attackedPositions[i]->m_coordinateX != position->m_coordinateX ||
               attackedPositions[i]->m_coordinateY != position->m_coordinateY)
            {
                playAgain = false;
                break;
            }
            playAgain = true;
        }
        position->m_status = PositionStatus::Hit;

    } while(playAgain == true);

    return position;
}
