QT += core
QT -= gui

TARGET = comparator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arraylist.cpp \
    pointerlist.cpp \
    list.cpp \
    listscomparator.cpp \

HEADERS += \
    arraylist.h \
    list.h \
    pointerlist.h \
    listscomparator.h \
    sortedset.h \
    avltree.h

