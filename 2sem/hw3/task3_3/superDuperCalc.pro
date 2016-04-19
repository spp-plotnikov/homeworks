#-------------------------------------------------
#
# Project created by QtCreator 2016-03-31T22:43:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = superDuperCalc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../hw1/task1_2/calculator.cpp

HEADERS  += mainwindow.h \
    ../../hw1/task1_2/arraystack.h \
    ../../hw1/task1_2/calculator.h \
    ../../hw1/task1_2/pointerstack.h \
    ../../hw1/task1_2/stack.h

FORMS    += mainwindow.ui

RC_FILE = logoSPP.rc
