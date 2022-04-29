/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
//#include "CfgSwcServiceOs.hpp"
#include "SwcServiceOs_core.hpp"
#include "infSwcServiceOs.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SWCSERVICEOS_AR_RELEASE_VERSION_MAJOR                                  4
#define SWCSERVICEOS_AR_RELEASE_VERSION_MINOR                                  3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SWCSERVICEOS_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SWCSERVICEOS_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SWCSERVICEOS_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SWCSERVICEOS_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_SwcServiceOs:
      public abstract_module
      //TBD: move to infxxx.hpp?
   ,  public infSwcServiceOs_Os
   ,  public class_SwcServiceOs_Functionality
{
   public:
      module_SwcServiceOs(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, SWCSERVICEOS_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, SWCSERVICEOS_CONFIG_DATA, SWCSERVICEOS_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SWCSERVICEOS_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEOS_CODE) MainFunction   (void);
      SWCSERVICEOS_CORE_FUNCTIONALITIES
};

extern VAR(module_SwcServiceOs, SWCSERVICEOS_VAR) SwcServiceOs;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient,      SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfEcuMClient_SwcServiceOs = &SwcServiceOs;
CONSTP2VAR(infDcmClient,       SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfDcmClient_SwcServiceOs  = &SwcServiceOs;
CONSTP2VAR(infSchMClient,      SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfSchMClient_SwcServiceOs = &SwcServiceOs;
CONSTP2VAR(infSwcServiceOs_Os, SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfSwcServiceOs_Os         = &SwcServiceOs;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_SwcServiceOs, SWCSERVICEOS_VAR) SwcServiceOs(
   {
         SWCSERVICEOS_AR_RELEASE_VERSION_MAJOR
      ,  SWCSERVICEOS_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, SWCSERVICEOS_CONFIG_DATA, SWCSERVICEOS_APPL_CONST) lptrCfgModule
){
#if(STD_ON == SwcServiceOs_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == SwcServiceOs_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
//            lptrCfg = &PBcfgSwcServiceOs;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == SwcServiceOs_InitCheck)
   }
#endif
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::DeInitFunction(void){
#if(STD_ON == SwcServiceOs_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == SwcServiceOs_InitCheck)
   }
#endif
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::MainFunction(void){
#if(STD_ON == SwcServiceOs_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == SwcServiceOs_InitCheck)
   }
#endif
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::StartupHook(void){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::ShutdownHook(void){
}

#include "infNvM_SchM.hpp"
#include "infEcuM_SchM.hpp"

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_Idle(void){
   gptrinfSchMClient_EcuM->MainFunction();
   gptrinfSchMClient_NvM->MainFunction();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

