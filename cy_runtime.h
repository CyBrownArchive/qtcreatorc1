#ifndef __CY_RUNTIME__
#define __CY_RUNTIME__

#include <setjmp.h>

extern jmp_buf env;

#include "cy_macros.h"
#include "cy_muids.h"
#include "cy_runtime/class.h"

typedef void* (*cy_functionPointer)(void*, ...);

CyClass* CyClass_init(CyClass* self);
CyClass* CyClass_setParent(CyClass* self, CyClass* parent);
CyClass* CyClass_addMethod(CyClass* self, cy_muid muid, void* (*implementation)(void*, ...));
void CyObject_setClass(void* self, CyClass* cls);

cy_functionPointer cy_findImplementation(jmp_buf env, void* object, cy_muid muid);
cy_functionPointer cy_findSuperImplementation(jmp_buf env, void* object, cy_muid muid);

#include "cy_classes.h"

#endif
