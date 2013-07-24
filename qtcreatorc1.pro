TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    cy_runtime.c \
    classes/string.c \
    classes/dummy.c \
    classes/accumulator.c \
    classes/object.c \
    cy_runtime/class.c

HEADERS += \
    cy_runtime.h \
    cy_muids.h \
    cy_macros.h \
    classes/string.h \
    cy_classes.h \
    classes/dummy.h \
    classes/accumulator.h \
    classes/object.h \
    cy_runtime/class.h

