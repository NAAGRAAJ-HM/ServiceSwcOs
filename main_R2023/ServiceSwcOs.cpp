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

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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
extern void INT_Init(void); //TBD: use interface headers as per architecture

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCOS_CONST,       SERVICESWCOS_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCOS_CONFIG_DATA, SERVICESWCOS_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceSwcOs_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
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
      INT_Init();
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

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_1ms(
   void
){
	((NvM_BlocksRom_ServiceSwcOs_Type*)lptrNvMBlocksRom)->ptrinfServiceSchM_ServiceSwcOs->ServiceSchM_1ms();
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

FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_25ms(void){
	((NvM_BlocksRom_ServiceSwcOs_Type*)lptrNvMBlocksRom)->ptrinfServiceSchM_ServiceSwcOs->ServiceSchM_25ms();
}

uint32 gu32SystemTime = 0;
#else
#endif

#include "ReSimCmd.hpp"
FUNC(void, SERVICESWCOS_CODE) module_ServiceSwcOs::TASK_Idle(
   void
){
#if(STD_ON == _ReSIM)
   ReSimCmd_MainFunction();

   const  uint32 lu32PrescaleSystem = 100000000;
   const  uint8  lu8Prescale5ms     = 5; //TBD: hardcode after SIL testing
   const  uint8  lu8Prescale10ms    = 2;
   const  uint8  lu8Prescale20ms    = 2;
   const  uint8  lu8Prescale25ms    = 5;
   static uint32 lu32TickSystem     = 0;
   static uint8  lu8Tick5ms         = 0;
   static uint8  lu8Tick10ms        = 0;
   static uint8  lu8Tick20ms        = 0;
   static uint8  lu8Tick25ms        = 0;
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

