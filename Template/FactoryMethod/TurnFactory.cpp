#include "mainwindow.h"

#include "TurnFactory.hpp"
#include "Template/TurnTypes/HumanTurn.hpp"
#include "Template/TurnTypes/ComputerTurn.hpp"

TurnFactory::TurnFactory(MainWindow *ui)
    : m_ui(ui)
{

}

Turn* TurnFactory::CreateTurn(PlayerType playerType)
{
    Turn* turn;
    switch(playerType)
    {
        case PlayerType::Computer:
            turn = new ComputerTurn();
            break;
        case PlayerType::Human:
            turn = new HumanTurn(m_ui);
            break;
        default:
            break;
    }

    return turn;
}
