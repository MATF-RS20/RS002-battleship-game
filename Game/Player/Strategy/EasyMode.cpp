#include "EasyMode.hpp"
#include <QVector>

EasyMode::EasyMode()
{

}

// EasyMode implements strategy that attacks always random positions
std::shared_ptr<Position> EasyMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    // But we remember which positions we have already attacked
    // (Idea for extra easy: We do not remember positions. :D)
    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    int randX = 0;
    int randY = 0;
    std::shared_ptr<Position> position = std::make_shared<Position>();

    // search for next position to attack while chosen random numbers are
    // in already attacked position values
    bool searchAgain;
    do {
        searchAgain = false;
        randX = qrand() % 10;
        randY = qrand() % 10;

        for(int i=0; i<attackedPositions.size(); ++i) {
            if(attackedPositions[i]->m_coordinateX == randX &&
               attackedPositions[i]->m_coordinateY == randY)
            {
                searchAgain = true;
                break;
            }
        }
    } while(searchAgain);

    position->m_coordinateX = randX;
    position->m_coordinateY = randY;
    // remember new attacked position
    attacker->AddAttackedPosition(position);

    return position;
}
