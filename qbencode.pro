TEMPLATE = lib
CONFIG += c++14 staticlib

QMAKE_CFLAGS += -std=c99

SOURCES += QBencode.cpp \
    heapless-bencode/bencode.c

HEADERS += heapless-bencode/bencode.h \
    QBencode.h
