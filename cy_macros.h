#ifndef __CY_HELPERS__

#define CY_NEW(X) (X*)malloc(sizeof(X))
#define CY_INVOKE_VOID(SELF, MUID) cy_findImplementation(env, SELF, MUID)(SELF)
#define CY_INVOKE_ARGS(SELF, MUID, ...) cy_findImplementation(env, SELF, MUID)(SELF, __VA_ARGS__)
#define CY_INVOKE_SUPER_VOID(SELF, MUID) cy_findSuperImplementation(env, SELF, MUID)(SELF)
#define CY_INVOKE_SUPER_ARGS(SELF, MUID, ...) cy_findSuperImplementation(env, SELF, MUID)(SELF, __VA_ARGS__)
#define CY_SET_PARENT(CHILD, PARENT) CyClass_setParent(CHILD, PARENT);
#define CY_SET_CLASS(OBJECT, CLASS) CyObject_setClass(OBJECT, CLASS);
#define CY_ADD_METHOD(SELF, MUID, IMPL) CyClass_addMethod(SELF, MUID, (void*(*)(void*, ...))IMPL);

#endif
