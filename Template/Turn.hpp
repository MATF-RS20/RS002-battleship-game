#ifndef TURN_HPP
#define TURN_HPP

#include "Game/Player/IPlayer.hpp"
#include "Game/Board/Position.hpp"
#include "Template/Shoot.hpp"
#include <memory>

class Turn
{
public:
    bool Play(std::shared_ptr<IPlayer> attacker, std::shared_ptr<IPlayer> defender);

    virtual std::shared_ptr<Shoot> CreateShoot() {}

private:
    bool ExecuteShoot(std::shared_ptr<IPlayer> attacker, std::shared_ptr<IPlayer> defender, std::shared_ptr<Position> attackedPosition);

};

#endif // TURN_HPP
