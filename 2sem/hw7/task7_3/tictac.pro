#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T02:54:33
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tictac
TEMPLATE = app


SOURCES += main.cpp\
        tictactoe.cpp \
    tictactoehelper.cpp

HEADERS  += tictactoe.h \
    tictactoehelper.h \
    tictactoehelpertest.h

FORMS    += tictactoe.ui

RC_FILE = logoSPP.rc

RESOURCES += \
    images.qrc
