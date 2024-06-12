/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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

