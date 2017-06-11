TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    splitter.cpp \
    database.cpp \
    UI.cpp

HEADERS += \
    splitter.hpp \
    database.hpp \
    UI.hpp
