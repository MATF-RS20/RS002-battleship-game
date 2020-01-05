#ifndef TURNFACTORY_HPP
#define TURNFACTORY_HPP

#include "mainwindow.h"

#include "Game/Player/IPlayer.hpp"
#include "Turn.hpp"

class TurnFactory
{
public:
    TurnFactory(MainWindow *ui);

    Turn* CreateTurn(PlayerType playerType, IPlayer* attacker);

private:
    MainWindow *m_ui;
};

#endif // TURNFACTORY_HPP
