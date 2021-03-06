/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : KIN1.h
**     Project     : FRDM
**     Processor   : MKL25Z128VLK4
**     Component   : KinetisTools
**     Version     : Component 01.025, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-05-09, 11:02, # CodeGen: 14
**     Abstract    :
**
**     Settings    :
**          Component name                                 : KIN1
**          Utility                                        : UTIL1
**          Shell                                          : Disabled
**     Contents    :
**         SoftwareReset          - void KIN1_SoftwareReset(void);
**         UIDGet                 - uint8_t KIN1_UIDGet(KIN1_UID *uid);
**         UIDSame                - bool KIN1_UIDSame(const KIN1_UID *src, const KIN1_UID *dst);
**         UIDtoString            - uint8_t KIN1_UIDtoString(const KIN1_UID *uid, uint8_t *buf, size_t bufSize);
**         GetKinetisFamilyString - KIN1_ConstCharPtr KIN1_GetKinetisFamilyString(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014, all rights reserved.
**     http          : www.mcuoneclipse.com
**     This an open source software implementing software using Processor Expert.
**     Main purpose is for a file system, but useful as well without one.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file KIN1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup KIN1_module KIN1 module documentation
**  @{
*/         

#ifndef __KIN1_H
#define __KIN1_H

/* MODULE KIN1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "UTIL1.h"

#include "Cpu.h"


#ifndef __BWUserType_KIN1_ConstCharPtr
#define __BWUserType_KIN1_ConstCharPtr
  typedef const uint8_t *KIN1_ConstCharPtr; /* Pointer to constant string */
#endif

typedef struct {
  uint8_t id[10]; /* 80 bit ID */
} KIN1_UID;

typedef enum {
  KIN1_FAMILY_K10_K12,                 /* K10 or K12 */
  KIN1_FAMILY_K20_K22,                 /* K10 or K12 */
  KIN1_FAMILY_K30_K11_K61,             /* K30, K11 or K61 */
  KIN1_FAMILY_K40_K21,                 /* K40 or K21 */
  KIN1_FAMILY_K70,                     /* K70 */
  KIN1_FAMILY_UNKONWN,                 /* Unknown */
  KIN1_FAMILY_LAST                     /* Must be last one! */
} KIN1_FAMILY;

#define KIN1_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */
#define KIN1_CPU_IS_M0_PLUS  1
#define KIN1_CPU_IS_M4       0
#define KIN1_IS_USING_KINETIS_SDK   0 /* 1: using Kinetis SDK, 0: not using Kinetis SDK */


void KIN1_SoftwareReset(void);
/*
** ===================================================================
**     Method      :  KIN1_SoftwareReset (component KinetisTools)
**     Description :
**         Performs a reset of the device
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t KIN1_UIDGet(KIN1_UID *uid);
/*
** ===================================================================
**     Method      :  KIN1_UIDGet (component KinetisTools)
**     Description :
**         Return the 80bit UID of the device
**     Parameters  :
**         NAME            - DESCRIPTION
**       * uid             - Pointer to 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

bool KIN1_UIDSame(const KIN1_UID *src, const KIN1_UID *dst);
/*
** ===================================================================
**     Method      :  KIN1_UIDSame (component KinetisTools)
**     Description :
**         Compares two UID
**     Parameters  :
**         NAME            - DESCRIPTION
**       * src             - Pointer to 
**         Variable_1      - 
**     Returns     :
**         ---             - TRUE if the same, FALSE otherwise
** ===================================================================
*/

uint8_t KIN1_UIDtoString(const KIN1_UID *uid, uint8_t *buf, size_t bufSize);
/*
** ===================================================================
**     Method      :  KIN1_UIDtoString (component KinetisTools)
**     Description :
**         Returns the value of the UID as string
**     Parameters  :
**         NAME            - DESCRIPTION
**         uid             - 
**       * buf             - Pointer to 
**         bufSize         - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

KIN1_ConstCharPtr KIN1_GetKinetisFamilyString(void);
/*
** ===================================================================
**     Method      :  KIN1_GetKinetisFamilyString (component KinetisTools)
**     Description :
**         Determines the Kinetis Familiy based on SIM_SDID register
**     Parameters  : None
**     Returns     :
**         ---             - String describing the Kinetis Family
** ===================================================================
*/

/* END KIN1. */

#endif
/* ifndef __KIN1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
