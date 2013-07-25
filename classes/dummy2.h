#ifndef __CY_CLASSES_DUMMY2__
#define __CY_CLASSES_DUMMY2__

#include "../cy_runtime/runtime.h"
#include "dummy.h"

typedef struct {
    Cy_struct_Dummy super;
} Cy_struct_Dummy2;

extern CyClass* Cy_class_Dummy2;

Cy_struct_Dummy2* _Dummy2_i_construct(CyClass* cls, Cy_struct_Dummy2* self);
Cy_struct_Dummy2* _Dummy2_i_dummy(CyClass* cls, Cy_struct_Dummy2* self);

#endif
