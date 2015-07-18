#-------------------------------------------------
#
# Project created by QtCreator 2015-06-20T22:22:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NixContacts
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addform.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    addform.h \
    about.h

FORMS    += mainwindow.ui \
    addform.ui \
    about.ui
