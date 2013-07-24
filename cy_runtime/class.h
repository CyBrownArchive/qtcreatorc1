#ifndef __CY_RUNTIME_CLASS__
#define __CY_RUNTIME_CLASS__

#include "../cy_muids.h"

typedef struct {
    cy_muid muid;
    void* (*method)(void* self, ...);
} CyMethodEntry;

typedef struct _CyClass {
    struct _CyClass* parent;
    unsigned int methodsCount;
    CyMethodEntry methods[10];
} CyClass;

#endif
