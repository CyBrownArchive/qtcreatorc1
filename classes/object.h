#ifndef __CY_CLASSES_OBJECT__
#define __CY_CLASSES_OBJECT__

#include "../cy_runtime/class.h"

typedef struct {
    CyClass* cls;
} Cy_struct_Object;

void* _Object_i_init(void* self);
int   _Object_i_inc_i(void* self, int a);
int   _Object_i_dec_i(void* self, int a);
int   _Object_i_inc2_i(void* self, int a);
char* _Object_i_str_pb(void* self, char* a);

#endif
