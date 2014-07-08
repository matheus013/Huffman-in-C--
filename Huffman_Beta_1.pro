#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T13:24:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Huffman_Beta_1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Huffman.cpp \
    ArrayFrequency.cpp \
    Tree.cpp \
    OpenFile.cpp \
    Node.cpp \
    FrequencyByte.cpp \
    CreateHuff.cpp

HEADERS += \
    Tree.h \
    Node.h \
    FrequencyByte.h \
    OpenFile.h \
    ArrayFrequency.h \
    Huffman.h \
    CreateHuff.h
