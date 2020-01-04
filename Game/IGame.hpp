#ifndef IGAME_HPP
#define IGAME_HPP

#include "Game/Player/IPlayer.hpp"

enum GameState
{
    InProgress,
    GameOver
};


class IGame
{
public:
    virtual ~IGame() {}
    virtual bool AttackBy(IPlayer* player) = 0;
    virtual GameState GetGameState() = 0;

};

#endif // IGAME_HPP
