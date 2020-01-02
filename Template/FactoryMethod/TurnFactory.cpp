#include "TurnFactory.hpp"
#include "Template/TurnTypes/HumanTurn.hpp"
#include "Template/TurnTypes/ComputerTurn.hpp"

Turn* TurnFactory::CreateTurn(PlayerType playerType)
{
    Turn* turn;
    switch(playerType)
    {
        case PlayerType::Computer:
            turn = new ComputerTurn();
            break;
        case PlayerType::Human:
            turn = new HumanTurn();
            break;
        default:
            break;
    }

    return turn;
}
