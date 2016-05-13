#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T03:22:09
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = sorter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    quicksorter.cpp \
    heapsorter.cpp \
    bubblesorter.cpp

HEADERS += \
    sorter.h \
    quicksorter.h \
    heapsorter.h \
    bubblesorter.h \
    sortertest.h
