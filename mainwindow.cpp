#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include "levelselection2/levelselection2.h"
#include "gameinstruction/gameinstruction.h"
#include "PushBox/pushboxdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 创建实例
    this->ppage2 = new LevelSelection2;  // 关卡选择页面
    this->ppage3 = new GameInstruction;  // 游戏说明页面
    this->pushBoxGame = new PushBoxDialog;  // 推箱子游戏页面

    // 关于：LevelSelection
    connect(ui->b_LevelSelection, &QPushButton::clicked, this, [this](){
        this->hide();
        this->ppage2->show();
    });

    // 连接关卡选择信号到推箱子游戏
    connect(this->ppage2, &LevelSelection2::levelSelected, this, [this](int level){
        this->ppage2->hide();
        this->pushBoxGame->setLevel(level);
        this->pushBoxGame->show();
    });

    // 从关卡选择返回主菜单
    connect(this->ppage2, &LevelSelection2::back, this, [this](){
        this->ppage2->hide();
        this->show();
    });

    // 从推箱子游戏返回关卡选择
    connect(this->pushBoxGame, &PushBoxDialog::backToSelection, this, [this](){
        this->pushBoxGame->hide();
        this->ppage2->show();
    });

    // 关于：GameInstruction
    connect(ui->b_GameInstruction, &QPushButton::clicked, this, [this](){
        this->hide();
        this->ppage3->show();
    });

    // 从游戏说明返回主菜单
    connect(this->ppage3, &GameInstruction::back, this, [this](){
        this->ppage3->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete pushBoxGame;
    delete ppage2;
    delete ppage3;
    delete ui;
}
