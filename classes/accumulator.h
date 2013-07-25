#ifndef __CY_CLASSES_ACCUMULATOR__
#define __CY_CLASSES_ACCUMULATOR__

#include "../cy_runtime/runtime.h"

typedef struct {
    Cy_struct_Object super;
    int value;
} Cy_struct_Accumulator;

Cy_struct_Accumulator* _Accumulator_i_construct(Cy_struct_Accumulator* self);
void _Accumulator_i_add_i(Cy_struct_Accumulator* self, int value);
int _Accumulator_i_getValue(Cy_struct_Accumulator* self);

#endif
