#include "Template/TurnTypes/HumanTurn.hpp"

HumanTurn::HumanTurn(MainWindow *ui)
    : m_ui(ui)
{}

Shoot* HumanTurn::CreateShoot()
{
    int row = m_ui->getSelectedRow();
    int column = m_ui->getSelectedColumn();
    Shoot* shoot = new Shoot(row, column);

    return shoot;
}
