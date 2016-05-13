#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T01:18:53
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = list
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    arraylist.cpp \
    pointerlist.cpp

HEADERS += \
    list.h \
    arraylist.h \
    pointerlist.h \
    listtest.h
