#pragma once
/******************************************************************************/
/* File   : ServiceSwcOs.hpp                                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceSwcOs_ServiceNvM_Types.hpp"
#include "CfgServiceSwcOs.hpp"
#include "ServiceSwcOs_core.hpp"
#include "infServiceSwcOs_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_ServiceSwcOs:
      INTERFACES_EXPORTED_SERVICESWCOS
   ,  public abstract_module
   ,  public class_ServiceSwcOs_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstModule_TypeAbstract* lptrNvMBlocksRom = (ConstModule_TypeAbstract*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, SERVICESWCOS_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCOS_CONST,       SERVICESWCOS_APPL_CONST) lptrNvMBlocksRomModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCOS_CONFIG_DATA, SERVICESWCOS_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SERVICESWCOS_CODE) DeInitFunction (void);
      FUNC(void, SERVICESWCOS_CODE) MainFunction   (void);
      SERVICESWCOS_CORE_FUNCTIONALITIES
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
extern VAR(module_ServiceSwcOs, SERVICESWCOS_VAR) ServiceSwcOs;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

