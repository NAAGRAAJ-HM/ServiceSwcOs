/*****************************************************/
/* File   : SwcServiceOs.cpp                         */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "infSwcServiceOs_EcuM.h"
#include "infSwcServiceOs_SchM.h"
#include "infSwcServiceOs_Os.h"
#include "infSwcServiceOs_Unused.h"

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
   ,  public infSwcServiceOs_Os
{
   public:
      FUNC(void, OS_CODE) InitFunction   (void);
      FUNC(void, OS_CODE) DeInitFunction (void);
      FUNC(void, OS_CODE) GetVersionInfo (void);
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
infEcuMClient*      gptrinfEcuMClient_SwcServiceOs = &SwcServiceOs;
infDcmClient*       gptrinfDcmClient_SwcServiceOs  = &SwcServiceOs;
infSchMClient*      gptrinfSchMClient_SwcServiceOs = &SwcServiceOs;
infSwcServiceOs_Os* gptrinfSwcServiceOs_Os;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, OS_CODE) module_SwcServiceOs::InitFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::DeInitFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::GetVersionInfo(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::MainFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::StartupHook(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::ShutdownHook(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::TASK_Idle(void){
   gptrinfSchMClient_EcuM->MainFunction();
   gptrinfSchMClient_NvM->MainFunction();
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

