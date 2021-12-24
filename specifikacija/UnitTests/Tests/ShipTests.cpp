#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../Game/Ships/IShip.hpp"
#include "../../Game/Ships/ShipTypes/Battleship.hpp"
#include "../../Game/Ships/ShipTypes/Carrier.hpp"
#include "../../Game/Ships/ShipTypes/Cruiser.hpp"
#include "../../Game/Ships/ShipTypes/Destroyer.hpp"
#include "../../Game/Ships/ShipTypes/Submarine.hpp"

TEST_CASE("IShip interface testing", "[class][iship][ships]")
{
    SECTION("When Battleship ship is created by ShipFactory class, ship position amount should be BATTLESHIP_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Battleship(shipPositions);

        // act
        int result = ship->GetShipSize();

        // assert
        REQUIRE(result == BATTLESHIP_SIZE);
    }

    SECTION("When Battleship ship is created by ShipFactory class, ship status should be ShipStatus::OK.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Battleship(shipPositions);

        // act
        ShipStatus result = ship->GetShipStatus();

        // assert
        REQUIRE(result == ShipStatus::OK);
    }

    SECTION("When Battleship ship is created by ShipFactory class, ship type should be ShipType::BattleshipType.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Battleship(shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::BattleshipType);
    }


    SECTION("When Battleship is set on position (x, y), IsShipOnPosition should return true for (x, y) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = new Battleship(shipPositions);
        int x = 4;
        int y = 5;

        // act
        ship->SetShipOnPosition(x, y);
        bool result = ship->IsShipOnPosition(x, y);

        // assert
        REQUIRE(result == true);
    }

    SECTION("When Battleship is set on position (x, y), IsShipOnPosition should return false for (x+n, y+n) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = new Battleship(shipPositions);
        int x = 4;
        int y = 5;
        int n = -3;

        // act
        ship->SetShipOnPosition(x, y);
        bool result = ship->IsShipOnPosition(x+n, y+n);

        // assert
        REQUIRE_FALSE(result == true);
    }

    SECTION("When Carrier ship is created by ShipFactory class, ship position amount should be CARRIER_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(1, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = new Carrier(shipPositions);

        // act
        int result = ship->GetShipSize();

        // assert
        REQUIRE(result == CARRIER_SIZE);
    }

    SECTION("When Cruiser ship is created by ShipFactory class, ship type amount should be CRUISER_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Cruiser(shipPositions);

        // act
        int result = ship->GetShipSize();

        // assert
        REQUIRE(result == CRUISER_SIZE);
    }

    SECTION("When Cruiser ship is created by ShipFactory class, ship type should be CruiserType.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Cruiser(shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::CruiserType);
    }

    SECTION("When Cruiser is set on position (x, y), IsShipOnPosition should return true for (x, y) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        IShip* ship = new Cruiser(shipPositions);
        int x = 4;
        int y = 5;

        // act
        ship->SetShipOnPosition(x, y);
        bool result = ship->IsShipOnPosition(x, y);

        // assert
        REQUIRE(result == true);
    }

    SECTION("When Cruiser is set on position (x, y), IsShipOnPosition should return false for (x+n, y+n) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Cruiser(shipPositions);

        // act
        ship->SetShipOnPosition(4, 5);
        bool result = ship->IsShipOnPosition(1, 1);

        // assert
        REQUIRE(result == false);
    }

    SECTION("When Submarine ship is created by ShipFactory class, ship position amount should be SUBMARINE_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Submarine(shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::SubmarineType);
    }

    SECTION("When Submarine ship is created by ShipFactory class, ship position amount should be SUBMARINE_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Submarine(shipPositions);

        // act
        int result = ship->GetShipSize();

        // assert
        REQUIRE(result == SUBMARINE_SIZE);
    }

    SECTION("When Submarine is set on position (x, y), IsShipOnPosition should return true for (x, y) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Submarine(shipPositions);

        // act
        ship->SetShipOnPosition(4, 5);
        bool result = ship->IsShipOnPosition(4, 5);

        // assert
        REQUIRE(result == true);
    }

    SECTION("When Submarine is set on position (x, y), IsShipOnPosition should return false for (x+n, y+n) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Submarine(shipPositions);

        // act
        ship->SetShipOnPosition(4, 5);
        bool result = ship->IsShipOnPosition(1, 1);

        // assert
        REQUIRE(result == false);
    }

    SECTION("When Destroyer ship is created by ShipFactory class, ship position amount should be DESTROYER_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Destroyer(shipPositions);

        // act
        int result = ship->GetShipSize();

        // assert
        REQUIRE(result == DESTROYER_SIZE);
    }

    SECTION("When Destroyer ship is created by ShipFactory class, ship position amount should be DESTROYER_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Destroyer(shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::DestroyerType);
    }

    SECTION("When Destroyer is set on position (x, y), IsShipOnPosition should return true for (x, y) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Destroyer(shipPositions);

        // act
        ship->SetShipOnPosition(4, 5);
        bool result = ship->IsShipOnPosition(4, 5);

        // assert
        REQUIRE(result == true);
    }

    SECTION("When Destroyer is set on position (x, y), IsShipOnPosition should return false for (x+n, y+n) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Destroyer(shipPositions);
        int x = 4;
        int y = 5;
        int n = 3;
        // act
        ship->SetShipOnPosition(x, y);
        bool result = ship->IsShipOnPosition(x+n, y+n);

        // assert
        REQUIRE(result == false);
    }

    SECTION("When Carrier ship is created by ShipFactory class, ship position amount should be CARRIER_SIZE.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Carrier(shipPositions);

        // act
        ShipType result = ship->GetShipType();

        // assert
        REQUIRE(result == ShipType::CarrierType);
    }

    SECTION("When Carrier is set on position (x, y), IsShipOnPosition should return true for (x, y) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Carrier(shipPositions);

        // act
        ship->SetShipOnPosition(4, 5);
        bool result = ship->IsShipOnPosition(4, 5);

        // assert
        REQUIRE(result == true);
    }

    SECTION("When Carrier is set on position (x, y), IsShipOnPosition should return false for (x+n, y+n) position.")
    {
        // arange
        QVector<std::shared_ptr<Position>> shipPositions;
        shipPositions.append(std::make_shared<Position>(5, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(4, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(3, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));
        shipPositions.append(std::make_shared<Position>(2, 5, PositionStatus::Unknown, AvailabilityStatus::Busy));

        IShip* ship = new Carrier(shipPositions);

        // act
        ship->SetShipOnPosition(4, 5);
        bool result = ship->IsShipOnPosition(1, 1);

        // assert
        REQUIRE(result == false);
    }
}
