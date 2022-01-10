#pragma once

#include "Std_Types.h"

class class_Swc_Os{
   public:
      void StartupHook  (void);
      void ShutdownHook (void);
      void TASK_Idle    (void);
};

extern class_Swc_Os Swc_Os;

