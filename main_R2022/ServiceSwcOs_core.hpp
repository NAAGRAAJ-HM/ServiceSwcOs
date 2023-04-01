#pragma once
/******************************************************************************/
/* File   : ServiceSwcOs_core.hpp                                             */
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
#include "CompilerCfg_ServiceSwcOs.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICESWCOS_CORE_FUNCTIONALITIES                                      \
              FUNC(void, SERVICESWCOS_CODE) StartupHook  (void);               \
              FUNC(void, SERVICESWCOS_CODE) ShutdownHook (void);               \
              FUNC(void, SERVICESWCOS_CODE) TASK_Idle    (void);               \
              FUNC(void, SERVICESWCOS_CODE) TASK_1ms     (void);               \
              FUNC(void, SERVICESWCOS_CODE) TASK_5ms     (void);               \
              FUNC(void, SERVICESWCOS_CODE) TASK_10ms    (void);               \
              FUNC(void, SERVICESWCOS_CODE) TASK_20ms    (void);               \
              FUNC(void, SERVICESWCOS_CODE) TASK_25ms    (void);               \

#define SERVICESWCOS_CORE_FUNCTIONALITIES_VIRTUAL                              \
      virtual FUNC(void, SERVICESWCOS_CODE) StartupHook  (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) ShutdownHook (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) TASK_Idle    (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) TASK_1ms     (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) TASK_5ms     (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) TASK_10ms    (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) TASK_20ms    (void) = 0;           \
      virtual FUNC(void, SERVICESWCOS_CODE) TASK_25ms    (void) = 0;           \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceSwcOs_Functionality{
   public:
      SERVICESWCOS_CORE_FUNCTIONALITIES_VIRTUAL
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

