QT += widgets
QT += core
QT += gui
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
    network/servercli.cpp \
    view/mainwindow.cpp \
    view/boardwidget.cpp \
    view/newgamedialog.cpp \
    view/selectservergame.cpp

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
    network/servercli.h \
    view/mainwindow.h \
    view/boardwidget.h \
    view/boardtexture.h \
    view/newgamedialog.h \
    view/selectservergame.h

RESOURCES += \
    src.qrc


RESOURCES +=

