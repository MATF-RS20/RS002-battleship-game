#ifndef HUMANTURN_HPP
#define HUMANTURN_HPP

#include "mainwindow.h"
#include "Template/Turn.hpp"

class HumanTurn : public Turn
{
public:
    HumanTurn(MainWindow *ui);
    std::shared_ptr<Shoot> CreateShoot();

private:
    MainWindow *m_ui;
    int m_xCoordinate;
    int m_yCoordinate;
};

#endif // HUMANTURN_HPP
