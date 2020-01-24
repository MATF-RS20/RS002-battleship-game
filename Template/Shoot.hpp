#ifndef SHOOT_HPP
#define SHOOT_HPP

#include "Game/Board/Position.hpp"

class Shoot
{
public:
    Shoot(int x, int y);
    Position* getPosition();

private:
    Position* m_position;

};

#endif // SHOOT_HPP
