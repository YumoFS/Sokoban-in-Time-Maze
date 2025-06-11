#include "pushboxdialog.h"
#include "ui_pushboxdialog.h"


#define DEF_INITMAP()\
    for(int i = 0; i < 15; i ++){\
        for(int j = 0; j < 15; j ++){\
            m_map[i][j] = temp[i][j];\
            if(temp[i][j] == NULL){\
                mp[i][j]->hide();\
        }else if(temp[i][j] == WALL){\
                mp[i][j]->setPixmap(pix_wall);\
                mp[i][j]->show();\
        }else if(temp[i][j] == BOX){\
                mp[i][j]->setPixmap(pix_box);\
                mp[i][j]->show();\
        }else if(temp[i][j] == TARGET){\
                mp[i][j]->setPixmap(pix_des);\
                mp[i][j]->show();\
        }else if(temp[i][j] == PLAYER){\
                mp[i][j]->setPixmap(pix_character_r_0);\
                mp[i][j]->show();\
        }else if(temp[i][j] == PLAYER_PEACE){\
                mp[i][j]->setPixmap(pix_player_peace);\
                mp[i][j]->show();\
        }else if(temp[i][j] == PEACE){\
                mp[i][j]->setPixmap(pix_peacepoint);\
                mp[i][j]->show();\
        }else if(temp[i][j] == TRAVEL){\
                mp[i][j]->setPixmap(pix_travelgate);\
                mp[i][j]->show();\
        }else if(temp[i][j] == BOX_PEACE){\
                mp[i][j]->setPixmap(pix_box_peace);\
                mp[i][j]->show();\
        }\
    }\
}

void PushBoxDialog::setLevel(int level)
{
    // 设置当前关卡
    CurId = level;
    // 初始化地图
    InitMap(CurId);
    // 更新显示
    UpdateMap();
}

PushBoxDialog::PushBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PushBoxDialog),
    isFirstHint(true),    // 确保所有成员变量都被初始化
    hintButton(nullptr)   // 初始化顺序要与头文件声明顺序一致
{
    ui->setupUi(this);

    // 初始化成员变量
    memset(m_map, 0, sizeof(m_map));
    CurId = 1;
    CurX = 0;
    CurY = 0;

    // 设置基础参数
    base = 25;
    baseX = 5;
    baseY = 5;

    // 加载图片资源
    pix_wall.load(":/image/WallRound_Brown.png");
    pix_box.load(":/image/Crate_Blue.png");
    pix_peacepoint.load(":/image/EndPoint_Brown.png");  //回溯点
    pix_travelgate.load(":/image/EndPoint_Gray.png"); //传送点
    pix_player_peace.load(":/image/Character2.png"); //回溯点上的玩家
    pix_box_peace.load(":/image/Crate_Red.png"); // 回溯点上的玩家
    pix_character_l_0.load(":/image/Character0.png");
    pix_character_l_1.load(":/image/Character1.png");

    pix_character_r_1.load(":/image/Character3.png");
    pix_character_u_0.load(":/image/Character7.png");
    pix_character_u_1.load(":/image/Character8.png");
    pix_character_u_2.load(":/image/Character9.png");
    pix_character_d_0.load(":/image/Character4.png");
    pix_character_d_1.load(":/image/Character5.png");
    pix_character_d_2.load(":/image/Character6.png");
    pix_des.load(":/image/EndPoint_Red.png");

    // 创建标签网格
    vector<QLabel*> t_vector;
    for(int i = 0; i < 15; i++){
        t_vector.clear();
        for(int j = 0; j < 15; j++){
            QLabel* lb_temp = new QLabel(ui->widget);
            lb_temp->setText("");
            lb_temp->setGeometry(baseX+j*base, baseY+i*base, base, base);
            lb_temp->setScaledContents(true);
            lb_temp->setStyleSheet("border:none;");
            lb_temp->hide();
            t_vector.push_back(lb_temp);
        }
        mp.push_back(t_vector);
    }

    // 创建按钮
    pushbotton();

    retraceCount = 3;  // 每关允许回溯3次

    // 初始化容器
    peacePoints.clear();
    check.clear();
    teleportPoints.clear();
}

void PushBoxDialog::pushbotton()
{
    // Exit按钮
    QPushButton *btn = new QPushButton(this);
    btn->setText("Exit");
    btn->move(360, 470);
    btn->setMinimumSize(100, 40);
    btn->setStyleSheet("QPushButton {"
                       "background-color: #FFFFFF;"
                       "border: 2px solid #A0A0A0;"
                       "border-radius: 5px;"
                       "padding: 5px;"
                       "font-family: Arial;"
                       "font-size: 16px;"
                       "font-weight: bold;"
                       "}"
                       "QPushButton:hover {"
                       "background-color: #E0E0E0;"
                       "}");
    connect(btn, &QPushButton::clicked, this, &PushBoxDialog::onExitGame);

    // Again按钮
    QPushButton *btn1 = new QPushButton(this);
    btn1->setText("Again");
    btn1->move(60, 470);
    btn1->setMinimumSize(100, 40);
    btn1->setStyleSheet(btn->styleSheet());  // 复用相同的样式
    connect(btn1, &QPushButton::clicked, this, &PushBoxDialog::onRestartGame);

    // Hint按钮
    hintButton = new QPushButton(this);
    hintButton->setText("Hint");
    hintButton->move(210, 470);
    hintButton->setMinimumSize(100, 40);
    hintButton->setStyleSheet(btn->styleSheet());  // 复用相同的样式
    connect(hintButton, &QPushButton::clicked, this, &PushBoxDialog::onShowPopup);

    // Retrace按钮
    QPushButton *btn3 = new QPushButton(this);
    btn3->setText("Retrace");
    btn3->move(60, 520);
    btn3->setMinimumSize(100, 40);
    btn3->setStyleSheet(btn->styleSheet());  // 复用相同的样式
    connect(btn3, &QPushButton::clicked, this, &PushBoxDialog::retrace);
}


void PushBoxDialog::onExitGame() {
    close();  // 关闭当前对话框，退出游戏
}

// 重来游戏的槽
void PushBoxDialog::onRestartGame() {
    InitMap(CurId);  // 重新初始化地图
    UpdateMap();     // 更新地图
}

// 显示弹窗的槽
void PushBoxDialog::onShowPopup()
{
    if (isFirstHint) {
        // 第一次点击显示提示信息
        switch(CurId) {
        case 1:
            QMessageBox::information(this, "Hint", "Go to Safe Point and retrace the time.");
            break;
        case 2:
            QMessageBox::information(this, "Hint", "Go to Safe Point and retrace the time, crossing the box.");
            break;
        case 3:
            QMessageBox::information(this, "Hint", "Go to Safe Point and retrace the time, crossing the box.");
            break;
        case 4:
            QMessageBox::information(this, "Hint", "You can arrive Escape Point without retracing time.");
            break;
        case 5:
            QMessageBox::information(this, "Hint", "Push the boxes in the line into Safe Point, retrace the time, and then you can proceed directly to Escape Point.");
            break;
        case 6:
            QMessageBox::information(this, "Hint", "Use Portals to push some of key boxes into Safe Point. It's a difficult challenge.");
            break;
        default:
            QMessageBox::information(this, "Hint", "Push the box to the target point.");
            break;
        }
        isFirstHint = false;
    } else {
        // 第二次点击显示演示
        showDemoAnimation();
        isFirstHint = true;  // 重置状态
    }
}

// 显示通关演示
void PushBoxDialog::showDemoAnimation()
{
    QMessageBox demoBox;
    demoBox.setWindowTitle(tr("Level Demo"));
    demoBox.setText(tr("Demo animation will be implemented later."));
    demoBox.setIcon(QMessageBox::Information);
    demoBox.exec();
}

PushBoxDialog::~PushBoxDialog()
{
    delete ui;

    for(auto i = mp.begin();i != mp.end(); i++){
        for(auto j = (*i).begin();j != (*i).end(); j++){
            if((*j)){
                delete (*j);
                (*j) = nullptr;
            }
        }
        (*i).clear();
    }
    mp.clear();
}

void PushBoxDialog::InitMap(int level)
{
    ui->label->setText(QString("Level %1 ").arg(CurId));
    ui->label_2->setText(QString("%1 chance(s) to retrace").arg(CurId));
   ui->label_2->setMinimumWidth(200);  // 设置最小宽度
    // 或者让标签自动调整大小


    QString labelStyle =
        "QLabel {"
        "    font-size: 18px;"          // 设置字体大小
        "    font-weight: bold;"        // 设置为粗体
        "    color: black;"           // 统一字体颜色
        "}";

    ui->label->setStyleSheet(labelStyle);
    ui->label_2->setStyleSheet(labelStyle);

    retraceCount = 3;  // 重置回溯次数
    moveHistory.clear();  // 清空移动历史
    teleportPoints.clear();  // 清空传送门位置
    check.clear();        // 清空目标点列表
    peacePoints.clear();  // 清空回溯点列表

    // 只在第6关初始化传送门位置
    if (level == FINAL_LEVEL) {
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                if(m_map[i][j] == TRAVEL) {
                    teleportPoints.push_back(QPoint(j, i));
                }
            }
        }
    }


    switch(level){
    case 1:
        //第一关 地图初始化
        {
            // 添加标点位置
            CurX = 6;
            CurY = 7;

            int temp[15][15] =  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
                                {0,0,0,0,0,1,1,1,6,1,1,0,0,0,0},
                                {0,0,0,0,0,1,4,0,2,0,3,0,0,0,0},
                                {0,0,0,0,0,1,1,1,0,1,1,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};


            // 清空之前的数据
            check.clear();
            peacePoints.clear();
            moveHistory.clear();

            // 添加标点位置
            QPoint target(10,7);
            check.push_back(target);

            // 扫描并记录所有回溯点位置
            for(int i = 0; i < 15; i++) {
                for(int j = 0; j < 15; j++) {
                    if(temp[i][j] == PEACE) {  // PEACE = 6
                        peacePoints.push_back(QPoint(j, i));
                    }
                    m_map[i][j] = temp[i][j];  // 同时加载地图数据
                }
            }

            DEF_INITMAP()

            if(isWin()){
                CurId++;
                InitMap(CurId);
                UpdateMap();
            }
        }
        break;

    case 2:
    {
        int temp[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
                            {0,0,0,0,1,2,2,2,0,3,0,0,0,0,0},
                            {0,0,0,0,1,0,2,6,0,1,0,0,0,0,0},
                            {0,0,0,0,1,0,2,2,2,1,0,0,0,0,0},
                            {0,0,0,0,1,4,2,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        CurX = 5;
        CurY = 7;
        // 清空之前的数据
        check.clear();        // 存储目标点
        peacePoints.clear();  // 存储回溯点

        // 添加目标点位置
        QPoint target(9, 4);
        check.push_back(target);

        // 扫描地图数据
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                if(temp[i][j] == PEACE) {
                    peacePoints.push_back(QPoint(j, i));
                }
                m_map[i][j] = temp[i][j];
            }
        }

        DEF_INITMAP()

        if(isWin()){
            CurId++;
            InitMap(CurId);
            UpdateMap();
        }
    }
    break;

    case 3:
    {
        int temp[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
                            {0,1,2,2,2,0,0,0,0,2,6,0,1,0,0},
                            {0,1,0,2,0,0,2,0,2,2,2,0,1,0,0},
                            {0,1,0,2,2,2,2,2,6,2,2,0,1,0,0},
                            {0,1,4,2,0,0,2,2,0,0,0,0,1,0,0},
                            {0,1,1,1,1,1,1,1,1,1,3,1,1,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

        CurX = 2;
        CurY = 8;
        // 清空之前的数据
        check.clear();        // 存储目标点
        peacePoints.clear();  // 存储回溯点

        // 添加目标点位置
        QPoint target(10,9);
        check.push_back(target);

        // 扫描地图数据
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                if(temp[i][j] == PEACE) {
                    peacePoints.push_back(QPoint(j, i));
                }
                m_map[i][j] = temp[i][j];
            }
        }

        DEF_INITMAP()

        if(isWin()){
            CurId++;
            InitMap(CurId);
            UpdateMap();
        }
    }
    break;

    case 4:
    {
        int temp[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
                            {0,0,0,0,1,0,4,2,2,0,1,0,0,0,0},
                            {0,0,0,0,1,0,0,2,2,0,1,0,0,0,0},
                            {0,0,0,0,1,0,2,6,0,2,1,0,0,0,0},
                            {0,0,0,0,1,0,6,2,2,0,1,0,0,0,0},
                            {0,0,0,0,1,2,2,0,0,2,1,0,0,0,0},
                            {0,0,0,0,1,1,1,3,1,1,1,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        // 玩家初始位置
        CurX = 6;
        CurY = 5;

        // 添加目标点位置
        QPoint target(7,10);
        check.push_back(target);

        // 扫描地图数据
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                if(temp[i][j] == PEACE) {
                    peacePoints.push_back(QPoint(j, i));
                }
                m_map[i][j] = temp[i][j];
            }
        }

        DEF_INITMAP()

        if(isWin()){
            CurId++;
            InitMap(CurId);
            UpdateMap();
        }
    }
    break;

    case 5:
    {
        int temp[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
                            {0,0,1,0,0,6,0,6,0,6,0,1,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
                            {0,0,1,0,2,0,2,0,2,0,2,1,0,0,0},
                            {0,0,1,4,2,2,2,2,2,2,0,3,0,0,0},
                            {0,0,1,0,0,2,0,2,0,2,2,1,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
                            {0,0,1,0,6,0,6,0,6,0,0,1,0,0,0},
                            {0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        // 玩家初始位置
        CurX = 3;
        CurY = 7;

        // 清空之前的数据
        check.clear();        // 存储目标点
        peacePoints.clear();  // 存储回溯点

        // 添加目标点位置
        QPoint target(11,7);
        check.push_back(target);

        // 扫描地图数据
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                if(temp[i][j] == PEACE) {
                    peacePoints.push_back(QPoint(j, i));
                }
                m_map[i][j] = temp[i][j];
            }
        }

        DEF_INITMAP()

        if(isWin()){
            CurId++;
            InitMap(CurId);
            UpdateMap();
        }
    }
    break;

    case 6:
    {
        int temp[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
                            {0,0,0,0,1,4,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,6,2,2,2,1,0,0,0,0,0},
                            {0,0,0,0,1,2,0,7,2,1,0,0,0,0,0},
                            {0,0,0,0,1,6,2,2,0,1,0,0,0,0,0},
                            {0,0,0,0,1,6,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,2,2,2,2,1,0,0,0,0,0},
                            {0,0,0,0,1,7,2,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,0,0,2,0,1,0,0,0,0,0},
                            {0,0,0,0,1,1,1,1,3,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        // 玩家初始位置
        CurX = 5;
        CurY = 3;

        // 清空之前的数据
        check.clear();        // 存目标点
        peacePoints.clear();  // 存储回溯点

        // 添加目标点位置
        QPoint target(8,11);
        check.push_back(target);

        // 扫描地图数据
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                if(temp[i][j] == PEACE) {
                    peacePoints.push_back(QPoint(j, i));
                }
                m_map[i][j] = temp[i][j];
            }
        }

        DEF_INITMAP()

        if(isWin()){
            CurId++;
            InitMap(CurId);
            UpdateMap();
        }
    }
    break;
    }
    isFirstHint = true;  // 重置提示状态
}


void PushBoxDialog::UpdateMap()
{
    pushbotton();
    restore();
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            if(m_map[i][j] == NULL) {
                mp[i][j]->hide();
            } else {
                switch(m_map[i][j]) {
                case WALL:
                    mp[i][j]->setPixmap(pix_wall);
                    break;
                case BOX:
                    mp[i][j]->setPixmap(pix_box);
                    break;
                case TARGET:
                    mp[i][j]->setPixmap(pix_des);
                    break;
                case PLAYER:
                    mp[i][j]->setPixmap(pix_character_d_0);
                    break;
                case PLAYER_PEACE:
                    mp[i][j]->setPixmap(pix_player_peace);
                    break;
                case BOX_PEACE:
                    mp[i][j]->setPixmap(pix_box_peace);
                    break;
                }
                mp[i][j]->show();
            }
        }
    }

    // 确保回溯点始终显示
    for(const QPoint& point : peacePoints) {
        if(m_map[point.y()][point.x()] != PLAYER &&
            m_map[point.y()][point.x()] != PLAYER_PEACE &&
            m_map[point.y()][point.x()] != BOX &&
            m_map[point.y()][point.x()] != BOX_PEACE) {
            mp[point.y()][point.x()]->setPixmap(pix_peacepoint);
            mp[point.y()][point.x()]->show();
        }
    }

    ui->label_2->setText(QString("%1 chance(s) to retrace").arg(retraceCount));
}

// 修改 isWin() 函数检玩家是否到目标点
bool PushBoxDialog::isWin()
{
    // 查玩家当前位置是否为目标点
    for(auto ite = check.begin(); ite != check.end(); ite++) {
        if(CurX == (*ite).x() && CurY == (*ite).y()) {
            return true;
        }
    }
    return false;
}

void PushBoxDialog::restore()
{
    // 只恢复目标点的状态，不处理回溯点
    for(const QPoint& point : check) {
        if(m_map[point.y()][point.x()] == NULL) {
            m_map[point.y()][point.x()] = TARGET;
        }
    }
}

void PushBoxDialog::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed:" << event->key();
    qDebug() << "Current player position:" << CurX << "," << CurY;


    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
    {
        if(CurY > 0 && m_map[CurY-1][CurX] != WALL) {
            MoveHistory history;
            history.x = CurX;
            history.y = CurY;
            history.pushBox = false;
            history.isTeleport = false;

            // 检查当前位置是否在回溯点上
            bool currentOnPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX && point.y() == CurY) {
                    currentOnPeace = true;
                    break;
                }
            }

            // 检查目标位置是否是回溯点
            bool targetIsPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX && point.y() == CurY-1) {
                    targetIsPeace = true;
                    break;
                }
            }

            // 移动到空地、目标点或回溯点
            if(m_map[CurY-1][CurX] == NULL || m_map[CurY-1][CurX] == TARGET || m_map[CurY-1][CurX] == PEACE) {
                // 清除原位置
                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                // 设置新位置
                if(targetIsPeace) {
                    m_map[CurY-1][CurX] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY-1][CurX] = PLAYER;
                    history.onPeace = false;
                }

                CurY--;
                moveHistory.push_back(history);
                UpdateMap();
                qDebug() << "Moved to:" << CurX << "," << CurY;
            }
            // 推箱子
            else if((m_map[CurY-1][CurX] == BOX || m_map[CurY-1][CurX] == BOX_PEACE) &&
                     CurY > 1 && m_map[CurY-2][CurX] != WALL && m_map[CurY-2][CurX] != BOX && m_map[CurY-2][CurX] != BOX_PEACE) {

                history.pushBox = true;
                history.boxX = CurX;
                history.boxY = CurY-1;

                // 检查箱子目标位置是否是回溯点
                bool boxTargetIsPeace = false;
                for(const QPoint& point : peacePoints) {
                    if(point.x() == CurX && point.y() == CurY-2) {
                        boxTargetIsPeace = true;
                        break;
                    }
                }

                // 移动箱子
                if(boxTargetIsPeace) {
                    m_map[CurY-2][CurX] = BOX_PEACE;
                } else {
                    m_map[CurY-2][CurX] = BOX;
                }

                // 清除原位置
                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                // 移动玩家到箱子原位置
                if(targetIsPeace) {
                    m_map[CurY-1][CurX] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY-1][CurX] = PLAYER;
                    history.onPeace = false;
                }

                CurY--;
                moveHistory.push_back(history);
                UpdateMap();
                qDebug() << "Pushed box and moved to:" << CurX << "," << CurY;
            }
        }
    }
    break;

    case Qt::Key_S:
    case Qt::Key_Down:
    {
        if(CurY < 14 && m_map[CurY+1][CurX] != WALL) {
            MoveHistory history;
            history.x = CurX;
            history.y = CurY;
            history.pushBox = false;
            history.isTeleport = false;

            bool currentOnPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX && point.y() == CurY) {
                    currentOnPeace = true;
                    break;
                }
            }

            bool targetIsPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX && point.y() == CurY+1) {
                    targetIsPeace = true;
                    break;
                }
            }

            if(m_map[CurY+1][CurX] == NULL || m_map[CurY+1][CurX] == TARGET || m_map[CurY+1][CurX] == PEACE) {
                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                if(targetIsPeace) {
                    m_map[CurY+1][CurX] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY+1][CurX] = PLAYER;
                    history.onPeace = false;
                }

                CurY++;
                moveHistory.push_back(history);
                UpdateMap();
            }
            else if((m_map[CurY+1][CurX] == BOX || m_map[CurY+1][CurX] == BOX_PEACE) &&
                     CurY < 13 && m_map[CurY+2][CurX] != WALL && m_map[CurY+2][CurX] != BOX && m_map[CurY+2][CurX] != BOX_PEACE) {

                history.pushBox = true;
                history.boxX = CurX;
                history.boxY = CurY+1;

                bool boxTargetIsPeace = false;
                for(const QPoint& point : peacePoints) {
                    if(point.x() == CurX && point.y() == CurY+2) {
                        boxTargetIsPeace = true;
                        break;
                    }
                }

                if(boxTargetIsPeace) {
                    m_map[CurY+2][CurX] = BOX_PEACE;
                } else {
                    m_map[CurY+2][CurX] = BOX;
                }

                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                if(targetIsPeace) {
                    m_map[CurY+1][CurX] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY+1][CurX] = PLAYER;
                    history.onPeace = false;
                }

                CurY++;
                moveHistory.push_back(history);
                UpdateMap();
            }
        }
    }
    break;

    case Qt::Key_A:
    case Qt::Key_Left:
    {
        if(CurX > 0 && m_map[CurY][CurX-1] != WALL) {
            MoveHistory history;
            history.x = CurX;
            history.y = CurY;
            history.pushBox = false;
            history.isTeleport = false;

            bool currentOnPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX && point.y() == CurY) {
                    currentOnPeace = true;
                    break;
                }
            }

            bool targetIsPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX-1 && point.y() == CurY) {
                    targetIsPeace = true;
                    break;
                }
            }

            if(m_map[CurY][CurX-1] == NULL || m_map[CurY][CurX-1] == TARGET || m_map[CurY][CurX-1] == PEACE) {
                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                if(targetIsPeace) {
                    m_map[CurY][CurX-1] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY][CurX-1] = PLAYER;
                    history.onPeace = false;
                }

                CurX--;
                moveHistory.push_back(history);
                UpdateMap();
            }
            else if((m_map[CurY][CurX-1] == BOX || m_map[CurY][CurX-1] == BOX_PEACE) &&
                     CurX > 1 && m_map[CurY][CurX-2] != WALL && m_map[CurY][CurX-2] != BOX && m_map[CurY][CurX-2] != BOX_PEACE) {

                history.pushBox = true;
                history.boxX = CurX-1;
                history.boxY = CurY;

                bool boxTargetIsPeace = false;
                for(const QPoint& point : peacePoints) {
                    if(point.x() == CurX-2 && point.y() == CurY) {
                        boxTargetIsPeace = true;
                        break;
                    }
                }

                if(boxTargetIsPeace) {
                    m_map[CurY][CurX-2] = BOX_PEACE;
                } else {
                    m_map[CurY][CurX-2] = BOX;
                }

                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                if(targetIsPeace) {
                    m_map[CurY][CurX-1] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY][CurX-1] = PLAYER;
                    history.onPeace = false;
                }

                CurX--;
                moveHistory.push_back(history);
                UpdateMap();
            }
        }
    }
    break;

    case Qt::Key_D:
    case Qt::Key_Right:
    {
        if(CurX < 14 && m_map[CurY][CurX+1] != WALL) {
            MoveHistory history;
            history.x = CurX;
            history.y = CurY;
            history.pushBox = false;
            history.isTeleport = false;

            bool currentOnPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX && point.y() == CurY) {
                    currentOnPeace = true;
                    break;
                }
            }

            bool targetIsPeace = false;
            for(const QPoint& point : peacePoints) {
                if(point.x() == CurX+1 && point.y() == CurY) {
                    targetIsPeace = true;
                    break;
                }
            }

            if(m_map[CurY][CurX+1] == NULL || m_map[CurY][CurX+1] == TARGET || m_map[CurY][CurX+1] == PEACE) {
                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                if(targetIsPeace) {
                    m_map[CurY][CurX+1] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY][CurX+1] = PLAYER;
                    history.onPeace = false;
                }

                CurX++;
                moveHistory.push_back(history);
                UpdateMap();
            }
            else if((m_map[CurY][CurX+1] == BOX || m_map[CurY][CurX+1] == BOX_PEACE) &&
                     CurX < 13 && m_map[CurY][CurX+2] != WALL && m_map[CurY][CurX+2] != BOX && m_map[CurY][CurX+2] != BOX_PEACE) {

                history.pushBox = true;
                history.boxX = CurX+1;
                history.boxY = CurY;

                bool boxTargetIsPeace = false;
                for(const QPoint& point : peacePoints) {
                    if(point.x() == CurX+2 && point.y() == CurY) {
                        boxTargetIsPeace = true;
                        break;
                    }
                }

                if(boxTargetIsPeace) {
                    m_map[CurY][CurX+2] = BOX_PEACE;
                } else {
                    m_map[CurY][CurX+2] = BOX;
                }

                if(currentOnPeace) {
                    m_map[CurY][CurX] = PEACE;
                } else {
                    m_map[CurY][CurX] = NULL;
                }

                if(targetIsPeace) {
                    m_map[CurY][CurX+1] = PLAYER_PEACE;
                    history.onPeace = true;
                } else {
                    m_map[CurY][CurX+1] = PLAYER;
                    history.onPeace = false;
                }

                CurX++;
                moveHistory.push_back(history);
                UpdateMap();
            }
        }
    }
    break;
    }

    // 每次移动后检查利条件
    if(isWin()) {
        CurId++;
        InitMap(CurId);
        UpdateMap();
    }
}

// 添加回溯函数
void PushBoxDialog::retrace()
{
    if (moveHistory.empty() || retraceCount <= 0) {
        QMessageBox::warning(this, "Warning", "No more retrace chances!");
        return;
    }

    MoveHistory lastMove = moveHistory.back();
    moveHistory.pop_back();

    // 如果玩家当前在回溯点上，恢复为PEACE状态
    if (m_map[CurY][CurX] == PLAYER_PEACE) {
        m_map[CurY][CurX] = PEACE;
    } else {
        m_map[CurY][CurX] = NULL;
    }

    // 恢复玩家位置
    CurY = lastMove.y;
    CurX = lastMove.x;

    // 根据历史记录决定玩家状态
    if (lastMove.onPeace) {
        m_map[CurY][CurX] = PLAYER_PEACE;
    } else {
        m_map[CurY][CurX] = PLAYER;
    }

    // 处理箱子
    if (lastMove.pushBox) {
        int newBoxY = lastMove.boxY - (lastMove.y - CurY);
        int newBoxX = lastMove.boxX - (lastMove.x - CurX);

        // 清除新箱子位置
        if (m_map[newBoxY][newBoxX] == BOX_PEACE) {
            m_map[newBoxY][newBoxX] = PEACE;
        } else {
            m_map[newBoxY][newBoxX] = NULL;
        }

        // 恢复箱子位置
        if (m_map[lastMove.boxY][lastMove.boxX] == TARGET || m_map[lastMove.boxY][lastMove.boxX] == PEACE) {
            m_map[lastMove.boxY][lastMove.boxX] = BOX_PEACE;
        } else {
            m_map[lastMove.boxY][lastMove.boxX] = BOX;
        }
    }

    retraceCount--;
    UpdateMap();
}

// 添加传送门功能
void PushBoxDialog::teleport()
{
    // 只在最后一关允许传送
    if (CurId != FINAL_LEVEL) {
        return;
    }

    // 检查当前位置是否是传送门
    bool onTeleport = false;
    QPoint currentPos(CurX, CurY);
    QPoint targetPos;

    for(const QPoint& point : teleportPoints) {
        if(point == currentPos) {
            onTeleport = true;
            // 找到另一个传送门
            for(const QPoint& dest : teleportPoints) {
                if(dest != point) {
                    targetPos = dest;
                    break;
                }
            }
            break;
        }
    }

    if(onTeleport) {
        // 记录移动历史
        MoveHistory history;
        history.x = CurX;
        history.y = CurY;
        history.pushBox = false;
        history.isTeleport = true;

        // 执行传送
        m_map[CurY][CurX] = TRAVEL;  // 恢复原位置的传送门
        CurX = targetPos.x();
        CurY = targetPos.y();
        m_map[CurY][CurX] = PLAYER;

        moveHistory.push_back(history);
        UpdateMap();
    }
}

void PushBoxDialog::checkWinCondition()
{
    // 检查是否到达目标点
    if(isWin()) {
        // 显示过关提示
        QMessageBox::information(this, "Congratulations", QString("Level %1 Complete!").arg(CurId));

        // 如果不是最后一关，进入下一关
        if(CurId < FINAL_LEVEL) {
            CurId++;
            InitMap(CurId);
            UpdateMap();
        } else {
            // 如果是最后一关，显示游戏通关提示
            QMessageBox::information(this, "Congratulations", "You have completed all levels!");
            // 可以选择关闭游戏或返回主菜
            // close();  // 如果想直接关闭游戏
        }
    }
}

