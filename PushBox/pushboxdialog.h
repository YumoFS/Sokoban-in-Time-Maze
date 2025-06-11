#ifndef PUSHBOXDIALOG_H
#define PUSHBOXDIALOG_H

#include <vector>
#include <QDialog>
#include <QPixmap>
#include <QLabel>
#include <QKeyEvent>
#include <QMessageBox>
#include <qDebug>
#include <vector>
#include <QPushButton>

using namespace std;

namespace Ui {
class PushBoxDialog;
}

#define NULL 0    // 空地
#define WALL 1    // 墙
#define BOX 2     // 箱子
#define TARGET 3  // 目标点
#define PLAYER 4  // 玩家
#define PLAYER_PEACE 5   // 离开状态
#define PEACE 6   // 和平点
#define TRAVEL 7   // 传送门
#define BOX_PEACE 8 //回溯时的箱子

class PushBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PushBoxDialog(QWidget *parent = nullptr);
    ~PushBoxDialog();

    void InitMap(int id);

    void UpdateMap();

    bool isWin();

    void restore();

    void pushbotton();

    void setLevel(int level);

    void keyPressEvent(QKeyEvent *event);

    void retrace();

    void teleport();

    void checkWinCondition();

signals:
    void backToSelection();

    // 在 PushBoxDialog 类中，声明槽函数
public slots:
    void onExitGame();  // 退出游戏按钮的槽
    void onRestartGame();  // 重来游戏按钮的槽
    void onShowPopup();  // 弹窗按钮的槽

private:
    Ui::PushBoxDialog *ui;

    int base;
    int baseX;
    int baseY;

    int m_map[15][15];
    vector<vector<QLabel*>> mp;//地图

    QPixmap pix_wall;
    QPixmap pix_box;
    QPixmap pix_player_peace;
    QPixmap pix_peacepoint;
    QPixmap pix_character_l_0;
    QPixmap pix_character_l_1;
    QPixmap pix_character_r_0;
    QPixmap pix_character_r_1;
    QPixmap pix_character_u_0;
    QPixmap pix_character_u_1;
    QPixmap pix_character_u_2;
    QPixmap pix_character_d_0;
    QPixmap pix_character_d_1;
    QPixmap pix_character_d_2;
    QPixmap pix_des;
    QPixmap pix_travelgate;
    QPixmap pix_box_peace;

    int CurX;
    int CurY;
    int CurId;

    bool isFirstHint;
    QPushButton *hintButton;  // 添加Hint按钮指针

    // 添加提示相关的函数
    void showDemoAnimation();  // 显示通关演示


    // 用于存储移动历史的结构体
    struct MoveHistory {
        int x;          // 玩家位置 x
        int y;          // 玩家位置 y
        bool pushBox;   // 是否推动了箱子
        int boxX;       // 箱子位置 x（如果推动了箱子）
        int boxY;       // 箱子位置 y（如果推动了箱子）
        bool isTeleport;// 是否是传送门移动
        bool onPeace;   // 是否在回溯点上
    };

    std::vector<QPoint> teleportPoints;  // 存储传送门位置
    const int FINAL_LEVEL = 6;  // 定义最后一关的关卡号

    std::vector<MoveHistory> moveHistory;  // 存储移动历史
    int retraceCount;

    list<QPoint> check;//判断获胜

    QVector<QPoint> peacePoints;  // 存储所有回溯点的位置
};

#endif // PUSHBOXDIALOG_H

