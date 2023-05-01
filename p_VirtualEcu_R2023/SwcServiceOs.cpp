/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "SwcServiceOs.hpp"
#include "infSwcServiceOsSwcServiceEcuM.hpp"

#include "infSwcServiceEcuMSwcServiceOs.hpp"
#include "CalloutStubsSwcServiceOs.hpp"

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
static boolean SwcServiceOs_bRequestShutdown = FALSE;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static FUNC(void, SWCSERVICEOS_CODE) Activate_Task(//TBD: make scope and accessibility to global
   void //TBD: <generic service> arguement must contain reference to Task
){
   infSwcServiceEcuMSwcServiceOs_StartupTwo();
}

void infSwcServiceOs_RequestShutdown(void){
   SwcServiceOs_bRequestShutdown = TRUE;
}

FUNC(void, SWCSERVICEOS_CODE) infSwcServiceOsSwcServiceEcuM_Start(void){
   CalloutStubsSwcServiceOs_HookStartup();
   Activate_Task(/*TASK_Idle*/);

   do{
      Os_Entry_TASK_Idle();
   }while(FALSE == SwcServiceOs_bRequestShutdown);
   CalloutStubsSwcServiceOs_HookShutdown();
   infSwcServiceEcuMSwcServiceOs_Shutdown();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

