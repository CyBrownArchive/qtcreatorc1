#ifndef __CY_RUNTIME__
#define __CY_RUNTIME__

#include <setjmp.h>

extern jmp_buf env;

#define CY_INVOKE(TYPE, CLS, MUID, ...) ((TYPE (*)(void*, ...))cyrt_find_implementation(env, CLS, MUID))(CLS, __VA_ARGS__)
#define CY_CLASS_CREATE(NAME) Cy_class_##NAME = cyrt_class_init((CyClass*)malloc(sizeof(CyClass)))
#define CY_CLASS_EXTENDS(CHILD, PARENT) cyrt_class_extends(Cy_class_##CHILD, Cy_class_##PARENT)
#define CY_CLASS_DEFINE_METHOD(CLASS, MANGLED_NAME) cyrt_class_define_method(Cy_class_##CLASS, M_i_##MANGLED_NAME, (void*(*)(void*, ...))_##CLASS##_i_##MANGLED_NAME)
#define CY_NEW(X) (Cy_struct_##X*)cyrt_object_set_class(malloc(sizeof(Cy_struct_##X)), Cy_class_##X)

#include "../cy_muids.h"

typedef struct {
    cy_muid muid;
    void* (*method)(void* self, ...);
} CyMethodEntry;

typedef struct _CyClass {
    struct _CyClass* parent;
    unsigned int methodsCount;
    CyMethodEntry methods[10];
} CyClass;

// Base Object class

typedef struct {
    CyClass* cls;
} Cy_struct_Object;

extern CyClass* Cy_class_Object;

void* _Object_i_construct(CyClass* cls, void* self);

// Runtime functions

typedef void* (*cyrt_func)(void*, ...);

void      cyrt_initialize();
CyClass*  cyrt_class_init(CyClass* self);
CyClass*  cyrt_class_extends(CyClass* self, CyClass* parent);
CyClass*  cyrt_class_define_method(CyClass* self, cy_muid muid, void* (*implementation)(void*, ...));
void*     cyrt_object_set_class(void* self, CyClass* cls);
cyrt_func cyrt_find_implementation(jmp_buf env, CyClass* cls, cy_muid muid);

#endif
