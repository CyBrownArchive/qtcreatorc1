#ifndef __CY_CLASSES_OBJECT__
#define __CY_CLASSES_OBJECT__

#include "../cy_runtime/class.h"

typedef struct {
    CyClass* cls;
} Cy_struct_Object;

void* _Object_i_construct(void* self);

#endif
