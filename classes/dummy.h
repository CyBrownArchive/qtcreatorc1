#ifndef __CY_CLASSES_DUMMY__
#define __CY_CLASSES_DUMMY__

#include "../cy_runtime.h"

typedef struct {
    Cy_struct_Object super;
} Cy_struct_Dummy;

Cy_struct_Dummy* _Dummy_i_init(Cy_struct_Dummy* self);
Cy_struct_Dummy* _Dummy_i_dummy(Cy_struct_Dummy* self);

#endif
