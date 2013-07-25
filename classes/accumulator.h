#ifndef __CY_CLASSES_ACCUMULATOR__
#define __CY_CLASSES_ACCUMULATOR__

#include "object.h"

typedef struct {
    Cy_struct_Object super;
    int value;
} Cy_struct_Accumulator;

#include "../cy_runtime/runtime.h"

Cy_struct_Accumulator* _Accumulator_i_construct(CyClass* cls, Cy_struct_Accumulator* self);
void _Accumulator_i_add_i(CyClass* cls, Cy_struct_Accumulator* self, int value);
int _Accumulator_i_getValue(CyClass* cls, Cy_struct_Accumulator* self);

#endif
