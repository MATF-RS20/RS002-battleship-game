#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../Game/Ships/FactoryMethod/ShipFactory.hpp"
#include "../../Game/Ships/IShip.hpp"


TEST_CASE("ShipFactory class testing", "[class][factory]")
{
    SECTION("When Carrier ship is created by ShipFactory class, ship type should be CarrierType.")
    {
        // arange
        ShipFactory shipFactory;
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(1, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = shipFactory.CreateShip(ShipType::CarrierType, shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::CarrierType);
    }

    SECTION("When Battleship ship is created by ShipFactory class, ship type should be BattleshipType.")
    {
        // arange
        ShipFactory shipFactory;
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = shipFactory.CreateShip(ShipType::BattleshipType, shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::BattleshipType);
    }

    SECTION("When Cruiser ship is created by ShipFactory class, ship type should be CruiserType.")
    {
        // arange
        ShipFactory shipFactory;
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = shipFactory.CreateShip(ShipType::CruiserType, shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::CruiserType);
    }

    SECTION("When Submarine ship is created by ShipFactory class, ship type should be SubmarineType.")
    {
        // arange
        ShipFactory shipFactory;
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = shipFactory.CreateShip(ShipType::SubmarineType, shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::SubmarineType);
    }

    SECTION("When Destroyer ship is created by ShipFactory class, ship type should be DestroyerType.")
    {
        // arange
        ShipFactory shipFactory;
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = shipFactory.CreateShip(ShipType::DestroyerType, shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::DestroyerType);
    }
}
