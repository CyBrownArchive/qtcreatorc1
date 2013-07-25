#ifndef __CY_HELPERS__

#define Q(X) #X
#define QUOTE(X) Q(X)
#define CY_MALLOC(X) (X*)malloc(sizeof(X))

#define CY_INVOKE_VOID(SELF, CLS, MUID) cy_findImplementation(env, CLS, MUID)(SELF, CLS)
#define CY_INVOKE_ARGS(SELF, CLS, MUID, ...) cy_findImplementation(env, CLS, MUID)(SELF, CLS, __VA_ARGS__)

#define CY_CLASS_CREATE(NAME) Cy_class_##NAME = CyClass_init(CY_MALLOC(CyClass))
#define CY_CLASS_EXTENDS(CHILD, PARENT) CyClass_setParent(Cy_class_##CHILD, Cy_class_##PARENT)
#define CY_CLASS_CREATE_EXTENDS(NAME, PARENT) Cy_class_##NAME = CyClass_setParent(CyClass_init(CY_MALLOC(CyClass)), Cy_class_##PARENT)
#define CY_CLASS_DEFINE_METHOD(CLASS, MANGLED_NAME) CyClass_addMethod(Cy_class_##CLASS, M_i_##MANGLED_NAME, (void*(*)(void*, ...))_##CLASS##_i_##MANGLED_NAME)

#define CY_NEW(X) (Cy_struct_##X*)CyObject_setClass(malloc(sizeof(Cy_struct_##X)), Cy_class_##X)

#endif
