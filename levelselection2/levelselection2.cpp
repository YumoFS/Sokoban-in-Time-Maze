#include "levelselection2.h"
#include "ui_levelselection2.h"
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QFile>
#include <QPixmap>
#include <QDebug>  // 添加调试输出
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QGraphicsDropShadowEffect>

void LevelSelection2::setupLevelButtons()
{
    // 定义图片路径
    QStringList imagePaths = {
        ":/image/1.2.png",
        ":/image/2.2.png",
        ":/image/3.2.png",
        ":/image/4.2.png",
        ":/image/5.2.png",
        ":/image/6.2.png"
    };

    QVector<QPushButton*> buttons;
    buttons.append(ui->Level1);
    buttons.append(ui->Level2);
    buttons.append(ui->Level3);
    buttons.append(ui->Level4);
    buttons.append(ui->Level5);
    buttons.append(ui->Level6);

    for (int i = 0; i < buttons.size(); ++i) {
        if (!buttons[i]) continue;

        // 加载图片
        QPixmap pixmap(imagePaths[i]);
        if (!pixmap.isNull()) {
            QIcon icon(pixmap);
            buttons[i]->setIcon(icon);
            buttons[i]->setIconSize(QSize(80, 80));  // 调整图标大小
        }

        // 设置按钮样式
        buttons[i]->setStyleSheet(
            "QPushButton {"
            "    background-color: transparent;"  // 透明背景
            "    border: none;"                  // 移除边框
            "    outline: none;"                 // 移除轮廓
            "}"
            "QPushButton:focus {"
            "    border: none;"                  // 移除焦点时的边框
            "    outline: none;"                 // 移除焦点时的轮廓
            "}"
            );

        // 设置按钮大小
        buttons[i]->setFixedSize(130, 130);

        // 连接点击信号
        int level = i + 1;
        connect(buttons[i], &QPushButton::clicked, this, [this, level]() {
            emit levelSelected(level);
        });
    }
}

LevelSelection2::LevelSelection2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelSelection2)
{
    ui->setupUi(this);

    // 设置固定窗口大小
    this->setFixedSize(650, 650);

    // 设置窗口背景色

    this->setStyleSheet("QMainWindow { background-color: rgb(255, 216, 76); }");

    ui->Return_LevelSelection->setFixedSize(80, 40);  // 增大按钮尺寸
    ui->Return_LevelSelection->move(20, 20);          // 调整位置，远离边缘

    // 设置返回按钮样式
    ui->Return_LevelSelection->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border: 2px solid #8B4513;"         // 加粗边框
        "    border-radius: 8px;"               // 调整圆角
        "    padding: 5px 15px;"                // 增加内边距
        "    font-size: 13px;"                  // 增大字体
        "    font-weight: bold;"
        "    color: #8B4513;"
        "}"
        "QPushButton:hover {"
        "    background-color: #F0F0F0;"
        "    border-color: #654321;"            // 悬停时边框颜色加深
        "}"
        "QPushButton:pressed {"
        "    background-color: #E0E0E0;"
        "}"
        );

    // 连接返回按钮
    connect(ui->Return_LevelSelection, &QPushButton::clicked, this, [this](){
        emit back();
    });

    setupLevelButtons();
}

LevelSelection2::~LevelSelection2()
{
    delete ui;
}
