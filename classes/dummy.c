#include <stdio.h>

#include "dummy.h"

Cy_struct_Dummy* _Dummy_i_construct(Cy_struct_Dummy* self, CyClass* cls)
{
    CY_INVOKE_VOID(self, cls->parent, M_i_construct);
    puts("Dummy.construct()");
    return self;
}

Cy_struct_Dummy* _Dummy_i_dummy(Cy_struct_Dummy* self, CyClass* cls)
{
    return self;
}
