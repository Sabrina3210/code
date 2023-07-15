#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);

    connect(ui->common_button, &QPushButton::clicked, [=]{
        chess_board.show();
        chess_board.game_type=true;
    });
    connect(ui->funny_button, &QPushButton::clicked, [=]{
        chess_board.show();
        chess_board.game_type=false;
    });
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
