#-------------------------------------------------
#
# Project created by QtCreator 2016-02-23T22:49:09
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = calc
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    calculator.cpp

HEADERS += \
    stack.h \
    arraystack.h \
    pointerstack.h \
    calculator.h \
    stacktest.h \
    calculatortest.h
