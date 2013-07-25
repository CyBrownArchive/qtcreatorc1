#ifndef __CY_CLASSES_DUMMY__
#define __CY_CLASSES_DUMMY__

#include "object.h"

typedef struct {
    Cy_struct_Object super;
} Cy_struct_Dummy;

#include "../cy_runtime/runtime.h"

Cy_struct_Dummy* _Dummy_i_construct(CyClass* cls, Cy_struct_Dummy* self);
Cy_struct_Dummy* _Dummy_i_dummy(CyClass* cls, Cy_struct_Dummy* self);

#endif
