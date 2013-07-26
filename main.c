#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>

#include "cy_runtime/runtime.h"


#include "classes/application.h"
#include "classes/string.h"
#include "classes/accumulator.h"
#include "classes/dummy.h"
#include "classes/dummy2.h"

void createClasses()
{
    CY_CLASS_CREATE(Application);
    CY_CLASS_EXTENDS(Application, Object);
    CY_CLASS_DEFINE_METHOD(Application, construct);
    CY_CLASS_DEFINE_METHOD(Application, run_i_ppb);

    CY_CLASS_CREATE(Dummy);
    CY_CLASS_EXTENDS(Dummy, Object);
    CY_CLASS_DEFINE_METHOD(Dummy, construct);
    CY_CLASS_DEFINE_METHOD(Dummy, dummy);

    CY_CLASS_CREATE(Dummy2);
    CY_CLASS_EXTENDS(Dummy2, Dummy);
    CY_CLASS_DEFINE_METHOD(Dummy2, construct);
    CY_CLASS_DEFINE_METHOD(Dummy2, dummy);

    CY_CLASS_CREATE(String);
    CY_CLASS_EXTENDS(String, Object);
    CY_CLASS_DEFINE_METHOD(String, construct);
    CY_CLASS_DEFINE_METHOD(String, construct_pb);
    CY_CLASS_DEFINE_METHOD(String, concat_pb);
    CY_CLASS_DEFINE_METHOD(String, concat_ZCString);
    CY_CLASS_DEFINE_METHOD(String, concat_pb_pb);
    CY_CLASS_DEFINE_METHOD(String, charAt_i);

    CY_CLASS_CREATE(Accumulator);
    CY_CLASS_EXTENDS(Accumulator, Object);
    CY_CLASS_DEFINE_METHOD(Accumulator, construct);
    CY_CLASS_DEFINE_METHOD(Accumulator, add_i);
    CY_CLASS_DEFINE_METHOD(Accumulator, getValue);
}

#pragma GCC diagnostic ignored "-Wunused-parameter"

int cy_main(int argc, char* argv[])
{
    Cy_struct_Application* app = CY_NEW(Application);
    CY_INVOKE(Cy_struct_Application*, Cy_class_Application, M_i_construct, app);
    CY_INVOKE(int, Cy_class_Application, M_i_run_i_ppb, app, argc, argv);
    return 0;
}

int main(int argc, char* argv[])
{
    cyrt_initialize();
    createClasses();
    if (!setjmp(env)) {
        cy_main(argc, argv);
    } else {
        printf("UNCAUGHT EXCEPTION !\n");
    }
    return 0;
}
