#ifndef COMPUTERTURN_HPP
#define COMPUTERTURN_HPP

#include "Template/Turn.hpp"
#include <memory>

class ComputerTurn : public Turn
{
public:
    ComputerTurn(std::shared_ptr<IPlayer> attacker);
    Shoot* CreateShoot();

private:
    std::shared_ptr<IPlayer> m_attacker;
};

#endif // COMPUTERTURN_HPP
