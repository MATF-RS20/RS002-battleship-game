#ifndef GAME_HPP
#define GAME_HPP

#include "mainwindow.h"

#include "IGame.hpp"
#include "Template/FactoryMethod/TurnFactory.hpp"

class Game : public IGame
{
public:
    Game(MainWindow *ui, IPlayer* player1, IPlayer* player2);
    bool AttackBy(IPlayer* player, IPlayer* defender) override;
    GameState GetGameState() override;
    void SwapPlayers() override;

private:
    IPlayer* m_attacker;
    IPlayer* m_defender;
    GameState m_state;
    int m_round;

    TurnFactory* m_turnFactory;
};

#endif // GAME_HPP
