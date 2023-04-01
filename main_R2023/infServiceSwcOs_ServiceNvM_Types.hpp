#pragma once
/******************************************************************************/
/* File   : infServiceSwcOs_ServiceNvM_Types.hpp                              */
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

