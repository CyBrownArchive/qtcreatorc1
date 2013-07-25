#include <stdlib.h>
#include <string.h>

#include "string.h"

CyClass* Cy_class_String;

#pragma GCC diagnostic ignored "-Wunused-parameter"

Cy_struct_String* _String_i_construct(CyClass* cls, Cy_struct_String* self)
{
    CY_INVOKE(void*, cls->parent, M_i_construct, self);
    self->data = strdup("");
    return self;
}

Cy_struct_String* _String_i_construct_pb(CyClass* cls, Cy_struct_String* self, char* str)
{
    CY_INVOKE(void*, cls, M_i_construct, self);
    self->data = strdup(str);
    return self;
}

char _String_i_charAt_i(CyClass* cls, Cy_struct_String* self, int offset)
{
    return self->data[offset];
}

Cy_struct_String* _String_i_concat_pb(CyClass* cls, Cy_struct_String* self, char* other)
{
    char* newData = (char*)malloc(strlen(self->data) + strlen(other) + 1);
    newData[0] = '\0';
    strcat(newData, self->data);
    strcat(newData, other);
    Cy_struct_String* result = CY_NEW(String);
    CY_INVOKE(void*, cls, M_i_construct_pb, result, newData);
    return result;
}

Cy_struct_String* _String_i_concat_ZCString(CyClass* cls, Cy_struct_String* self, Cy_struct_String* other)
{
    return CY_INVOKE(void*, cls, M_i_concat_pb, self, other->data);
}

Cy_struct_String* _String_i_concat_pb_pb(CyClass* cls, Cy_struct_String* self, char* str1, char* str2)
{
    return CY_INVOKE(Cy_struct_String*, cls, M_i_concat_pb, CY_INVOKE(Cy_struct_String*, cls, M_i_concat_pb, self, str1), str2);
}
