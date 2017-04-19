#-------------------------------------------------
#
# Project created by QtCreator 2017-03-12T15:17:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameLabyrinth1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewidget.cpp \
    GameClasses/unit.cpp \
    GameClasses/roundcollision.cpp \
    GameClasses/rectanglecollision.cpp \
    GameClasses/wall.cpp \
    GameClasses/player.cpp \
    GameClasses/level.cpp \
    GameClasses/map.cpp \
    GameClasses/collision.cpp \
    GameClasses/drawclass.cpp \
    GameClasses/maze.cpp \
<<<<<<< HEAD
    GameClasses/math_function.cpp \
    levelsetting.cpp
=======
    GameClasses/math_function.cpp
>>>>>>> d308ea92dcccc3489fb83f1344e8f25edc0784ce

HEADERS  += mainwindow.h \
    gamewidget.h \
    GameClasses/unit.h \
    GameClasses/roundcollision.h \
    GameClasses/rectanglecollision.h \
    GameClasses/wall.h \
    GameClasses/player.h \
    GameClasses/level.h \
    GameClasses/map.h \
    GameClasses/collision.h \
    GameClasses/drawclass.h \
    GameClasses/maze.h \
<<<<<<< HEAD
    GameClasses/math_function.h \
    levelsetting.h
=======
    GameClasses/math_function.h
>>>>>>> d308ea92dcccc3489fb83f1344e8f25edc0784ce

FORMS    += mainwindow.ui \
    levelsetting.ui

RESOURCES += \
    resource.qrc
