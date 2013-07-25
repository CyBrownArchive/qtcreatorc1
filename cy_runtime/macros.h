#ifndef __CY_HELPERS__


#define Q(X) #X
#define QUOTE(X) Q(X)
#define CY_MALLOC(X) (X*)malloc(sizeof(X))


#define CY_INVOKE_VOID(SELF, MUID) cy_findImplementation(env, SELF, MUID)(SELF)
#define CY_INVOKE_ARGS(SELF, MUID, ...) cy_findImplementation(env, SELF, MUID)(SELF, __VA_ARGS__)
#define CY_INVOKE_SUPER_VOID(SELF, MUID) cy_findSuperImplementation(env, SELF, MUID)(SELF)
#define CY_INVOKE_SUPER_ARGS(SELF, MUID, ...) cy_findSuperImplementation(env, SELF, MUID)(SELF, __VA_ARGS__)

#define CY_CLASS_EXTENDS(CHILD, PARENT) CyClass_setParent(CHILD, PARENT);
#define CY_CLASS_DEFINE_METHOD(SELF, MUID, IMPL) CyClass_addMethod(SELF, MUID, (void*(*)(void*, ...))IMPL);

#define CY_NEW(X) (Cy_struct_##X*)CyObject_setClass(malloc(sizeof(Cy_struct_##X)), Cy_class_##X)


#endif
