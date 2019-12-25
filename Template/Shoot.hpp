#ifndef SHOOT_HPP
#define SHOOT_HPP
#include "Game/Board/Position.hpp"

class Shoot
{
public:
    Shoot();
    void SearchPosition();
    Position* getPosition();

private:
    Position* m_position;

};

#endif // SHOOT_HPP
