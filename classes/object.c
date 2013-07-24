#include <stdio.h>
#include <stdlib.h>

#include "object.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

void* _Object_i_init(void* self)
{
    puts("Object.init()");
    return self;
}

int _Object_i_inc_i(void* self, int a)
{
    return a + 1;
}

int _Object_i_dec_i(void* self, int a)
{
    return a - 1;
}

int _Object_i_inc2_i(void* self, int a)
{
    return a + 2;
}

char* _Object_i_str_pb(void* self, char* a)
{
    return a;
}
