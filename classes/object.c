#include <stdio.h>

#include "object.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

void* _Object_i_construct(CyClass* cls, void* self)
{
    puts("Object.construct()");
    return self;
}
