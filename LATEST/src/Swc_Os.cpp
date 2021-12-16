#include "Swc_Os.h"

#include "EcuM.h"

class_Swc_Os Swc_Os;

void class_Swc_Os::StartupHook(void){
}

void class_Swc_Os::ShutdownHook(void){
}

void class_Swc_Os::TASK_Idle(void){
   EcuM.MainFunction();
}

