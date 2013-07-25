#include <stdio.h>

#include "dummy2.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

CyClass* Cy_class_Dummy2;

Cy_struct_Dummy2* _Dummy2_i_construct(CyClass* cls, Cy_struct_Dummy2* self)
{
    CY_INVOKE(void*, cls->parent, M_i_construct, self);
    puts("Dummy2.construct()");
    return self;
}

Cy_struct_Dummy2* _Dummy2_i_dummy(CyClass* cls, Cy_struct_Dummy2* self)
{
    return self;
}
