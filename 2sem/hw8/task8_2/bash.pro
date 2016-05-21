#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T19:38:05
#
#-------------------------------------------------

QT       += core gui webkitwidgets xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bash
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        bashquotes.cpp

HEADERS  += bashquotes.h

FORMS    += bashquotes.ui

RC_FILE = logoSPP.rc

RESOURCES += \
    images.qrc
