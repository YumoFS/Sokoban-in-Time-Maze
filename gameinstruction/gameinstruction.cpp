#include "gameinstruction.h"
#include "ui_gameinstruction.h"
#include <QPushButton>


GameInstruction::GameInstruction(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameInstruction)
{
    ui->setupUi(this);

    //返回主页面
    connect(ui->Return_GameInstruction,&QPushButton::clicked,[=](){
        //发信号去
        emit this->back();
    });
}

GameInstruction::~GameInstruction()
{
    delete ui;
}

//void GameInstruction::run()
//{
//    this->show();
//}

//void GameInstruction::initGameInstrution(int w2, int h2, const QString &title2)
//{
//    setFixedSize(w2,h2);
//    setWindowTitle(title2);
//}
