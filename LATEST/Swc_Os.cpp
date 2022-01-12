#include "Swc_Os.h"

#include "EcuM.h"
#include "NvM.h"

class_Swc_Os Swc_Os;

FUNC(void, SWC_OS_CODE) class_Swc_Os::StartupHook(void){
}

FUNC(void, SWC_OS_CODE) class_Swc_Os::ShutdownHook(void){
}

FUNC(void, SWC_OS_CODE) class_Swc_Os::TASK_Idle(void){
   EcuM.MainFunction();
   NvM.MainFunction();
}

