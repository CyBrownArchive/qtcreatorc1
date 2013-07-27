TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    classes/string.c \
    classes/dummy.c \
    classes/accumulator.c \
    cy_runtime/runtime.c \
    classes/dummy2.c \
    classes/application.c \
    taskqueue/taskqueue.c

HEADERS += \
    cy_muids.h \
    cy_macros.h \
    classes/string.h \
    classes/dummy.h \
    classes/accumulator.h \
    cy_runtime/runtime.h \
    classes/dummy2.h \
    classes/application.h \
    taskqueue/taskqueue.h

