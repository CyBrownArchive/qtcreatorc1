#include <stdio.h>
#include <stdlib.h>

#include "app.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

CyClass* Cy_class_App;

Cy_struct_App* _App_i_construct(CyClass* cls, Cy_struct_App* self)
{
    CY_INVOKE(void*, cls->parent, M_i_construct, self);
    self->name = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_construct_pb, CY_NEW(String), "NoTitle");
    puts("App Created !!");
    return self;
}

int _App_i_run(CyClass* cls, Cy_struct_App* self)
{
    printf("App %s Running !!\n", self->name->data);
    return 0;
}
