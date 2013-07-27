#ifndef __CY_CLASSES_Application__
#define __CY_CLASSES_Application__

#include "../cy_runtime/runtime.h"
#include "string.h"

typedef struct {
    Cy_struct_Object super;
    Cy_struct_String* name;
    int argc;
    char** argv;
} Cy_struct_Application;

extern CyClass* Cy_class_Application;

Cy_struct_Application* _Application_i_construct_i_ppb(CyClass* cls, Cy_struct_Application* self, int argc, char* argv[]);
int _Application_i_run(CyClass* cls, Cy_struct_Application* self);

#endif
