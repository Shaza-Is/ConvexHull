TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /usr/local/include/OpenMesh

LIBS += -L/usr/local/lib -lOpenMeshTools -lOpenMeshCore
SOURCES += main.cpp \
    Incremental.cpp \
    ConvexHull.cpp


HEADERS += \
    Incremental.h\
    ConvexHull.h\
    HullAlgorithm.h


