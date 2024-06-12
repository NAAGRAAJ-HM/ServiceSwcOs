#pragma once
/******************************************************************************/
/* File   : ServiceSwcOs_core.hpp                                             */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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

