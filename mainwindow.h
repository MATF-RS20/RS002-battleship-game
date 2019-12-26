#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Game/IGame.hpp"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startBattleBtn_clicked();

private:
    Ui::MainWindow *ui;
    IGame* m_game;
};

#endif // MAINWINDOW_H
