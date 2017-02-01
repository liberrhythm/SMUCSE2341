TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp \
    DSString.cpp

HEADERS += \
    DSString.h \
    catch.hpp
