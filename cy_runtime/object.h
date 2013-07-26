#ifndef __CY_CLASSES_OBJECT__
#define __CY_CLASSES_OBJECT__

#include "class.h"

typedef struct {
    CyClass* cls;
} Cy_struct_Object;

extern CyClass* Cy_class_Object;

void* _Object_i_construct(CyClass* cls, void* self);

#endif
