#include "accumulator.h"

Cy_struct_Accumulator* _Accumulator_i_construct(Cy_struct_Accumulator* self)
{
    CY_INVOKE_SUPER_VOID(self, M_i_construct);
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
