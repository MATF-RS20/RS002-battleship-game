#include "HardMode.hpp"

HardMode::HardMode()
{

}

QPair<int, int> HardMode::GetAttackingPosition(std::shared_ptr<IPlayer> attacker)
{
    return QPair<int, int>(1, 1);
}
