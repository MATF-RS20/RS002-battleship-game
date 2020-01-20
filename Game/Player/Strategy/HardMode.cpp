#include "HardMode.hpp"

HardMode::HardMode()
{

}

std::shared_ptr<Position> HardMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    std::shared_ptr<Position> positionToAttack;

    if (attacker->GetAttackedPositions().size() == 0) {
        // Prvi napad je uvek random
        positionToAttack = RandomAttack(attacker);
        return positionToAttack;
    }

    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    for (int i=0; i<attackedPositions.size(); ++i) {
        // Prodji kroz sve prethodne napade i proveri da li postoji neki koji je Hit
        if (attackedPositions[i]->m_status == PositionStatus::Hit) {
            //if(CheckIfPositionIsAttacked)
        }
    }

    return positionToAttack;
}

std::shared_ptr<Position> HardMode::RandomAttack(std::shared_ptr<IPlayer> attacker)
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

bool HardMode::CheckIfPositionIsAttacked(std::shared_ptr<IPlayer> attacker, std::shared_ptr<Position> positionToCheck) {
    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    foreach(auto position, attackedPositions) {
        if (position->m_coordinateX == positionToCheck->m_coordinateX &&
             position->m_coordinateY == positionToCheck->m_coordinateY)
            return true;
    }
    return false;
}

/*bool HardMode::CheckIfNextPositionIsAttacked(std::shared_ptr<IPlayer> attacker, std::shared_ptr<Position> positionToCheck) {
    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    foreach(auto position, attackedPositions) {
        if (position->m_coordinateX == positionToCheck->m_coordinateX &&
             position->m_coordinateY == positionToCheck->m_coordinateY)
            return true;
    }
    return false;
}*/
