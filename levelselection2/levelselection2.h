#ifndef LEVELSELECTION2_H
#define LEVELSELECTION2_H

#include <QMainWindow>
#include <QToolButton>  // 添加这个头文件

namespace Ui {
class LevelSelection2;
}

class LevelSelection2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelSelection2(QWidget *parent = nullptr);
    ~LevelSelection2();
    void setupUI();

signals:
    void levelSelected(int level);
    void back();

private:
    void setupLevelButtons();

private:
    Ui::LevelSelection2 *ui;
};

#endif // LEVELSELECTION2_H
