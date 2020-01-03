#ifndef COMPUTERTURN_HPP
#define COMPUTERTURN_HPP

#include "Template/Turn.hpp"

class ComputerTurn : public Turn
{
public:
    ComputerTurn();
    Shoot* CreateShoot();
};

#endif // COMPUTERTURN_HPP
