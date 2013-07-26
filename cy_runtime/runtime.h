#ifndef __CY_RUNTIME__
#define __CY_RUNTIME__

#include <setjmp.h>

extern jmp_buf env;

#include "macros.h"
#include "../cy_muids.h"
#include "class.h"
#include "object.h"

typedef void* (*cyrt_func)(void*, ...);

void      cyrt_initialize();
CyClass*  cyrt_class_init(CyClass* self);
CyClass*  cyrt_class_extends(CyClass* self, CyClass* parent);
CyClass*  cyrt_class_define_method(CyClass* self, cy_muid muid, void* (*implementation)(void*, ...));
void*     cyrt_object_set_class(void* self, CyClass* cls);
cyrt_func cyrt_find_implementation(jmp_buf env, CyClass* cls, cy_muid muid);

#endif
