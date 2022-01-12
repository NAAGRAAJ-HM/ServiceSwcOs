#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Swc_Os.h"

class class_Swc_Os{
   public:
      FUNC(void, SWC_OS_CODE) StartupHook  (void);
      FUNC(void, SWC_OS_CODE) ShutdownHook (void);
      FUNC(void, SWC_OS_CODE) TASK_Idle    (void);
};

extern class_Swc_Os Swc_Os;

