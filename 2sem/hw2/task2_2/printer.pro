#-------------------------------------------------
#
# Project created by QtCreator 2016-03-05T18:48:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = printer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    printer.cpp \
    consoleprinter.cpp \
    fileprinter.cpp

HEADERS += \
    printer.h \
    consoleprinter.h \
    fileprinter.h
