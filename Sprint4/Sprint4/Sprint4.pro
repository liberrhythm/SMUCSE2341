TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp

HEADERS += \
    catch.hpp \
    Queue.h \
    Stack.h \
    LinkedList.h \
    DSString.h
