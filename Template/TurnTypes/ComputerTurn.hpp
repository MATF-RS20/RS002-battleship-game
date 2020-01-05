#ifndef COMPUTERTURN_HPP
#define COMPUTERTURN_HPP

#include "Template/Turn.hpp"

class ComputerTurn : public Turn
{
public:
    ComputerTurn(IPlayer* attacker);
    Shoot* CreateShoot();

private:
    IPlayer* m_attacker;
};

#endif // COMPUTERTURN_HPP
