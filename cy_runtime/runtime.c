#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#include "runtime.h"

jmp_buf env;

#pragma GCC diagnostic ignored "-Wunused-parameter"

// CyClass

CyClass* CyClass_init(CyClass* self)
{
    self->methodsCount = 0;
    self->parent = NULL;
    return self;
}

CyClass* CyClass_setParent(CyClass* self, CyClass* parent)
{
    self->parent = parent;
    return self;
}

CyClass* CyClass_addMethod(CyClass* self, cy_muid muid, void* (*implementation)(void*, ...))
{
    self->methods[self->methodsCount].muid = muid;
    self->methods[self->methodsCount].method = implementation;
    self->methodsCount++;
    return self;
}

// CyObject

void* CyObject_setClass(void* self, CyClass* cls)
{
    ((Cy_struct_Object*)self)->cls = cls;
    return self;
}

int cy_nop(void* self, int a) {
    return 0;
}

cy_functionPointer cy_findSuperImplementation(jmp_buf env, CyClass* clsb, cy_muid muid)
{
    unsigned int i;
    cy_functionPointer implementation = (void* (*)(void*, ...))cy_nop;
    int found = 0;
    CyClass* cls = clsb->parent;

    while (cls && !found) {
        for (i = 0; i < cls->methodsCount; i++) {
            if (cls->methods[i].muid == muid) {
                implementation = cls->methods[i].method;
                found = 1;
            }
        }
        cls = cls->parent;
    }
    if (!found) {
        printf("Not found: %d\n", muid);
        longjmp(env, 1);
    }
    return implementation;
}

cy_functionPointer cy_findImplementation(jmp_buf env, CyClass* cls, cy_muid muid)
{
    unsigned int i;
    for (i = 0; i < cls->methodsCount; i++) {
        if (cls->methods[i].muid == muid) {
            return cls->methods[i].method;
        }
    }
    return cy_findSuperImplementation(env, cls, muid);
}
