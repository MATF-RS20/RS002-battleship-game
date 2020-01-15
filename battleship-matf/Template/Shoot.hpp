#ifndef SHOOT_HPP
#define SHOOT_HPP

#include "Game/Board/Position.hpp"

class Shoot
{
public:
    Shoot(int x, int y);
    void SearchPosition();
    Position* getPosition();

private:
    Position* m_position;

};

#endif // SHOOT_HPP
