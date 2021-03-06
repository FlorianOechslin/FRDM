/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : KIN1.c
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
** @file KIN1.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup KIN1_module KIN1 module documentation
**  @{
*/         

/* MODULE KIN1. */

#include "KIN1.h"
#include <stddef.h> /* for size_t */

#if KIN1_CPU_IS_M4
static const unsigned char *KinetisM4FamilyStrings[] =
{ /* FAMID (3 bits) are used as index */
  (const unsigned char *)"K10 or K12 Family",          /* 000 */
  (const unsigned char *)"K20 or K22 Family",          /* 001 */
  (const unsigned char *)"K30, K11 or K61 Family",     /* 010 */
  (const unsigned char *)"K40 or K21 Family",          /* 011 */
  (const unsigned char *)"K60 or K62 Family",          /* 100 */
  (const unsigned char *)"K70 Family",                 /* 101 */
  (const unsigned char *)"Reserved",                   /* 110 */
  (const unsigned char *)"Reserved"                    /* 111 */
};
#endif
#if KIN1_CPU_IS_M0_PLUS
static const unsigned char *KinetisM0FamilyStrings[] =
{ /* FAMID (3 bits) are used as index */
  (const unsigned char *)"KL0x",          /* 000 */
  (const unsigned char *)"KL1x",          /* 001 */
  (const unsigned char *)"KL2x",          /* 010 */
  (const unsigned char *)"KL3x",          /* 011 */
  (const unsigned char *)"KL4x",          /* 100 */
  (const unsigned char *)"Reserved",      /* 101 */
  (const unsigned char *)"Reserved",      /* 110 */
  (const unsigned char *)"Reserved"       /* 111 */
};
#endif



/*
** ===================================================================
**     Method      :  KIN1_SoftwareReset (component KinetisTools)
**     Description :
**         Performs a reset of the device
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void KIN1_SoftwareReset(void)
{
  /* Generic way to request a reset from software for ARM Cortex */
  /* See https://community.freescale.com/thread/99740
     To write to this register, you must write 0x5FA to the VECTKEY field, otherwise the processor ignores the write.
     SYSRESETREQ will cause a system reset asynchronously, so need to wait afterwards.
   */
#if KIN1_IS_USING_KINETIS_SDK
  SCB->AIRCR = (0x5FA<<SCB_AIRCR_VECTKEY_Pos)|SCB_AIRCR_SYSRESETREQ_Msk;
#else
  SCB_AIRCR = SCB_AIRCR_VECTKEY(0x5FA) | SCB_AIRCR_SYSRESETREQ_MASK;
#endif
  for(;;) {
    /* wait until reset */
  }
}

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
/*!
 * \brief Return the 80bit UID of the device
 * \param uid Pointer to the buffer where to store the UID
 * \return Error code, ERR_OK if everything is ok.
 */
uint8_t KIN1_UIDGet(KIN1_UID *uid)
{
  uid->id[0] = (SIM_UIDMH>>8)&0xff;
  uid->id[1] = SIM_UIDMH&0xff;
  uid->id[2] = (SIM_UIDML>>24)&0xff;
  uid->id[3] = (SIM_UIDML>>16)&0xff;
  uid->id[4] = (SIM_UIDML>>8)&0xff;
  uid->id[5] = SIM_UIDML&0xff;
  uid->id[6] = (SIM_UIDL>>24)&0xff;
  uid->id[7] = (SIM_UIDL>>16)&0xff;
  uid->id[8] = (SIM_UIDL>>8)&0xff;
  uid->id[9] = SIM_UIDL&0xff;
  return ERR_OK;
}

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
/*!
 * \brief Compares two UID
 * \param src One UID
 * \param dst The other UID
 * \return TRUE if the two UID's are the same
 */
bool KIN1_UIDSame(const KIN1_UID *src, const KIN1_UID *dst)
{
  int i;

  for(i=0; i<sizeof(KIN1_UID); i++) {
    if (src->id[i]!=dst->id[i]) {
      return FALSE; /* no match */
    }
  }
  return TRUE;
}

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
/*!
 * \brief Transforms the 80bit UID into a string
 * \param id Pointer to the buffer where to store the string
 * \param bufSize Size of buffer in bytes
 * \return Error code, ERR_OK if everything is ok.
 */
uint8_t KIN1_UIDtoString(const KIN1_UID *uid, uint8_t *buf, size_t bufSize)
{
  int i;

  UTIL1_strcpy(buf, bufSize, (unsigned char*)"{");
  for(i=0;i<sizeof(KIN1_UID);i++) {
    UTIL1_strcat(buf, bufSize, (unsigned char*)"0x");
    UTIL1_strcatNum8Hex(buf, bufSize, uid->id[i]);
    if (i<sizeof(KIN1_UID)-1) {
      UTIL1_strcat(buf, bufSize, (unsigned char*)", ");
    }
  }
  UTIL1_strcat(buf, bufSize, (unsigned char*)"}");
  return ERR_OK;
}

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
KIN1_ConstCharPtr KIN1_GetKinetisFamilyString(void)
{
#if KIN1_CPU_IS_M0_PLUS
  int32_t val;

  val = (SIM_SDID>>28)&0x3; /* bits 30..28 */
  return KinetisM0FamilyStrings[val];
#elif KIN1_CPU_IS_M4
  int32_t val;

  val = (SIM_SDID>>4)&0x3; /* bits 6..4 */
  return KinetisM4FamilyStrings[val];
#else
  #error "Unknown architecture!"
  return "ERROR";
#endif
}

/* END KIN1. */

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
