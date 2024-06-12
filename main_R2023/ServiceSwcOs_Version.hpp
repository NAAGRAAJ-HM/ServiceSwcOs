#pragma once
/******************************************************************************/
/* File   : ServiceSwcOs_Version.hpp                                          */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

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
/* EOF                                                                        */
/******************************************************************************/

