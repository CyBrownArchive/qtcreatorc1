#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#include "runtime.h"

jmp_buf env;

#pragma GCC diagnostic ignored "-Wunused-parameter"

void cyrt_initialize()
{
    CY_CLASS_CREATE(Object);
    CY_CLASS_DEFINE_METHOD(Object, construct);
}

CyClass* cyrt_class_init(CyClass* self)
{
    self->methodsCount = 0;
    self->parent = NULL;
    return self;
}

CyClass* cyrt_class_extends(CyClass* self, CyClass* parent)
{
    self->parent = parent;
    return self;
}

CyClass* cyrt_class_define_method(CyClass* self, cy_muid muid, void* (*implementation)(void*, ...))
{
    self->methods[self->methodsCount].muid = muid;
    self->methods[self->methodsCount].method = implementation;
    self->methodsCount++;
    return self;
}

void* cyrt_object_set_class(void* self, CyClass* cls)
{
    ((Cy_struct_Object*)self)->cls = cls;
    return self;
}

cyrt_func cyrt_find_implementation(jmp_buf env, CyClass* cls, cy_muid muid)
{
    unsigned int i;
    cyrt_func implementation = 0;

    while (cls && !implementation) {
        for (i = 0; i < cls->methodsCount && !implementation; i++) {
            if (cls->methods[i].muid == muid) {
                implementation = cls->methods[i].method;
            }
        }
        cls = cls->parent;
    }
    if (!implementation) {
        printf("Not found: %d\n", muid);
        longjmp(env, 1);
    }
    return implementation;
}

CyClass* Cy_class_Object;

void* _Object_i_construct(CyClass* cls, void* self)
{
    return self;
}
