/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "SwcServiceOs.hpp"
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
         lptrCfg = lptrCfgModule;
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

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::DeInitFunction(
   void
){
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

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::MainFunction(
   void
){
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

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::StartupHook(
   void
){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::ShutdownHook(
   void
){
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

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_1ms(
   void
){
	lptrConst->ptrinfSchM_SwcServiceOs->SchM_1ms();
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_5ms(
   void
){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_10ms(
   void
){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_20ms(
   void
){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_25ms(
   void
){
}
#else
#endif

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_Idle(
   void
){
#if(STD_ON == _ReSIM)
   static uint32 lu32TickSystem = 0;
   static uint8  lu8Tick5ms     = 0;
   static uint8  lu8Tick10ms    = 0;
   static uint8  lu8Tick20ms    = 0;
   static uint8  lu8Tick25ms    = 0;
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

