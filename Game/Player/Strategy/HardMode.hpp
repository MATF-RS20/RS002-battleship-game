#ifndef HARDMODE_H
#define HARDMODE_H

#include "IShootingStrategy.hpp"

class HardMode : public IShootingStrategy
{
public:
    HardMode();

    virtual std::shared_ptr<Position> GetAttackingPosition(std::shared_ptr<IPlayer> attacker) override;

private:
    std::shared_ptr<Position> RandomAttack(std::shared_ptr<IPlayer> attacker);
    bool CheckIfPositionIsAttacked(std::shared_ptr<IPlayer> attacker, std::shared_ptr<Position> positionToCheck);
    bool CheckIfNextPositionIsAttacked(std::shared_ptr<IPlayer> attacker, std::shared_ptr<Position> positionToCheck, std::shared_ptr<Position> &positionToAttack);
};

#endif // HARDMODE_H
