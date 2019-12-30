#include "Game/Player/Player.hpp";
#include "Game/Game.hpp";
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
    ui->ship1->setScaledContents(true);
    ui->ship2->setPixmap(QPixmap("Assets/Images/2.png"));
    ui->ship3->setPixmap(QPixmap("Assets/Images/3.png"));
    ui->ship4->setPixmap(QPixmap("Assets/Images/4.png"));
    ui->ship5->setPixmap(QPixmap("Assets/Images/5.png"));


    // ubacio sam staticki ove brodove samo da vidim kako ce da izgleda
    // 1. ship
    QLabel *ship1 = new QLabel();
    ship1->setPixmap(QPixmap("Assets/Images/1.png"));
    ship1->setScaledContents(true);

    ui->player1Field->setCellWidget(0,1,ship1);

    // 2. ship
    ui->player1Field->setSpan(3, 2, 1,2);
    QLabel *ship2 = new QLabel();
    ship2->setPixmap(QPixmap("Assets/Images/2.png"));
    ship2->setScaledContents(true);

    ui->player1Field->setCellWidget(3,2,ship2);

    // 3.ship
    ui->player1Field->setSpan(5, 7, 1,3);
    QLabel *ship3 = new QLabel();
    ship3->setPixmap(QPixmap("Assets/Images/3.png"));
    ship3->setScaledContents(true);

    ui->player1Field->setCellWidget(5,7,ship3);

    // 5.ship
    ui->player1Field->setSpan(8, 4, 1,5);
    QLabel *ship5 = new QLabel();
    ship5->setPixmap(QPixmap("Assets/Images/5.png"));
    ship5->setScaledContents(true);

    ui->player1Field->setCellWidget(8,4,ship5);



//    ui->player1Field->setCellWidget(1,5,ui->player1Field->cellWidget(8,4));
//    ui->player1Field->cellWidget(8,5)




    ui->player1Field->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect( ui->player1Field, SIGNAL( cellDoubleClicked (int, int) ),
     this, SLOT( cellSelected( int, int ) ) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBattleBtn_clicked()
{
    QString player1Name = ui->player1NameInput->text();
    QString player2Name = ui->player2NameInput->text();

    m_player1 = new Player(player1Name, PlayerType::Human);
    m_player2 = new Player(player2Name, PlayerType::Human);

    m_game = new Game(m_player1, m_player2);

    while(m_game->GetGameState() != GameState::GameOver)
    {
        QThread::msleep(500);
    }
}
