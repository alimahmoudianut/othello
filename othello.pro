QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = othello
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    logic/piece.cpp \
    logic/cell.cpp \
    logic/player.cpp \
    logic/board.cpp \
    logic/time.cpp \
    logic/game.cpp \
    logic/player/humanplayer.cpp \
    logic/player/clientplayer.cpp \
    logic/player/serverplayer.cpp \
    network/serverterminal.cpp \
    network/serverconnection.cpp \
    network/clientterminal.cpp \
    network/servercli.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    logic/piece.h \
    logic/cell.h \
    logic/player.h \
    logic/board.h \
    logic/time.h \
    logic/game.h \
    logic/player/humanplayer.h \
    logic/player/clientplayer.h \
    logic/player/serverplayer.h \
    network/serverterminal.h \
    network/serverconnection.h \
    network/clientterminal.h \
    network/servercli.h

RESOURCES += \
    src.qrc
