#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../Game/Player/Player.hpp"
#include "../../Game/Player/Strategy/ShootingStrategyFactory.hpp"

//    std::shared_ptr<IShootingStrategy> CreateComputerStrategy(PlayerStrategy computerStrategy);


TEST_CASE("ShootingStrategyFactory class testing", "[class][factory]")
{
    SECTION("When Easy shooting strategy is on, GetAttackingPosition can return Position with any status type.")
    {
        // arange
        std::shared_ptr<IPlayer> attacker = std::make_shared<Player>("Jovan", PlayerType::Human, PlayerStrategy::Easy);
        ShootingStrategyFactory shootingStrategyFactory;
        std::shared_ptr<IShootingStrategy> easyMode = shootingStrategyFactory.CreateComputerStrategy(PlayerStrategy::Easy);

        // act
        std::shared_ptr<Position> position = easyMode->GetAttackingPosition(attacker);
        PositionStatus result = position->m_status;

        // assert
        REQUIRE(result == PositionStatus::Unknown ||
                result == PositionStatus::Hit ||
                result == PositionStatus::Miss ||
                result == PositionStatus::Destroyed);
    }

    SECTION("When Hard shooting strategy is on, GetAttackingPosition can return Position with Unknown status only.")
    {
        // arange
        std::shared_ptr<IPlayer> attacker = std::make_shared<Player>("Dragan", PlayerType::Human, PlayerStrategy::Hard);
        ShootingStrategyFactory shootingStrategyFactory;
        std::shared_ptr<IShootingStrategy> hardMode = shootingStrategyFactory.CreateComputerStrategy(PlayerStrategy::Hard);

        // act
        std::shared_ptr<Position> position = hardMode->GetAttackingPosition(attacker);
        PositionStatus result = position->m_status;

        // assert
        REQUIRE(result == PositionStatus::Unknown);
    }
}
