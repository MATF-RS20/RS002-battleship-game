#include "Game.hpp"

Game::Game(IPlayer* player1, IPlayer* player2)
    : m_attacker(player1), m_defender(player2), m_state(GameState::InProgress)
    , m_round(1)
{}


void Game::AttackBy(IPlayer* player, int x, int y)
{
    bool isHit = false;

    //do
    //{
        m_defender->GetBoard()->AttackOnCoordinates(x, y);
        int availableShips = m_defender->GetBoard()->NumberOfAvailableShips();

        if(availableShips == 0)
            m_state = GameState::GameOver;
    //}
    //while(isHit);
}

GameState Game::GetGameState()
{
    return m_state;
}

void Game::SwapPlayers()
{
    IPlayer* tmp = m_attacker;
    m_attacker = m_defender;
    m_defender = tmp;
}
