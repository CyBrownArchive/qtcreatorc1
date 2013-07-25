#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>

#include "cy_runtime/runtime.h"

void createClasses()
{
    CY_CLASS_CREATE(Object);
    CY_CLASS_DEFINE_METHOD(Object, construct);

    CY_CLASS_CREATE_EXTENDS(Dummy, Object);
    CY_CLASS_DEFINE_METHOD(Dummy, construct);
    CY_CLASS_DEFINE_METHOD(Dummy, dummy);

    CY_CLASS_CREATE_EXTENDS(Dummy2, Dummy);
    CY_CLASS_DEFINE_METHOD(Dummy2, construct);
    CY_CLASS_DEFINE_METHOD(Dummy2, dummy);

    CY_CLASS_CREATE_EXTENDS(String, Object);
    CY_CLASS_DEFINE_METHOD(String, construct);
    CY_CLASS_DEFINE_METHOD(String, construct_pb);
    CY_CLASS_DEFINE_METHOD(String, concat_pb);
    CY_CLASS_DEFINE_METHOD(String, concat_ZCString);
    CY_CLASS_DEFINE_METHOD(String, concat_pb_pb);
    CY_CLASS_DEFINE_METHOD(String, charAt_i);

    CY_CLASS_CREATE_EXTENDS(Accumulator, Object);
    CY_CLASS_DEFINE_METHOD(Accumulator, construct);
    CY_CLASS_DEFINE_METHOD(Accumulator, add_i);
    CY_CLASS_DEFINE_METHOD(Accumulator, getValue);
}

int cy_main(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    createClasses();
    if (!setjmp(env)) {
        cy_main(argc, argv);
    } else {
        printf("UNCAUGHT EXCEPTION !\n");
    }
    return 0;
}

#pragma GCC diagnostic ignored "-Wunused-parameter"

int cy_main(int argc, char* argv[])
{
    // Using String object
    Cy_struct_String* str1 = CY_NEW(String);
    CY_INVOKE(void*, Cy_class_String, M_i_construct_pb, str1, "Hello");
    Cy_struct_String* str2 = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_construct_pb, CY_NEW(String), " People");
    Cy_struct_String* str3 = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_concat_ZCString, str1, str2);
    printf("%s\n", str3->data);
    Cy_struct_String* str4 = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_concat_pb_pb, str1, ", ", "World");
    printf("%s\n", str4->data);
    printf("%c%c\n", CY_INVOKE(char, Cy_class_String, M_i_charAt_i, str4, 0), CY_INVOKE(char, Cy_class_String, M_i_charAt_i, str4, 7));

    // Using Dummy object
    Cy_struct_Dummy* dummy = CY_NEW(Dummy);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Dummy, M_i_construct, dummy);

    // Using Accumulator object
    Cy_struct_Accumulator* acc = CY_NEW(Accumulator);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_construct, acc);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_add_i, acc, 10);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_add_i, acc, 30);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_add_i, acc, 2);
    printf("Accumulator = %d\n", CY_INVOKE(int, Cy_class_Accumulator, M_i_getValue, acc));

    // Using Dummy2 object
    Cy_struct_Dummy2* dummy2 = CY_NEW(Dummy2);
    CY_INVOKE(Cy_struct_Dummy2*, Cy_class_Dummy2, M_i_construct, dummy2);

    return 0;
}
