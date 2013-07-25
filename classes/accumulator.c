#include "accumulator.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

Cy_struct_Accumulator* _Accumulator_i_construct(CyClass* cls, Cy_struct_Accumulator* self)
{
    CY_INVOKE(void*, cls->parent, M_i_construct, self);
    self->value = 0;
    return self;
}

void _Accumulator_i_add_i(CyClass* cls, Cy_struct_Accumulator* self, int value)
{
    self->value += value;
}

int _Accumulator_i_getValue(CyClass* cls, Cy_struct_Accumulator* self)
{
    return self->value;
}
