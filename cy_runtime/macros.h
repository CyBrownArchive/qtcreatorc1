#ifndef __CY_HELPERS__

#define Q(X) #X
#define QUOTE(X) Q(X)
#define CY_MALLOC(X) (X*)malloc(sizeof(X))

#define CY_INVOKE(TYPE, CLS, MUID, ...) ((TYPE (*)(void*, ...))cyrt_find_implementation(env, CLS, MUID))(CLS, __VA_ARGS__)

#define CY_CLASS_CREATE(NAME) Cy_class_##NAME = cyrt_class_init(CY_MALLOC(CyClass))
#define CY_CLASS_EXTENDS(CHILD, PARENT) cyrt_class_extends(Cy_class_##CHILD, Cy_class_##PARENT)
#define CY_CLASS_DEFINE_METHOD(CLASS, MANGLED_NAME) cyrt_class_define_method(Cy_class_##CLASS, M_i_##MANGLED_NAME, (void*(*)(void*, ...))_##CLASS##_i_##MANGLED_NAME)

#define CY_NEW(X) (Cy_struct_##X*)cyrt_object_set_class(malloc(sizeof(Cy_struct_##X)), Cy_class_##X)

#endif
