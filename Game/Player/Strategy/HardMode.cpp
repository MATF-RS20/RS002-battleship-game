#include "HardMode.hpp"

HardMode::HardMode()
{

}

// HardMode has a more serious strategy: It remebers positions that are already hit
// and then searches for positions nearby to attack
std::shared_ptr<Position> HardMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    std::shared_ptr<Position> positionToAttack;
    // If it's the first move
    if (attacker->GetAttackedPositions().size() == 0) {
        // First attack is always random
        positionToAttack = RandomAttack(attacker);
        return positionToAttack;
    }

    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    for (int i=0; i<attackedPositions.size(); ++i) {
        // Go through every attacked position and check if any is hit (not miss)
        if (attackedPositions[i]->m_status == PositionStatus::Hit) {
            // Then check if there is some position nearby that has not been attacked already
            if(CheckIfNextPositionIsAttacked(attacker, attackedPositions[i], positionToAttack) == false) {                
                return positionToAttack;
            }
        }
    }

    positionToAttack = RandomAttack(attacker);
    return positionToAttack;
}

// Same as in EasyMode - searches for random position to attack, but not the
// the ones which are already hit
std::shared_ptr<Position> HardMode::RandomAttack(std::shared_ptr<IPlayer> attacker)
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

    return position;
}

// Checks if given position has been attacked - if it's in vector of attacked positions
bool HardMode::CheckIfPositionIsAttacked(std::shared_ptr<IPlayer> attacker, std::shared_ptr<Position> positionToCheck) {
    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    foreach(auto position, attackedPositions) {
        if (position->m_coordinateX == positionToCheck->m_coordinateX &&
             position->m_coordinateY == positionToCheck->m_coordinateY)
            return true;
    }
    return false;
}

bool HardMode::CheckIfNextPositionIsAttacked(std::shared_ptr<IPlayer> attacker, std::shared_ptr<Position> positionToCheck,
                                             std::shared_ptr<Position>& positionToAttack) {
    QVector<std::shared_ptr<Position>> attackedPositions = attacker->GetAttackedPositions();
    foreach(auto position, attackedPositions) {
            // check if position in the next row has been attacked
            if(positionToCheck->m_coordinateX+1<10)
                if (position->m_coordinateX != positionToCheck->m_coordinateX+1) {
                    // make new position to attack from this neighbor
                    positionToAttack = std::make_shared<Position>(positionToCheck->m_coordinateX+1, positionToCheck->m_coordinateY,
                                                                  PositionStatus::Unknown, AvailabilityStatus::Busy);
                    if(CheckIfPositionIsAttacked(attacker, positionToAttack) == false)
                       return false;
                }
            // check if position in the previous row has been attacked
            if(positionToCheck->m_coordinateX-1>=0)
                if (position->m_coordinateX != positionToCheck->m_coordinateX-1) {
                    positionToAttack = std::make_shared<Position>(positionToCheck->m_coordinateX-1, positionToCheck->m_coordinateY,
                                                                  PositionStatus::Unknown, AvailabilityStatus::Busy);
                    if(CheckIfPositionIsAttacked(attacker, positionToAttack) == false)
                        return false;
                }
            // check if position in the next column has been attacked
            if(positionToCheck->m_coordinateY+1<10)
                if (position->m_coordinateY != positionToCheck->m_coordinateY+1) {
                    positionToAttack = std::make_shared<Position>(positionToCheck->m_coordinateX, positionToCheck->m_coordinateY+1,
                                                                  PositionStatus::Unknown, AvailabilityStatus::Busy);
                    if(CheckIfPositionIsAttacked(attacker, positionToAttack) == false)
                        return false;
                }
            // check if position in the previous column has been attacked
            if(positionToCheck->m_coordinateY-1>=0)
                if (position->m_coordinateY != positionToCheck->m_coordinateY-1) {
                    positionToAttack = std::make_shared<Position>(positionToCheck->m_coordinateX, positionToCheck->m_coordinateY-1,
                                                                  PositionStatus::Unknown, AvailabilityStatus::Busy);
                    if(CheckIfPositionIsAttacked(attacker, positionToAttack) == false)
                        return false;
                }
    }
    return true;
}
