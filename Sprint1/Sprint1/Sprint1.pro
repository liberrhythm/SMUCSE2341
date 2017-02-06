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
    DSString.cpp

HEADERS += \
    catch.hpp \
    tag.h \
    team.h \
    player.h \
    match.h \
    DSString.h

DISTFILES += \
    cowboys.txt \
    sharks.txt \
    match1.txt
