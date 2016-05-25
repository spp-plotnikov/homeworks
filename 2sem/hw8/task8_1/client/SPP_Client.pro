#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T00:45:56
#
#-------------------------------------------------

QT       += core gui  network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPP_Client
TEMPLATE = app


SOURCES += main.cpp\
        clientspp.cpp \
    ../helper/messengerhelper.cpp

HEADERS  += clientspp.h \
    ../helper/messengerhelper.h

FORMS    += clientspp.ui

RC_FILE = logoSPP.rc

RESOURCES += \
    images.qrc
