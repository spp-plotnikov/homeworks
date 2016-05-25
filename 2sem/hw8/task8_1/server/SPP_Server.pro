#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T05:27:58
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPP_Server
TEMPLATE = app


SOURCES += main.cpp\
        serverspp.cpp \
    ../helper/messengerhelper.cpp

HEADERS  += serverspp.h \
    ../helper/messengerhelper.h

FORMS    += serverspp.ui

RC_FILE = logoSPP.rc

RESOURCES += \
    images.qrc
