QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialSender
TEMPLATE = app

SOURCES += \
    main.cpp \
    SerialSender.cpp

HEADERS += \
    SerialSender.h

FORMS += \
    SerialSender.ui

