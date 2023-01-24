#pragma once
/******************************************************************************/
/* File   : infServiceSwcOs_ServiceNvM.hpp                                    */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceSchM_ServiceSwcOs.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CONSTSERVICESWCOS_AR_RELEASE_VERSION_MAJOR                             4
#define CONSTSERVICESWCOS_AR_RELEASE_VERSION_MINOR                             3

#define Const_DefaultInit_ConstServiceSwcOs                                                                                      \
   ,  {                                                                                                                          \
            {CONSTSERVICESWCOS_AR_RELEASE_VERSION_MAJOR, CONSTSERVICESWCOS_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'} \
         ,  &ServiceSchM                                                                                                         \
      }                                                                                                                          \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CONSTSERVICESWCOS_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CONSTSERVICESWCOS_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CONSTSERVICESWCOS_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CONSTSERVICESWCOS_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

