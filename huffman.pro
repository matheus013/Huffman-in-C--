#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T13:24:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = huffman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Huffman.cpp \
    ArrayFrequency.cpp \
    OpenFile.cpp \
    Node.cpp \
    FrequencyByte.cpp \
    HTree.cpp \
    Tree.cpp \
    Queue.cpp \
    Compress.cpp \
    File.cpp

HEADERS += \
    Node.h \
    FrequencyByte.h \
    OpenFile.h \
    ArrayFrequency.h \
    Huffman.h \
    HTree.h \
    Tree.h \
    Queue.h \
    Compress.h \
    File.h
