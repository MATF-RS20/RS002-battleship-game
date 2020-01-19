#ifndef COMPUTERTURN_HPP
#define COMPUTERTURN_HPP

#include "Template/Turn.hpp"
#include "Game/Player/Strategy/IShootingStrategy.hpp"
#include <memory>

class ComputerTurn : public Turn
{
public:
    ComputerTurn(std::shared_ptr<IPlayer> attacker);
    std::shared_ptr<Shoot> CreateShoot();

private:
    std::shared_ptr<IPlayer> m_attacker;
    std::shared_ptr<IShootingStrategy> m_strategy;
};

#endif // COMPUTERTURN_HPP
