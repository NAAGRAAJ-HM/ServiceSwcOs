/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
//#include "CfgSwcServiceOs.h"
#include "infSwcServiceOs_EcuM.h"
#include "infSwcServiceOs_Dcm.h"
#include "infSwcServiceOs_SchM.h"
#include "infSwcServiceOs_Os.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SWCSERVICEOS_AR_RELEASE_MAJOR_VERSION                                  4
#define SWCSERVICEOS_AR_RELEASE_MINOR_VERSION                                  3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SWCSERVICEOS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible SWCSERVICEOS_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(SWCSERVICEOS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible SWCSERVICEOS_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
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

   private:
      CONST(Std_TypeVersionInfo, SWCSERVICEOS_CONST) VersionInfo = {
            0x0000
         ,  0xFFFF
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_SwcServiceOs, SWCSERVICEOS_VAR) SwcServiceOs;
CONSTP2VAR(infEcuMClient, SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfEcuMClient_SwcServiceOs = &SwcServiceOs;
CONSTP2VAR(infDcmClient,  SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfDcmClient_SwcServiceOs  = &SwcServiceOs;
CONSTP2VAR(infSchMClient, SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfSchMClient_SwcServiceOs = &SwcServiceOs;
infSwcServiceOs_Os* gptrinfSwcServiceOs_Os;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, OS_CODE) module_SwcServiceOs::InitFunction(void){
   SwcServiceOs.IsInitDone = E_OK;
}

FUNC(void, OS_CODE) module_SwcServiceOs::DeInitFunction(void){
   SwcServiceOs.IsInitDone = E_NOT_OK;
}

FUNC(void, OS_CODE) module_SwcServiceOs::GetVersionInfo(void){
#if(STD_ON == SwcServiceOs_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, OS_CODE) module_SwcServiceOs::MainFunction(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::StartupHook(void){
}

FUNC(void, OS_CODE) module_SwcServiceOs::ShutdownHook(void){
}

#include "infNvM_SchM.h"
#include "infEcuM_SchM.h"

FUNC(void, OS_CODE) module_SwcServiceOs::TASK_Idle(void){
   gptrinfSchMClient_EcuM->MainFunction();
   gptrinfSchMClient_NvM->MainFunction();
}

#include "SwcServiceOs_Unused.h"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

