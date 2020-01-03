#include "Game.hpp"
#include <QThread>

Game::Game(MainWindow *ui, IPlayer* player1, IPlayer* player2)
    : m_attacker(player1),
      m_defender(player2),
      m_state(GameState::InProgress),
      m_round(1),
      m_turnFactory(new TurnFactory(ui))
{}


bool Game::AttackBy(IPlayer* player)
{
    bool playAgain = false;

    //do
    //{
        Turn* turn = m_turnFactory->CreateTurn(player->GetPlayerType());
        playAgain = turn->Play(m_attacker, m_defender);

        int availableShips = m_defender->GetBoard()->NumberOfAvailableShips();

        if(availableShips == 0)
            m_state = GameState::GameOver;

        QThread::msleep(1000);
    //}
    //while(isHit);

    //SwapPlayers();

    return playAgain;
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
