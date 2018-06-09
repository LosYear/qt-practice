#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T18:31:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
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
        ui/mainwindow.cpp \
    classes/room.cpp \
    classes/maze.cpp \
    classes/hero.cpp \
    classes/game.cpp \
    classes/item.cpp \
    classes/food.cpp \
    ui/shopwindow.cpp \
    classes/shop.cpp \
    classes/gold.cpp \
    classes/weapon.cpp \
    classes/shield.cpp \
    classes/actor.cpp \
    classes/enemy.cpp \
    classes/battle.cpp

HEADERS += \
        ui/mainwindow.h \
    classes/room.h \
    classes/direction.h \
    classes/maze.h \
    classes/hero.h \
    classes/game.h \
    classes/item.h \
    classes/food.h \
    ui/shopwindow.h \
    classes/shop.h \
    classes/gold.h \
    classes/weapon.h \
    classes/shield.h \
    classes/actor.h \
    classes/enemy.h \
    classes/battle.h

FORMS += \
        ui/mainwindow.ui \
    ui/shopwindow.ui
