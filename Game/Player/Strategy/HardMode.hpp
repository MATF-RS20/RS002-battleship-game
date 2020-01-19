#ifndef HARDMODE_H
#define HARDMODE_H

#include "IShootingStrategy.hpp"

class HardMode : public IShootingStrategy
{
public:
    HardMode();

    virtual QPair<int, int> GetAttackingPosition(std::shared_ptr<IPlayer> attacker) override;
};

#endif // HARDMODE_H
