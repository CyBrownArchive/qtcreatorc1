#include <stdio.h>

#include "dummy2.h"

Cy_struct_Dummy2* _Dummy2_i_construct(Cy_struct_Dummy2* self, CyClass* cls)
{
    CY_INVOKE_VOID(self, cls->parent, M_i_construct);
    puts("Dummy2.construct()");
    return self;
}

Cy_struct_Dummy2* _Dummy2_i_dummy(Cy_struct_Dummy2* self, CyClass* cls)
{
    return self;
}
