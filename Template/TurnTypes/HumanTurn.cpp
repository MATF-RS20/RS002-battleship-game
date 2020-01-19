#include "Template/TurnTypes/HumanTurn.hpp"

HumanTurn::HumanTurn(MainWindow *ui)
    : m_ui(ui)
{}

std::shared_ptr<Shoot> HumanTurn::CreateShoot()
{
    int row = m_ui->getSelectedRow();
    int column = m_ui->getSelectedColumn();
    std::shared_ptr<Shoot> shoot = std::make_shared<Shoot>(row, column);

    return shoot;
}
