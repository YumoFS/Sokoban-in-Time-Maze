QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG += sdk_no_version_check

QMAKE_MACOSX_DEPLOYMENT_TARGET = 14

# 源文件
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    levelselection2/levelselection2.cpp \
    gameinstruction/gameinstruction.cpp \
    PushBox/pushboxdialog.cpp

# 头文件
HEADERS += \
    mainwindow.h \
    levelselection2/levelselection2.h \
    gameinstruction/gameinstruction.h \
    PushBox/pushboxdialog.h

# UI文件 - 使用完整相对路径
FORMS += \
    mainwindow.ui \
    $$PWD/levelselection2/levelselection2.ui \
    $$PWD/gameinstruction/gameinstruction.ui \
    $$PWD/PushBox/pushboxdialog.ui

# 包含路径
INCLUDEPATH += \
    $$PWD \
    $$PWD/levelselection2 \
    $$PWD/gameinstruction \
    $$PWD/PushBox

# 资源文件
RESOURCES += \
    PushBox/res.qrc \
    levelselection2/image.qrc

# 删除之前的构建文件
QMAKE_CLEAN += \
    $$PWD/build/* \
    $$PWD/ui_*.h

# 指定生成文件的位置
DESTDIR = $$PWD/bin
OBJECTS_DIR = $$PWD/build/obj
MOC_DIR = $$PWD/build/moc
RCC_DIR = $$PWD/build/rcc
UI_DIR = $$PWD/build/ui

# 对于 Mac arm64 架构
QMAKE_APPLE_DEVICE_ARCHS = arm64
