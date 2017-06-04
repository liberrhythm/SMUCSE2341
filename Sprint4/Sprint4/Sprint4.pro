TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp \
    DSString.cpp \
    Airport.cpp \
    FlightPlan.cpp

HEADERS += \
    catch.hpp \
    Queue.h \
    Stack.h \
    LinkedList.h \
    DSString.h \
    Airport.h \
    FlightPlan.h \
    DSVector.h

DISTFILES += \
    FlightData \
    PathsToCalculateFile.txt \
    OutputFile.txt \
    ../build-Sprint4-Desktop_Qt_5_8_0_GCC_64bit-Debug/FlightData.txt \
    ../build-Sprint4-Desktop_Qt_5_8_0_GCC_64bit-Debug/RequestedFlights.txt
