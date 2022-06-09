/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgSwcServiceOs.hpp"
#include "SwcServiceOs_core.hpp"
#include "infSwcServiceOs_Exp.hpp"
#include "infSwcServiceOs_Imp.hpp"

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
      INTERFACES_EXPORTED_SWCSERVICEOS
   ,  public abstract_module
   ,  public class_SwcServiceOs_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};

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
#if(STD_ON == _ReSIM)
         "SwcServiceOs"
#else
#endif
      ,  SWCSERVICEOS_AR_RELEASE_VERSION_MAJOR
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
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgSwcServiceOs;
         }
      }
      else{
#if(STD_ON == SwcServiceOs_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == SwcServiceOs_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SWCSERVICEOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::DeInitFunction(void){
#if(STD_ON == SwcServiceOs_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == SwcServiceOs_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SWCSERVICEOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::MainFunction(void){
#if(STD_ON == SwcServiceOs_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == SwcServiceOs_InitCheck)
   }
   else{
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SWCSERVICEOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::StartupHook(void){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::ShutdownHook(void){
}

#if(STD_ON == _ReSIM)
#include <iostream>
using namespace std;
uint32 gu32SystemTime = 0;
static const uint32 lu32PrescaleSystem = 100000000;
static const uint8 lu8Prescale5ms = 5;
static const uint8 lu8Prescale10ms = 2;
static const uint8 lu8Prescale20ms = 2;
static const uint8 lu8Prescale25ms = 5;
void TASK_1ms(void){
// gptrinfSchMClient_EcuM->MainFunction();
// gptrinfSchMClient_NvM->MainFunction();
   gptrinfSchMClient_PduR->MainFunction();
   gptrinfSchMClient_Dcm->MainFunction();
}
void TASK_5ms(void){
}
void TASK_10ms(void){
}
void TASK_20ms(void){
}
void TASK_25ms(void){
}
#else
#endif

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_Idle(void){
#if(STD_ON == _ReSIM)
   static uint32 lu32TickSystem = 0;
   static uint8 lu8Tick5ms = 0;
   static uint8 lu8Tick10ms = 0;
   static uint8 lu8Tick20ms = 0;
   static uint8 lu8Tick25ms = 0;
   if(lu32PrescaleSystem == ++lu32TickSystem){
      lu32TickSystem = 0;
      gu32SystemTime++;
      if(lu8Prescale5ms == ++lu8Tick5ms){
         lu8Tick5ms = 0;
         if(lu8Prescale25ms == ++lu8Tick25ms){
            lu8Tick25ms = 0;
            TASK_25ms();
         }
         if(lu8Prescale10ms == ++lu8Tick10ms){
            lu8Tick10ms = 0;
            if(lu8Prescale20ms == ++lu8Tick20ms){
               lu8Tick20ms = 0;
               TASK_20ms();
            }
            TASK_10ms();
         }
         TASK_5ms();
      }
      TASK_1ms();
   }
#else
#endif
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

