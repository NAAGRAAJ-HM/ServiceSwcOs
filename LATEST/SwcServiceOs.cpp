/*****************************************************/
/* File   : SwcServiceOs.cpp                         */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "SwcServiceOs_EcuM.h"
#include "SwcServiceOs_SchM.h"
#include "SwcServiceOs_Os.h"
#include "SwcServiceOs_Unused.h"

#include "NvM_SchM.h"
#include "EcuM_SchM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_SwcServiceOs:
      public abstract_module
   ,  public interface_SwcServiceOs_EcuM
   ,  public interface_SwcServiceOs_SchM
   ,  public interface_SwcServiceOs_Os
{
   public:
      FUNC(void, OS_CODE) InitFunction   (void);
      FUNC(void, OS_CODE) DeInitFunction (void);
      FUNC(void, OS_CODE) MainFunction   (void);
      FUNC(void, OS_CODE) StartupHook    (void);
      FUNC(void, OS_CODE) ShutdownHook   (void);
      FUNC(void, OS_CODE) TASK_Idle      (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_SwcServiceOs SwcServiceOs;

interface_SwcServiceOs_EcuM *EcuM_Client_ptr_SwcServiceOs = &SwcServiceOs;
interface_SwcServiceOs_SchM *SchM_Client_ptr_SwcServiceOs = &SwcServiceOs;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, OS_CODE) module_SwcServiceOs::InitFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::DeInitFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::MainFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::StartupHook(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::ShutdownHook(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::TASK_Idle(void){
   SchM_Client_ptr_EcuM->MainFunction();
   SchM_Client_ptr_NvM->MainFunction();
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

