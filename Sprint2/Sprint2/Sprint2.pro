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
    .gitignore \
    ../build-Sprint2-Desktop_Qt_5_8_0_MinGW_32bit-Debug/cowboys.txt \
    ../build-Sprint2-Desktop_Qt_5_8_0_MinGW_32bit-Debug/match1.txt \
    ../build-Sprint2-Desktop_Qt_5_8_0_MinGW_32bit-Debug/sharks.txt

HEADERS += \
    catch.hpp \
    DSString.h \
    match.h \
    player.h \
    tag.h \
    team.h
