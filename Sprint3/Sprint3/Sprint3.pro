TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DSString.cpp

HEADERS += \
    DSString.h \
    DSVector.h

DISTFILES += \
    input.txt \
    ../build-Sprint3-Desktop_Qt_5_8_0_GCC_64bit-Debug/input.txt \
    ../build-Sprint3-Desktop_Qt_5_8_0_GCC_64bit-Debug/output.txt
