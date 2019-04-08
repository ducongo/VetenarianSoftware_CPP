#-------------------------------------------------
#
# Project created by QtCreator 2019-02-02T12:55:42
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuac
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        homeview.cpp \
    animalprofiledialog.cpp \
    animalprofileeditdialog.cpp \
    clientprofiledialog.cpp \
    clientprofileeditdialog.cpp \
    database.cpp \
    addanimaldialog.cpp \
    animal.cpp \
    list.cpp \
    staff.cpp \
    array.cpp \
    viewanimaldialog.cpp \
    client.cpp \
    addclientdialog.cpp \
    logindialog.cpp \
    erroruserdialog.cpp \
    control.cpp

HEADERS += \
        homeview.h \
    animalprofiledialog.h \
    animalprofileeditdialog.h \
    clientprofiledialog.h \
    clientprofileeditdialog.h \
    database.h \
    datatypes.h \
    addanimaldialog.h \
    ../../../Downloads/Staff_copy.h \
    animal.h \
    attribute.h \
    control.h \
    list.h \
    staff.h \
    array.h \
    viewanimaldialog.h \
    client.h \
    addclientdialog.h \
    logindialog.h \
    erroruserdialog.h

FORMS += \
        homeview.ui \
    animalprofiledialog.ui \
    animalprofileeditdialog.ui \
    clientprofiledialog.ui \
    clientprofileeditdialog.ui \
    addanimaldialog.ui \
    viewanimaldialog.ui \
    addclientdialog.ui \
    logindialog.ui \
    erroruserdialog.ui

QT += widgets

RESOURCES += \
    ressources.qrc
