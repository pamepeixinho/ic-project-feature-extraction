######################################################################
# Automatically generated by qmake (3.0) qui set 25 17:00:51 2014
######################################################################

QT+=core
QT+=widgets
CONFIG+=c++11
LIBS+=-L/opt/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
QMAKE_CXXFLAGS+=-I/opt/local/include
QMAKE_CXXFLAGS+=-std=c++11 -U__STRICT_ANSI__
TEMPLATE = app
TARGET = PhdThesis
INCLUDEPATH += src

# Input
HEADERS += src/AreaFeatureExtractor.hpp \
           src/ComplexNetwork.hpp \
           src/ComplexNetworkConstructor.hpp \
           src/DatabaseReader.hpp \
           src/Edge.hpp \
           src/Feature.hpp \
           src/FeatureExtractor.hpp \
           src/HsvHistFeatureExtractor.hpp \
           src/Link.hpp \
           src/Node.hpp \
           src/Region.hpp \
           src/SunDatabaseReader.hpp \
           src/SupervisedImage.hpp
SOURCES += src/AreaFeatureExtractor.cpp \
           src/ComplexNetwork.cpp \
           src/ComplexNetworkConstructor.cpp \
           src/Edge.cpp \
           src/Feature.cpp \
           src/FeatureExtractor.cpp \
           src/HsvHistFeatureExtractor.cpp \
           src/Link.cpp \
           src/Node.cpp \
           src/Region.cpp \
           src/SunDatabaseReader.cpp \
           src/SupervisedImage.cpp \
           src/main.cpp

CONFIG(debug, debug|release) { 
    DESTDIR = "debug"
    OBJECTS_DIR="debug/object_files"
}
CONFIG(release, debug|release) { 
    DESTDIR = "release"
    OBJECTS_DIR="release/object_files"
}
