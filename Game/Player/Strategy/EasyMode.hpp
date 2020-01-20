#ifndef EASYMODE_H
#define EASYMODE_H

#include "IShootingStrategy.hpp"

class EasyMode : public IShootingStrategy
{
public:
    EasyMode();

    virtual std::shared_ptr<Position> GetAttackingPosition(std::shared_ptr<IPlayer> attacker) override;
};

#endif // EASYMODE_H
