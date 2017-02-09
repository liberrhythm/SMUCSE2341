TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DSstring.cpp \
    match.cpp \
    player.cpp \
    tag.cpp \
    team.cpp \
    test.cpp

DISTFILES += \
    .gitignore

HEADERS += \
    catch.hpp \
    DSString.h \
    match.h \
    player.h \
    tag.h \
    team.h
