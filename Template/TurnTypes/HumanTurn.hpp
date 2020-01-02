#ifndef HUMANTURN_HPP
#define HUMANTURN_HPP
#include "Template/Turn.hpp"

class HumanTurn : public Turn
{
protected:
    Shoot* CreateShoot();

};

#endif // HUMANTURN_HPP
