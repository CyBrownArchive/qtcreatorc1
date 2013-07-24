#ifndef __CY_CLASSES_STRING__
#define __CY_CLASSES_STRING__

#include "../cy_runtime.h"

typedef struct {
    Cy_struct_Object super;
    char* data;
} Cy_struct_String;

Cy_struct_String* _String_i_init(Cy_struct_String* self);
Cy_struct_String* _String_i_init_pb(Cy_struct_String* self, char* str);
char* _String_i_concat_pb(Cy_struct_String* self, char* str);
char* _String_i_concat_pb_pb(Cy_struct_String* self, char* str1, char* str2);
long  _String_i_add5shorts_s_s_s_s_s(Cy_struct_String* self, short a, short b, short c, short d, short e);

#endif
