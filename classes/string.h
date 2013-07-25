#ifndef __CY_CLASSES_STRING__
#define __CY_CLASSES_STRING__

#include "object.h"

typedef struct {
    Cy_struct_Object super;
    char* data;
} Cy_struct_String;

#include "../cy_runtime/runtime.h"

Cy_struct_String* _String_i_construct(Cy_struct_String* self, CyClass* cls);
Cy_struct_String* _String_i_construct_pb(Cy_struct_String* self, CyClass* cls, char* str);
char _String_i_charAt_i(Cy_struct_String* self, CyClass* cls, int offset);
Cy_struct_String* _String_i_concat_pb(Cy_struct_String* self, CyClass* cls, char* other);
Cy_struct_String* _String_i_concat_ZCString(Cy_struct_String* self, CyClass* cls, Cy_struct_String* other);
Cy_struct_String* _String_i_concat_pb_pb(Cy_struct_String* self, CyClass* cls, char* str1, char* str2);

#endif
