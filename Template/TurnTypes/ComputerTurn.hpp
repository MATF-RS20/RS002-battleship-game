#ifndef COMPUTERTURN_HPP
#define COMPUTERTURN_HPP
#include "Template/Turn.hpp"

class ComputerTurn : public Turn
{
protected:
    Shoot* CreateShoot();

};

#endif // COMPUTERTURN_HPP
