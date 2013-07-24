#include <stdio.h>
#include <stdlib.h>

#include "dummy.h"

Cy_struct_Dummy* _Dummy_i_init(Cy_struct_Dummy* self)
{
    CY_INVOKE_SUPER_VOID(self, M_i_init);
    puts("Dummy.init()");
    return self;
}

Cy_struct_Dummy* _Dummy_i_dummy(Cy_struct_Dummy* self)
{
    return self;
}
