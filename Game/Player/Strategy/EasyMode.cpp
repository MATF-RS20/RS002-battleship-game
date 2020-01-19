#include "EasyMode.hpp"
#include <QVector>

EasyMode::EasyMode()
{

}

QPair<int, int> EasyMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    return QPair<int, int>(0, 0);
}
