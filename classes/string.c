#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

Cy_struct_String* _String_i_init(Cy_struct_String* self)
{
    CY_INVOKE_SUPER_VOID(self, M_i_init);
    puts("String.init()");
    self->data = strdup("");
    return self;
}

Cy_struct_String* _String_i_init_pb(Cy_struct_String* self, char* str)
{
    CY_INVOKE_VOID(self, M_i_init);
    puts("String.init(b*)");
    self->data = strdup(str);
    return self;
}

long _String_i_add5shorts_s_s_s_s_s(Cy_struct_String* self, short a, short b, short c, short d, short e)
{
    return a + b + c + d + e;
}

char* _String_i_concat_pb(Cy_struct_String* self, char* str)
{
    char* newData = (char*)malloc(strlen(self->data) + strlen(str) + 1);
    strcpy(newData, self->data);
    strcat(newData, str);
    self->data = newData;
    return self->data;
}

char* _String_i_concat_pb_pb(Cy_struct_String* self, char* str1, char* str2)
{
    char* newData = (char*)malloc(strlen(self->data) + strlen(str1) + strlen(str2) + 1);
    strcpy(newData, self->data);
    strcat(newData, str1);
    strcat(newData, str2);
    self->data = newData;
    return self->data;
}
