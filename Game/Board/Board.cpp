#include "Game/Board/IBoard.hpp"
#include "Game/Board/Board.hpp"

Board::Board() :
    m_ships(),
    m_shipFactory(new ShipFactory())
{}

Board::~Board()
{
    delete m_boardPositions;
}

void Board::InitializeBoard()
{
    for(int i = 0 ; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            m_boardPositions[i][j] = new Position(i,j, PositionStatus::Unknown);
        }
    }
}

void Board::CreateShips()
{
    // Battleship
    QVector<Position*> battleshipPosition = {new Position(0, 0, PositionStatus::Unknown),
                                             new Position(0, 1, PositionStatus::Unknown),
                                             new Position(0, 2, PositionStatus::Unknown),
                                             new Position(0, 3, PositionStatus::Unknown)};
    // Carrier
    QVector<Position*> carrierPosition = {new Position(1, 0, PositionStatus::Unknown),
                                          new Position(1, 1, PositionStatus::Unknown),
                                          new Position(1, 2, PositionStatus::Unknown),
                                          new Position(1, 3, PositionStatus::Unknown),
                                          new Position(1, 3, PositionStatus::Unknown)};
    // Cruiser
    QVector<Position*> cruiserPosition = {new Position(2, 0, PositionStatus::Unknown),
                                          new Position(2, 1, PositionStatus::Unknown),
                                          new Position(2, 2, PositionStatus::Unknown)};

    // Submarine
    QVector<Position*> submarinePosition = {new Position(3, 0, PositionStatus::Unknown),
                                            new Position(3, 1, PositionStatus::Unknown),
                                            new Position(3, 2, PositionStatus::Unknown)};

    // Destroyer
    QVector<Position*> destroyerPosition = {new Position(4, 0, PositionStatus::Unknown),
                                            new Position(4, 1, PositionStatus::Unknown)};

    IShip* battleship = m_shipFactory->CreateShip(ShipType::BattleshipType, battleshipPosition);
    IShip* carrier = m_shipFactory->CreateShip(ShipType::CarrierType, carrierPosition);
    IShip* cruiser = m_shipFactory->CreateShip(ShipType::CruiserType, cruiserPosition);
    IShip* destroyer = m_shipFactory->CreateShip(ShipType::DestroyerType, destroyerPosition);
    IShip* submarine = m_shipFactory->CreateShip(ShipType::SubmarineType, submarinePosition);

    // Battleship
    ShipCoordinates* battleshipCoordinates = new ShipCoordinates(battleship, battleshipPosition);
    // Carrier
    ShipCoordinates* carrierCoordinates = new ShipCoordinates(carrier, carrierPosition);
    // Cruiser
    ShipCoordinates* cruiserCoordinates = new ShipCoordinates(cruiser, cruiserPosition);
    // Submarine
    ShipCoordinates* submarineCoordinates = new ShipCoordinates(submarine, submarinePosition);
    // Destroyer
    ShipCoordinates* destroyerCoordinates = new ShipCoordinates(destroyer, destroyerPosition);

    m_ships.push_back(battleshipCoordinates);
    m_ships.push_back(carrierCoordinates);
    m_ships.push_back(cruiserCoordinates);
    m_ships.push_back(submarineCoordinates);
    m_ships.push_back(destroyerCoordinates);
}

void Board::PlaceShips(int x, int y)
{

}

int Board::NumberOfAvailableShips()
{
    foreach (ShipCoordinates* ship, m_ships) {

        bool removeShip = true;
        foreach(Position* shipCoordinate, ship->m_coordinates) {

            if (shipCoordinate->m_status == PositionStatus::Unknown
                || shipCoordinate->m_status == PositionStatus::Miss) {
                removeShip = false;
            }
        }

        if (removeShip == true)
            m_ships.remove(m_ships.indexOf(ship));
    }

    return m_ships.size();
}

void Board::AttackOnCoordinates(int x, int y)
{
    PositionStatus attackStatus = PositionStatus::Miss;

    foreach (ShipCoordinates* ship, m_ships) {
        foreach(Position* shipCoordinate, ship->m_coordinates) {
            if(shipCoordinate->m_coordinateX == x
               && shipCoordinate->m_coordinateY == y)
            {
                attackStatus = PositionStatus::Hit;
                shipCoordinate->m_status = PositionStatus::Hit;
            }
        }
    }

    m_boardPositions[x][y]->m_status = attackStatus;
}

PositionStatus Board::GetPositionStatus(int x, int y)
{
    PositionStatus status = m_boardPositions[x][y]->m_status;
    return status;
}

QVector<ShipCoordinates*> Board::GetShips()
{
    return m_ships;
}
