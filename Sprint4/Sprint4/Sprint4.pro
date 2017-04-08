TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp \
    DSString.cpp \
    Airport.cpp \
    FlightPlan.cpp \
    FlightPaths.cpp

HEADERS += \
    catch.hpp \
    Queue.h \
    Stack.h \
    LinkedList.h \
    DSString.h \
    Airport.h \
    FlightPlan.h \
    DSVector.h \
    FlightPaths.h

DISTFILES += \
    FlightData
