#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T02:26:50
#
#-------------------------------------------------

QT       += core gui
QT       += network

CONFIG += debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleScorchedEarth2
TEMPLATE = app


SOURCES += main.cpp\
        GUI_Component\gamegui.cpp \
    Game_Component\game.cpp \
    Game_Component\cannon.cpp \
    Game_Component\littlebulletshot.cpp \
    Game_Component\grenadeshot.cpp \
    Game_Component/shot.cpp \
    Network_Component/networkentity.cpp \
    Network_Component/client.cpp \
    Network_Component/server.cpp

HEADERS  += GUI_Component\gamegui.h \
    Game_Component\game.h \
    Game_Component\cannon.h \
    Game_Component\shot.h \
    Game_Component\littlebulletshot.h \
    Game_Component\grenadeshot.h \
    Network_Component/networkentity.h \
    Network_Component/client.h \
    Network_Component/server.h

FORMS    += GUI_Component\gamegui.ui

RESOURCES += \
    GUI_Component\images.qrc
