#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <setjmp.h>

#include "cy_runtime.h"

void run()
{
    // Creating Object class
    CyClass* CyClassObject = CyClass_init(CY_NEW(CyClass));
    CY_ADD_METHOD(CyClassObject, M_i_init, _Object_i_init);
    CY_ADD_METHOD(CyClassObject, M_i_inc_i, _Object_i_inc_i);
    CY_ADD_METHOD(CyClassObject, M_i_dec_i, _Object_i_dec_i);

    // Creating Dummy class
    CyClass* CyClassDummy = CyClass_init(CY_NEW(CyClass));
    CY_SET_PARENT(CyClassDummy, CyClassObject);
    CY_ADD_METHOD(CyClassDummy, M_i_init, _Dummy_i_init);
    CY_ADD_METHOD(CyClassDummy, M_i_dummy, _Dummy_i_dummy);

    // Creating String class
    CyClass* CyClassString = CyClass_init(CY_NEW(CyClass));
    CY_SET_PARENT(CyClassString, CyClassObject);
    //CY_ADD_METHOD(CyClassString, M_i_init, _String_i_init);
    CY_ADD_METHOD(CyClassString, M_i_init_pb, _String_i_init_pb);
    CY_ADD_METHOD(CyClassString, M_i_concat_pb, _String_i_concat_pb);
    CY_ADD_METHOD(CyClassString, M_i_concat_pb_pb, _String_i_concat_pb_pb);
    CY_ADD_METHOD(CyClassString, M_i_add5shorts_s_s_s_s_s, _String_i_add5shorts_s_s_s_s_s);

    // Creating Accumulator class
    CyClass* CyClassAccumulator = CyClass_init(CY_NEW(CyClass));
    CY_SET_PARENT(CyClassAccumulator, CyClassObject);
    CY_ADD_METHOD(CyClassAccumulator, M_i_init, _Accumulator_i_init);
    CY_ADD_METHOD(CyClassAccumulator, M_i_add_i, _Accumulator_i_add_i);
    CY_ADD_METHOD(CyClassAccumulator, M_i_getValue, _Accumulator_i_getValue);

    // Using String object
    Cy_struct_String* str = CY_NEW(Cy_struct_String);
    CY_SET_CLASS(str, CyClassString);
    CY_INVOKE_ARGS(str, M_i_init_pb, "test");
    printf("%s\n", (char*)CY_INVOKE_ARGS(str, M_i_concat_pb, "-test1"));
    printf("%s\n", (char*)CY_INVOKE_ARGS(str, M_i_concat_pb_pb, "-test2", "-test3"));
    printf("%ld\n", (long)CY_INVOKE_ARGS(str, M_i_add5shorts_s_s_s_s_s, 1, 2, 3, 4, 5));

    // Using Dummy object
    Cy_struct_Dummy* dummy = CY_NEW(Cy_struct_Dummy);
    CY_SET_CLASS(dummy, CyClassDummy);
    CY_INVOKE_VOID(dummy, M_i_init);

    // Using Accumulator object
    Cy_struct_Accumulator* acc = CY_NEW(Cy_struct_Accumulator);
    CY_SET_CLASS(acc, CyClassAccumulator);
    CY_INVOKE_VOID(acc, M_i_init);
    CY_INVOKE_ARGS(acc, M_i_add_i, 10);
    CY_INVOKE_ARGS(acc, M_i_add_i, 30);
    CY_INVOKE_ARGS(acc, M_i_add_i, 2);
    printf("Accumulator = %d\n", (int)CY_INVOKE_VOID(acc, M_i_getValue));
}

int main(void)
{
    if (setjmp(env)) {
        printf("EXCEPTION !\n");
    } else {
        run();
    }
    return 0;
}
