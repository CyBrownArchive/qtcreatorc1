#include <stdio.h>
#include <stdlib.h>

#include "accumulator.h"

Cy_struct_Accumulator* _Accumulator_i_init(Cy_struct_Accumulator* self)
{
    CY_INVOKE_SUPER_VOID(self, M_i_init);
    self->value = 0;
    return self;
}

void _Accumulator_i_add_i(Cy_struct_Accumulator* self, int value)
{
    self->value += value;
}

int _Accumulator_i_getValue(Cy_struct_Accumulator* self)
{
    return self->value;
}
