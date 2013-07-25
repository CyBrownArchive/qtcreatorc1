#ifndef __CY_CLASSES_APP__
#define __CY_CLASSES_APP__

#include "../cy_runtime/runtime.h"
#include "string.h"

typedef struct {
    Cy_struct_Object super;
    Cy_struct_String* name;
} Cy_struct_App;

extern CyClass* Cy_class_App;

Cy_struct_App* _App_i_construct(CyClass* cls, Cy_struct_App* self);
int _App_i_run(CyClass* cls, Cy_struct_App* self);

#endif
