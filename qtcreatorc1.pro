TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    classes/string.c \
    classes/dummy.c \
    classes/accumulator.c \
    classes/object.c \
    cy_runtime/runtime.c \
    classes/dummy2.c \
    global_classes.c

HEADERS += \
    cy_muids.h \
    cy_macros.h \
    classes/string.h \
    cy_classes.h \
    classes/dummy.h \
    classes/accumulator.h \
    classes/object.h \
    cy_runtime/class.h \
    cy_runtime/runtime.h \
    cy_runtime/macros.h \
    classes/dummy2.h \
    global_classes.h

