#pragma once
/******************************************************************************/
/* File   : ServiceSwcOs_core.hpp                                             */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_ServiceSwcOs.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SWCSERVICEOS_CORE_FUNCTIONALITIES                                      \
              FUNC(void, SWCSERVICEOS_CODE) StartupHook  (void);               \
              FUNC(void, SWCSERVICEOS_CODE) ShutdownHook (void);               \
              FUNC(void, SWCSERVICEOS_CODE) TASK_Idle    (void);               \
              FUNC(void, SWCSERVICEOS_CODE) TASK_1ms     (void);               \
              FUNC(void, SWCSERVICEOS_CODE) TASK_5ms     (void);               \
              FUNC(void, SWCSERVICEOS_CODE) TASK_10ms    (void);               \
              FUNC(void, SWCSERVICEOS_CODE) TASK_20ms    (void);               \
              FUNC(void, SWCSERVICEOS_CODE) TASK_25ms    (void);               \

#define SWCSERVICEOS_CORE_FUNCTIONALITIES_VIRTUAL                              \
      virtual FUNC(void, SWCSERVICEOS_CODE) StartupHook  (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) ShutdownHook (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) TASK_Idle    (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) TASK_1ms     (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) TASK_5ms     (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) TASK_10ms    (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) TASK_20ms    (void) = 0;           \
      virtual FUNC(void, SWCSERVICEOS_CODE) TASK_25ms    (void) = 0;           \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceSwcOs_Functionality{
   public:
      SWCSERVICEOS_CORE_FUNCTIONALITIES_VIRTUAL
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

