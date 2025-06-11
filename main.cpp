#include "mainwindow.h"
#include "levelselection2/levelselection2.h"
#include "gameinstruction/gameinstruction.h"
#include "PushBox/pushboxdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建窗口
    MainWindow mainWindow;
    LevelSelection2 levelSelection;
    PushBoxDialog pushBoxDialog;

    // 连接 MainWindow 和 LevelSelection2
    QObject::connect(&mainWindow, &MainWindow::showLevelSelection, &levelSelection, &LevelSelection2::show);
    QObject::connect(&levelSelection, &LevelSelection2::back, &mainWindow, &MainWindow::show);

    // 连接关卡选择信号
    QObject::connect(&levelSelection, &LevelSelection2::levelSelected,
                     [&levelSelection, &pushBoxDialog](int level) {
                         levelSelection.hide();
                         pushBoxDialog.setLevel(level);
                         pushBoxDialog.show();
                     });

    // 连接游戏返回信号
    QObject::connect(&pushBoxDialog, &PushBoxDialog::backToSelection,
                     [&levelSelection, &pushBoxDialog]() {
                         pushBoxDialog.hide();
                         levelSelection.show();
                     });

    // 显示主窗口
    mainWindow.show();

    return a.exec();
}
