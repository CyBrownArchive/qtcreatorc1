#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>

#include "cy_runtime/runtime.h"

void createClasses()
{
    Cy_class_Object = CyClass_init(CY_MALLOC(CyClass));
    CY_CLASS_DEFINE_METHOD(Cy_class_Object, M_i_construct, _Object_i_construct);

    Cy_class_Dummy = CyClass_init(CY_MALLOC(CyClass));
    CY_CLASS_EXTENDS(Cy_class_Dummy, Cy_class_Object);
    CY_CLASS_DEFINE_METHOD(Cy_class_Dummy, M_i_construct, _Dummy_i_construct);
    CY_CLASS_DEFINE_METHOD(Cy_class_Dummy, M_i_dummy, _Dummy_i_dummy);

    Cy_class_String = CyClass_init(CY_MALLOC(CyClass));
    CY_CLASS_EXTENDS(Cy_class_String, Cy_class_Object);
    CY_CLASS_DEFINE_METHOD(Cy_class_String, M_i_construct, _String_i_construct);
    CY_CLASS_DEFINE_METHOD(Cy_class_String, M_i_construct_pb, _String_i_construct_pb);
    CY_CLASS_DEFINE_METHOD(Cy_class_String, M_i_concat_pb, _String_i_concat_pb);
    CY_CLASS_DEFINE_METHOD(Cy_class_String, M_i_concat_ZCString, _String_i_concat_ZCString);
    CY_CLASS_DEFINE_METHOD(Cy_class_String, M_i_concat_pb_pb, _String_i_concat_pb_pb);
    CY_CLASS_DEFINE_METHOD(Cy_class_String, M_i_charAt_i, _String_i_charAt_i);

    Cy_class_Accumulator = CyClass_init(CY_MALLOC(CyClass));
    CY_CLASS_EXTENDS(Cy_class_Accumulator, Cy_class_Object);
    CY_CLASS_DEFINE_METHOD(Cy_class_Accumulator, M_i_construct, _Accumulator_i_construct);
    CY_CLASS_DEFINE_METHOD(Cy_class_Accumulator, M_i_add_i, _Accumulator_i_add_i);
    CY_CLASS_DEFINE_METHOD(Cy_class_Accumulator, M_i_getValue, _Accumulator_i_getValue);
}

void run()
{
    // Using String object
    Cy_struct_String* str1 = CY_NEW(String);
    CY_INVOKE_ARGS(str1, M_i_construct_pb, "Hello");
    Cy_struct_String* str2 = CY_INVOKE_ARGS(CY_NEW(String), M_i_construct_pb, " People");
    Cy_struct_String* str3 = (Cy_struct_String*)CY_INVOKE_ARGS(str1, M_i_concat_ZCString, str2);
    printf("%s\n", str3->data);
    Cy_struct_String* str4 = (Cy_struct_String*)CY_INVOKE_ARGS(str1, M_i_concat_pb_pb, ", ", " World");
    printf("%s\n", str4->data);
    printf("%c%c\n", (char)CY_INVOKE_ARGS(str4, M_i_charAt_i, 0), (char)CY_INVOKE_ARGS(str4, M_i_charAt_i, 8));

    // Using Dummy object
    Cy_struct_Dummy* dummy = CY_NEW(Dummy);
    CY_INVOKE_VOID(dummy, M_i_construct);

    // Using Accumulator object
    Cy_struct_Accumulator* acc = CY_NEW(Accumulator);
    CY_INVOKE_VOID(acc, M_i_construct);
    CY_INVOKE_ARGS(acc, M_i_add_i, 10);
    CY_INVOKE_ARGS(acc, M_i_add_i, 30);
    CY_INVOKE_ARGS(acc, M_i_add_i, 2);
    printf("Accumulator = %d\n", (int)CY_INVOKE_VOID(acc, M_i_getValue));
}

int main(void)
{
    createClasses();
    if (!setjmp(env)) {
        run();
    } else {
        printf("UNCAUGHT EXCEPTION !\n");
    }
    return 0;
}
