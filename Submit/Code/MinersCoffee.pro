#-------------------------------------------------
#
# Project created by QtCreator 2021-03-28T11:47:49
#
#-------------------------------------------------

QT += \
    core \
    gui \
    network \
    charts \
    testlib \
    sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt warn_on depend_includepath testcase

TARGET = MinersCoffee
TEMPLATE = app
VERSION = 1.0

DEFINES += QT_DEPRECATED_WARNINGS NVIDIA AMD

SOURCES += \
    chartview.cpp \
    database.cpp \
    gpumonitor.cpp \
    helppage.cpp \
    jsonparser.cpp \
    main.cpp \
    mainwindow.cpp \
    minerprocess.cpp \
    nvidianvml.cpp \
    nvidiaapi.cpp \
    nvocpage.cpp \
    structures.cpp \
    urlapi.cpp \
    wincmd.cpp \
    helper.cpp

HEADERS += \
    chartview.h \
    constants.h \
    database.h \
    gpumonitor.h \
    helppage.h \
    jsonparser.h \
    mainwindow.h \
    minerprocess.h \
    nvidianvml.h \
    nvidiaapi.h \
    nvocpage.h \
    structures.h \
    urlapi.h \
    wincmd.h \
    helper.h

FORMS += \
    mainwindow.ui

RC_ICONS += \
    minerscoffee.ico

RESOURCES += \
    resources.qrc


win32: LIBS += -L'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.1/lib/x64/' -lnvml \
                $$PWD/lib/libmysql.lib

INCLUDEPATH += 'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.1/include'
DEPENDPATH += 'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.1/include'

win32: INCLUDEPATH += $$PWD/nvapi

INCLUDEPATH += $$PWD/adl/include \
                jsoncpp/include

CONFIG  += openssl-linked
