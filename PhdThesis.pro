######################################################################
# Automatically generated by qmake (3.0) qua set 17 08:57:18 2014
######################################################################

QT+=core
QT+=widgets
TEMPLATE = app
TARGET = PhdThesis
INCLUDEPATH += . src

# Input
HEADERS += src/ComplexNetwork.hpp src/Edge.hpp src/Node.hpp
SOURCES += src/ComplexNetwork.cpp src/Edge.cpp src/main.cpp src/Node.cpp
CONFIG(debug, debug|release) { 
    DESTDIR = "debug"
    }
CONFIG(release, debug|release) { 
    DESTDIR = "release"
}