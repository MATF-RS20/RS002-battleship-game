#include "Template/Turn.hpp"

// We implement Play and ExecuteShoot method here because they are the same
// for HumanTurn and ComputerTurn
bool Turn::Play(std::shared_ptr<IPlayer> attacker, std::shared_ptr<IPlayer> defender)
{

    std::shared_ptr<Shoot> shoot = CreateShoot();
    int x = shoot->getPosition()->m_coordinateX;
    int y = shoot->getPosition()->m_coordinateY;

    // We want to remember which positions are already attacked
    std::shared_ptr<Position> attackedPosition = std::make_shared<Position>(x, y, PositionStatus::Unknown, AvailabilityStatus::Busy);
    // so we add them to attacked positions vector
    attacker->AddAttackedPosition(attackedPosition);
    // we execute shoot and return if its hit or miss
    return ExecuteShoot(defender, attackedPosition);
}

bool Turn::ExecuteShoot(std::shared_ptr<IPlayer> defender, std::shared_ptr<Position> attackedPosition)
{
    bool isHit = false;
    PositionStatus status;

    int x = attackedPosition->m_coordinateX;
    int y = attackedPosition->m_coordinateY;
    // we change position status here
    defender->GetBoard()->AttackOnCoordinates(x, y);
    // and check if it's hit or miss
    status = defender->GetBoard()->GetPositionStatus(x, y);

    // if it's hit we return true value so the player can play again
    if (status == PositionStatus::Hit) {
        isHit = true;
        // also we change postion status of positions we need to remember
        attackedPosition->m_status = PositionStatus::Hit;
    } else {
        attackedPosition->m_status = PositionStatus::Miss;
    }

    return isHit;
}
