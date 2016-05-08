#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T21:10:52
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = theHashTable
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    optimalhashfunction.cpp \
    standardhashfunction.cpp

HEADERS += \
    hashtable.h \
    hashtabletest.h \
    hashfunction.h \
    optimalhashfunction.h \
    standardhashfunction.h
