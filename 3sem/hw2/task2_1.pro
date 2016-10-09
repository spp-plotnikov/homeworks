#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T22:38:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task2_1
TEMPLATE = app


CONFIG += debug

SOURCES += main.cpp\
    configurationwizard.cpp \
    numberofcomputerspage.cpp \
    setospage.cpp \
    tablepage.cpp \
    localnetwork.cpp \
    sppsimulatorlan.cpp

HEADERS  += \
    configurationwizard.h \
    numberofcomputerspage.h \
    setospage.h \
    tablepage.h \
    localnetwork.h \
    sppsimulatorlan.h

FORMS    += \
    configurationwizard.ui \
    numberofcomputerspage.ui \
    setospage.ui \
    tablepage.ui \
    sppsimulatorlan.ui

RESOURCES += \
    logospp.qrc
