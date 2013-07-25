#include <stdio.h>

#include "dummy.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

Cy_struct_Dummy* _Dummy_i_construct(CyClass* cls, Cy_struct_Dummy* self)
{
    CY_INVOKE(void*, cls->parent, M_i_construct, self);
    puts("Dummy.construct()");
    return self;
}

Cy_struct_Dummy* _Dummy_i_dummy(CyClass* cls, Cy_struct_Dummy* self)
{
    return self;
}
