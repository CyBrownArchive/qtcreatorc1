#include <stdio.h>

#include "dummy.h"

Cy_struct_Dummy* _Dummy_i_construct(Cy_struct_Dummy* self)
{
    CY_INVOKE_SUPER_VOID(self, M_i_construct);
    puts("Dummy.construct()");
    return self;
}

Cy_struct_Dummy* _Dummy_i_dummy(Cy_struct_Dummy* self)
{
    return self;
}
