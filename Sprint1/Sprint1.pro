TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp \
    tag.cpp \
    team.cpp \
    player.cpp \
    match.cpp \
    dsstring.cpp

HEADERS += \
    catch.hpp \
    tag.h \
    team.h \
    player.h \
    match.h \
    dsstring.h
