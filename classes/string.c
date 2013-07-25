#include <stdlib.h>
#include <string.h>

#include "string.h"

Cy_struct_String* _String_i_construct(Cy_struct_String* self)
{
    CY_INVOKE_SUPER_VOID(self, M_i_construct);
    //puts("String.construct()");
    self->data = strdup("");
    return self;
}

Cy_struct_String* _String_i_construct_pb(Cy_struct_String* self, char* str)
{
    CY_INVOKE_VOID(self, M_i_construct);
    self->data = strdup(str);
    return self;
}

char _String_i_charAt_i(Cy_struct_String* self, int offset)
{
    return self->data[offset];
}

Cy_struct_String* _String_i_concat_pb(Cy_struct_String* self, char* other)
{
    char* newData = (char*)malloc(strlen(self->data) + strlen(other) + 1);
    newData[0] = '\0';
    strcat(newData, self->data);
    strcat(newData, other);
    Cy_struct_String* result = CY_NEW(String);
    CY_INVOKE_ARGS(result, M_i_construct_pb, newData);
    return result;
}

Cy_struct_String* _String_i_concat_ZCString(Cy_struct_String* self, Cy_struct_String* other)
{
    return CY_INVOKE_ARGS(self, M_i_concat_pb, other->data);
}

Cy_struct_String* _String_i_concat_pb_pb(Cy_struct_String* self, char* str1, char* str2)
{
    return CY_INVOKE_ARGS(CY_INVOKE_ARGS(self, M_i_concat_pb, str1), M_i_concat_pb, str2);
}
