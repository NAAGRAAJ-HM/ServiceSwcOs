/******************************************************************************/
/* File   : ServiceSwcOs.cpp                                                  */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceSwcOs.hpp"
#include "infServiceSwcOs_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICESWCOS_AR_RELEASE_VERSION_MAJOR                                  4
#define SERVICESWCOS_AR_RELEASE_VERSION_MINOR                                  3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SERVICESWCOS_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SERVICESWCOS_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SERVICESWCOS_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SERVICESWCOS_AR_RELEASE_VERSION_MINOR!"
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
VAR(module_ServiceSwcOs, SERVICESWCOS_VAR) ServiceSwcOs;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCOS_CONST,       SERVICESWCOS_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCOS_CONFIG_DATA, SERVICESWCOS_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceSwcOs_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstServiceSwcOs_Type*)(ConstServiceSwcOs_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceSwcOs_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == ServiceSwcOs_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceSwcOs_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICESWCOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::DeInitFunction(
   void
){
#if(STD_ON == ServiceSwcOs_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceSwcOs_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceSwcOs_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICESWCOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::MainFunction(
   void
){
#if(STD_ON == ServiceSwcOs_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceSwcOs_InitCheck)
   }
   else{
#if(STD_ON == ServiceSwcOs_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICESWCOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::StartupHook(
   void
){
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::ShutdownHook(
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

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_1ms(
   void
){
	lptrConst->ptrinfServiceSchM_ServiceSwcOs->ServiceSchM_1ms();
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_5ms(
   void
){
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_10ms(
   void
){
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_20ms(
   void
){
}

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_25ms(
   void
){
}
#else
#endif

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_Idle(
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

