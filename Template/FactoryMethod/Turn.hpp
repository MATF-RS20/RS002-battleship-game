#ifndef TURN_HPP
#define TURN_HPP
#include "Game/Player/IPlayer.hpp"
#include "Game/Board/Position.hpp"
#include "Template/Shoot.hpp"

class Turn
{
public:
    bool Play(IPlayer* attacker, IPlayer* defender);

protected:
    Shoot* CreateShoot();

private:
    bool ExecuteShoot(IPlayer* attacker, IPlayer* defender, Position* shootPosition);

};

#endif // TURN_HPP
