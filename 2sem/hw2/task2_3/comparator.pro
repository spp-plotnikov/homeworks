QT += core
QT -= gui
QT += testlib

TARGET = comparator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arraylist.cpp \
    pointerlist.cpp \
    list.cpp

HEADERS += \
    arraylist.h \
    list.h \
    pointerlist.h \
    sortedset.h \
    avltree.h \
    comparator.h \
    comparatortest.h \
    sortedsettest.h

