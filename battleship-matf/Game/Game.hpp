#ifndef GAME_HPP
#define GAME_HPP

#include "mainwindow.h"

#include "IGame.hpp"
#include "Template/FactoryMethod/TurnFactory.hpp"

class Game : public IGame
{
public:
    Game(MainWindow *ui, std::shared_ptr<IPlayer> player1, std::shared_ptr<IPlayer> player2);
    bool AttackBy(std::shared_ptr<IPlayer> player, std::shared_ptr<IPlayer> defender) override;
    GameState GetGameState() override;
    void SwapPlayers() override;

private:
    std::shared_ptr<IPlayer> m_attacker;
    std::shared_ptr<IPlayer> m_defender;
    GameState m_state;
    int m_round;

    TurnFactory* m_turnFactory;
};

#endif // GAME_HPP
