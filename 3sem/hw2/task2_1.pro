#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T22:38:29
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task2_1
TEMPLATE = app


CONFIG += debug

SOURCES += main.cpp \
    Logic_component/localnetwork.cpp \
    GUI_component/configurationwizard.cpp \
    GUI_component/numberofcomputerspage.cpp \
    GUI_component/setospage.cpp \
    GUI_component/sppsimulatorlan.cpp \
    GUI_component/tablepage.cpp \
    Logic_component/sppsimulatorlanhelper.cpp

RESOURCES += \
    GUI_component/images/logospp.qrc

HEADERS += \
    Logic_component/localnetwork.h \
    GUI_component/configurationwizard.h \
    GUI_component/numberofcomputerspage.h \
    GUI_component/setospage.h \
    GUI_component/sppsimulatorlan.h \
    GUI_component/tablepage.h \
    Logic_component/sppsimulatorlanhelper.h \
    Logic_component/operatingsystemsenumeration.h \
    Logic_component/sppsimulatorlanhelpertest.h

FORMS += \
    GUI_component/configurationwizard.ui \
    GUI_component/numberofcomputerspage.ui \
    GUI_component/setospage.ui \
    GUI_component/sppsimulatorlan.ui \
    GUI_component/tablepage.ui
