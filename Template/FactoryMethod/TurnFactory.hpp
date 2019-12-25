#ifndef TURNFACTORY_HPP
#define TURNFACTORY_HPP

#include "Game/Player/IPlayer.hpp"
#include "Turn.hpp"

class TurnFactory
{

public:
    Turn CreateTurn(PlayerType playerType);

};

#endif // TURNFACTORY_HPP
