#pragma once
/******************************************************************************/
/* File   : infServiceSwcOs_ServiceNvM_Types.hpp                              */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceSchM_ServiceSwcOs.hpp"

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class NvM_BlocksRom_ServiceSwcOs_Type:
      public ConstModule_TypeAbstract
{
   public:
      infServiceSchM_ServiceSwcOs* ptrinfServiceSchM_ServiceSwcOs;
};

class NvM_BlocksNv_ServiceSwcOs_Type:
      public CfgModule_TypeAbstract
{
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

