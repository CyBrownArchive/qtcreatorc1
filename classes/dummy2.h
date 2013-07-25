#ifndef __CY_CLASSES_DUMMY2__
#define __CY_CLASSES_DUMMY2__

#include "dummy.h"

typedef struct {
    Cy_struct_Dummy super;
} Cy_struct_Dummy2;

#include "../cy_runtime/runtime.h"

Cy_struct_Dummy2* _Dummy2_i_construct(Cy_struct_Dummy2* self, CyClass* cls);
Cy_struct_Dummy2* _Dummy2_i_dummy(Cy_struct_Dummy2* self, CyClass* cls);

#endif
