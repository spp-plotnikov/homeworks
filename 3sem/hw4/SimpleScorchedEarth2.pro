#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T02:26:50
#
#-------------------------------------------------

QT       += core gui

CONFIG += debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleScorchedEarth2
TEMPLATE = app


SOURCES += main.cpp\
        GUI_Component\gamegui.cpp \
    Logic_Component\game.cpp \
    Logic_Component\cannon.cpp \
    Logic_Component\littlebulletshot.cpp \
    Logic_Component\grenadeshot.cpp \
    Logic_Component/shot.cpp

HEADERS  += GUI_Component\gamegui.h \
    Logic_Component\game.h \
    Logic_Component\cannon.h \
    Logic_Component\shot.h \
    Logic_Component\littlebulletshot.h \
    Logic_Component\grenadeshot.h

FORMS    += GUI_Component\gamegui.ui

RESOURCES += \
    GUI_Component\images.qrc
