#ifndef GAME_HPP
#define GAME_HPP

#include "IGame.hpp"

class Game : public IGame
{
public:
    Game(IPlayer* player1, IPlayer* player2);
    void AttackBy(IPlayer* player) override;
    GameState GetGameState() override;

private:
    void SwapPlayers();

    IPlayer* m_attacker;
    IPlayer* m_defender;
    GameState m_state;
    int m_round;

};

#endif // GAME_HPP
