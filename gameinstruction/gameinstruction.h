#ifndef GAMEINSTRUCTION_H
#define GAMEINSTRUCTION_H

#include <QMainWindow>

namespace Ui {
class GameInstruction;
}

class GameInstruction : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameInstruction(QWidget *parent = nullptr);
    void run();

    ~GameInstruction();

//信号GameInstruction
signals:
    void back();

private:
    Ui::GameInstruction *ui;
};

#endif // GAMEINSTRUCTION_H
