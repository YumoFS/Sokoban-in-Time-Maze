#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "levelselection2/levelselection2.h"
#include "gameinstruction/gameinstruction.h"
#include "PushBox/pushboxdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void showLevelSelection();  // 添加这个信号

private:
    Ui::MainWindow *ui;
    LevelSelection2 *ppage2;
    GameInstruction *ppage3;
    PushBoxDialog *pushBoxGame;
};

#endif // MAINWINDOW_H
