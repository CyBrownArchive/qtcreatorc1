#include "object.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

CyClass* Cy_class_Object;

void* _Object_i_construct(CyClass* cls, void* self)
{
    return self;
}
