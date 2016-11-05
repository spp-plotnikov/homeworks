#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T02:26:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleScorchedEarth
TEMPLATE = app


SOURCES += main.cpp\
        gamegui.cpp \
    game.cpp \
    cannon.cpp \
    littlebulletshot.cpp \
    grenadeshot.cpp

HEADERS  += gamegui.h \
    game.h \
    cannon.h \
    shot.h \
    littlebulletshot.h \
    grenadeshot.h

FORMS    += gamegui.ui

RESOURCES += \
    images.qrc
