#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T11:46:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CameraReader
TEMPLATE = app
CONFIG += ordered

include(data/data.pri)
include(gui/gui.pri)
include(process/process.pri)
include(core/core.pri)

SOURCES += main.cpp\

INCLUDEPATH += ../LibOpenCV/include
DEPENDPATH += ../LibOpenCV//include

LIBS += -L../LibOpenCV/lib/ \
        -lopencv_highgui243d \
        -lopencv_core243d \
        -lopencv_features2d243d \
        -lopencv_imgproc243d

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    pref.ini \
    camera.ini \


