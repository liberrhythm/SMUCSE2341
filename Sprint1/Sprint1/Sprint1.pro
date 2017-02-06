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
    sharks.txt \
    ../build-Sprint1-Desktop_Qt_5_8_0_MinGW_32bit-Debug/cowboys.txt \
    ../build-Sprint1-Desktop_Qt_5_8_0_MinGW_32bit-Debug/match1.txt
