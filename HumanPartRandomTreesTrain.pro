#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T00:20:53
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = HumanPartRandomTreesTrain
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH +=  /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so.2.4.9 \
        /usr/local/lib/libopencv_core.so.2.4.9    \
        /usr/local/lib/libopencv_imgproc.so.2.4.9 \
        /usr/local/lib/libopencv_contrib.so.2.4.9 \
        /usr/local/lib/libopencv_video.so.2.4.9   \
        /usr/local/lib/libopencv_ml.so.2.4.9
