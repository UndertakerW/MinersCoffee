#-------------------------------------------------
#
# Project created by QtCreator 2017-06-28T11:47:49
#
#-------------------------------------------------

QT       += \
        core gui network charts\
        charts
QT       +=  sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinerLamp
TEMPLATE = app
VERSION = 0.1.4.4

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS NVIDIA AMD


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gpumonitor.cpp \
    jsonparser.cpp \
        main.cpp \
        mainwindow.cpp \
    minerprocess.cpp \
    highlighter.cpp \
    helpdialog.cpp \
    mysql.cpp \
    nvidianvml.cpp \
    nvocdialog.cpp \
    nvidiaapi.cpp \
    nanopoolapi.cpp \
    amdapi_adl.cpp \
    hashratecharview.cpp \
    piesliceeff.cpp \
    structures.cpp \
    urlapi.cpp

HEADERS += \
    constants.h \
    gpumonitor.h \
    jsonparser.h \
        mainwindow.h \
    minerprocess.h \
    highlighter.h \
    helpdialog.h \
    mysql.h \
    nvidianvml.h \
    nvocdialog.h \
    nvidiaapi.h \
    nanopoolapi.h \
    amdapi_adl.h \
    hashratecharview.h \
    piesliceeff.h \
    structures.h \
    urlapi.h

FORMS += \
        mainwindow.ui \
    helpdialog.ui \
    nvocdialog.ui

RC_ICONS += \
        eth_miner_lamp.ico

RESOURCES += \
    resources.qrc


win32: LIBS += -L'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.1/lib/x64/' -lnvml

INCLUDEPATH += 'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.1/include'
DEPENDPATH += 'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.1/include'

win32: INCLUDEPATH += $$PWD/nvapi

INCLUDEPATH += $$PWD/adl/include \
                jsoncpp/include

CONFIG  += openssl-linked
