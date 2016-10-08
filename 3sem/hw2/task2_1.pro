#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T22:38:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task2_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configurationwizard.cpp \
    numberofcomputerspage.cpp \
    setospage.cpp \
    tablepage.cpp

HEADERS  += mainwindow.h \
    configurationwizard.h \
    numberofcomputerspage.h \
    setospage.h \
    tablepage.h

FORMS    += mainwindow.ui \
    configurationwizard.ui \
    numberofcomputerspage.ui \
    setospage.ui \
    tablepage.ui

RESOURCES += \
    logospp.qrc
