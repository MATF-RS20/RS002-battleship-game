#include "Game/Player/Player.hpp";
#include "Game/Board/Board.hpp";
#include "Game/Game.hpp";
#include <iostream>
#include <QThread>
#include <QIcon>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QDir>


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->player1Field, SIGNAL(cellClicked(int, int)), this, SLOT(player1FieldClicked(int, int)));
    connect(ui->player2Field, SIGNAL(cellClicked(int, int)), this, SLOT(player2FieldClicked(int, int)));

//    ui->label->setText(QDir::currentPath());

    for (int i = 0; i < 10; i++) {
        ui->player1Field->setColumnWidth(i,30);
        ui->player1Field->setRowHeight(i,30);
        ui->player2Field->setColumnWidth(i,30);
        ui->player2Field->setRowHeight(i,30);
    }

    // prikaz i odabir brodova
    // TODO: napraviti draggable elemente koje mozemo pomerati u tabelu
    ui->ship1->setPixmap(QPixmap("Assets/Images/1.png"));
    ui->ship2->setPixmap(QPixmap("Assets/Images/2.png"));
    ui->ship3->setPixmap(QPixmap("Assets/Images/3.png"));
    ui->ship4->setPixmap(QPixmap("Assets/Images/4.png"));
    ui->ship5->setPixmap(QPixmap("Assets/Images/5.png"));




    // ubacio sam staticki ove brodove samo da vidim kako ce da izgleda
    // 1. ship, x = 0, y = 1, size = 1
    setShip(0,1,1);

    // 2. ship, x = 3, y = 2, size = 2
    setShip(3,2,2);

    // 3. ship, x = 5, y = 7, size = 3
    setShip(5,7,3);

    // 4. ship, x = 2, y = 0, size = 4
    setShip(2,0,4);

    // 5. ship, x = 8, y = 4, size = 5
    setShip(8,4,5);

//    ui->player1Field->setCellWidget(1,5,ui->player1Field->cellWidget(8,4));
//    ui->player1Field->cellWidget(8,5)

    ui->player1Field->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect( ui->player1Field, SIGNAL( cellDoubleClicked (int, int) ),
     this, SLOT( cellSelected( int, int ) ) );

    ui->player1Field->setEnabled(false);
    ui->player2Field->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::player1FieldClicked(int x, int y)
{
    bool playAgain = false;

    if (m_game->GetGameState() != GameState::GameOver) {
        playAgain = m_game->AttackBy(m_player1, x, y);
    }

    if (playAgain == false) {
        ui->player1Field->setEnabled(false);
        ui->player2Field->setEnabled(true);
    }
}

void MainWindow::player2FieldClicked(int x, int y)
{
    bool playAgain = false;

    if (m_game->GetGameState() != GameState::GameOver) {
        playAgain = m_game->AttackBy(m_player2, x, y);
    }

    if (playAgain == false) {
        ui->player1Field->setEnabled(true);
        ui->player2Field->setEnabled(false);
    }

    //IBoard* p1Board = m_player1->GetBoard();
    //QVector<ShipCoordinates*> p1ShipCoordinates = p1Board->GetShips();

    //IBoard* p2Board = m_player2->GetBoard();
    //QVector<ShipCoordinates*> p2ShipCoordinates = p2Board->GetShips();
}

void MainWindow::on_startBattleBtn_clicked()
{
    QString player1Name = ui->player1NameInput->text();
    QString player2Name = ui->player2NameInput->text();

    m_player1 = new Player(player1Name, PlayerType::Human);
    m_player2 = new Player(player2Name, PlayerType::Human);

    m_game = new Game(m_player1, m_player2);

    ui->player1Field->setEnabled(false);
    ui->player2Field->setEnabled(true);

    /*while(m_game->GetGameState() != GameState::GameOver)
    {
        m_game->AttackBy(m_player1);
        m_game->AttackBy(m_player2);

        QThread::msleep(500);
    }*/

    //IBoard* p1Board = m_player1->GetBoard();
    //QVector<ShipCoordinates*> p1ShipCoordinates = p1Board->GetShips();
}

void MainWindow::setShip(int x, int y, int size)
{
    for (int i = 0; i < size ; i++ ) {
        QLabel *ship = new QLabel();
        std::string imageNamePom;
        if (size == 1)
            imageNamePom = "Assets/Images/" + std::to_string(size) + ".png";
        else
            imageNamePom = "Assets/Images/" + std::to_string(size) + "_" + std::to_string(i+1) + ".png";
        const char* imageName = imageNamePom.c_str();
        ship->setPixmap(QPixmap(imageName));
        ship->setScaledContents(true);
        ui->player1Field->setCellWidget(x,y+i,ship);

    }
}

