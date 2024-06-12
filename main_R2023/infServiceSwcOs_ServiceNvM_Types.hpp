#pragma once
/******************************************************************************/
/* File   : infServiceSwcOs_ServiceNvM_Types.hpp                              */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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

