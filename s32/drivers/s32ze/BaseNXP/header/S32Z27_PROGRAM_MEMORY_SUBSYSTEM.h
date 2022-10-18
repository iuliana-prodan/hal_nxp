/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z27_PROGRAM_MEMORY_SUBSYSTEM.h
 * @version 1.7
 * @date 2022-03-16
 * @brief Peripheral Access Layer for S32Z27_PROGRAM_MEMORY_SUBSYSTEM
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z27_PROGRAM_MEMORY_SUBSYSTEM_H_)  /* Check if memory map has not been already included */
#define S32Z27_PROGRAM_MEMORY_SUBSYSTEM_H_

#include "S32Z27_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PROGRAM_MEMORY_SUBSYSTEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PROGRAM_MEMORY_SUBSYSTEM_Peripheral_Access_Layer PROGRAM_MEMORY_SUBSYSTEM Peripheral Access Layer
 * @{
 */

/** PROGRAM_MEMORY_SUBSYSTEM - Register Layout Typedef */
typedef struct {
  __IO uint32_t MSS_PCR;                           /**< Program Control, offset: 0x0 */
  __IO uint32_t P_SYS_OU_C;                        /**< PMSS AXI Outstanding Configuration, offset: 0x4 */
  __I  uint32_t P_HDCFG;                           /**< PMSS Hardware Configuration, offset: 0x8 */
  uint8_t RESERVED_0[16];
  __IO uint32_t P_PORT_ID;                         /**< Program Port AXI ID, offset: 0x1C */
  __I  uint32_t P_ADD0_START;                      /**< PMSS ADD0 START, offset: 0x20 */
  __IO uint32_t P_ADD0_ATT0;                       /**< PMSS ADD0 ATT0, offset: 0x24 */
  __IO uint32_t P_ADD1_START;                      /**< PMSS ADD1 START, offset: 0x28 */
  __IO uint32_t P_ADD1_ATT0;                       /**< PMSS ADD1 ATT0, offset: 0x2C */
  __IO uint32_t P_ADD2_START;                      /**< PMSS ADD2 START, offset: 0x30 */
  __IO uint32_t P_ADD2_ATT0;                       /**< PMSS ADD2 ATT0, offset: 0x34 */
  __IO uint32_t P_ADD3_START;                      /**< PMSS ADD3 START, offset: 0x38 */
  __IO uint32_t P_ADD3_ATT0;                       /**< PMSS ADD3 ATT0, offset: 0x3C */
  __IO uint32_t P_ADD4_START;                      /**< PMSS ADD4 START, offset: 0x40 */
  __IO uint32_t P_ADD4_ATT0;                       /**< PMSS ADD4 ATT0, offset: 0x44 */
  __IO uint32_t P_ADD5_START;                      /**< PMSS ADD5 START, offset: 0x48 */
  __IO uint32_t P_ADD5_ATT0;                       /**< PMSS ADD5 ATT0, offset: 0x4C */
  __IO uint32_t P_ADD6_START;                      /**< PMSS ADD6 START, offset: 0x50 */
  __IO uint32_t P_ADD6_ATT0;                       /**< PMSS ADD6 ATT0, offset: 0x54 */
  __IO uint32_t P_ADD7_START;                      /**< PMSS ADD7 START, offset: 0x58 */
  __IO uint32_t P_ADD7_ATT0;                       /**< PMSS ADD7 ATT0, offset: 0x5C */
  uint8_t RESERVED_1[128];
  __IO uint32_t P_CCOSAR;                          /**< Program Cache Software Operations, offset: 0xE0 */
  __IO uint32_t P_CCOCR;                           /**< Program Cache Software Operations Control, offset: 0xE4 */
  uint8_t RESERVED_2[8];
  __I  uint32_t P_ECADD;                           /**< Program ECC Error Address, offset: 0xF0 */
  uint8_t RESERVED_3[76];
  __O  uint32_t PMSSACS;                           /**< PMSS Access Control, offset: 0x140 */
} PROGRAM_MEMORY_SUBSYSTEM_Type, *PROGRAM_MEMORY_SUBSYSTEM_MemMapPtr;

/** Number of instances of the PROGRAM_MEMORY_SUBSYSTEM module. */
#define PROGRAM_MEMORY_SUBSYSTEM_INSTANCE_COUNT  (1u)

/* PROGRAM_MEMORY_SUBSYSTEM - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM base address */
#define IP_CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM_BASE (0x24400400u)
/** Peripheral CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM base pointer */
#define IP_CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM   ((PROGRAM_MEMORY_SUBSYSTEM_Type *)IP_CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM_BASE)
/** Array initializer of PROGRAM_MEMORY_SUBSYSTEM peripheral base addresses */
#define IP_PROGRAM_MEMORY_SUBSYSTEM_BASE_ADDRS   { IP_CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM_BASE }
/** Array initializer of PROGRAM_MEMORY_SUBSYSTEM peripheral base pointers */
#define IP_PROGRAM_MEMORY_SUBSYSTEM_BASE_PTRS    { IP_CEVA_SPF2__PROGRAM_MEMORY_SUBSYSTEM }

/* ----------------------------------------------------------------------------
   -- PROGRAM_MEMORY_SUBSYSTEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PROGRAM_MEMORY_SUBSYSTEM_Register_Masks PROGRAM_MEMORY_SUBSYSTEM Register Masks
 * @{
 */

/*! @name MSS_PCR - Program Control */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PAPE_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PAPE_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PAPE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PAPE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PAPE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PAPE_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_PFE_MASK (0x4U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_PFE_SHIFT (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_PFE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_PFE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_PFE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_PFE_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CLBE_MASK (0x40U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CLBE_SHIFT (6U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CLBE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CLBE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CLBE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CLBE_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PCAC_EN_MASK (0x80U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PCAC_EN_SHIFT (7U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PCAC_EN_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PCAC_EN(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PCAC_EN_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_PCAC_EN_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_HWPF_SZ_MASK (0x300U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_HWPF_SZ_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_HWPF_SZ_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_HWPF_SZ(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_HWPF_SZ_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_HWPF_SZ_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_WPE_MASK (0x1000U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_WPE_SHIFT (12U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_WPE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_WPE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_WPE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_MSS_PCR_CAC_WPE_MASK)
/*! @} */

/*! @name P_SYS_OU_C - PMSS AXI Outstanding Configuration */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_TOTAL_OS_MASK (0xFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_TOTAL_OS_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_TOTAL_OS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_TOTAL_OS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_TOTAL_OS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_TOTAL_OS_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_SW_OS_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_SW_OS_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_SW_OS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_SW_OS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_SW_OS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_SYS_OU_C_SW_OS_MASK)
/*! @} */

/*! @name P_HDCFG - PMSS Hardware Configuration */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PTCM_SZE_MASK (0x7U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PTCM_SZE_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PTCM_SZE_WIDTH (3U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PTCM_SZE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PTCM_SZE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PTCM_SZE_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PCAC_SZE_MASK (0x70U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PCAC_SZE_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PCAC_SZE_WIDTH (3U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PCAC_SZE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PCAC_SZE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PCAC_SZE_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PECC_MASK (0x100U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PECC_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PECC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PECC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PECC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_PECC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_EPP_AXI_WID_MASK (0x200U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_EPP_AXI_WID_SHIFT (9U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_EPP_AXI_WID_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_EPP_AXI_WID(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_EPP_AXI_WID_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_EPP_AXI_WID_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_L1ICA_MASK (0xC0000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_L1ICA_SHIFT (30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_L1ICA_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_L1ICA(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_L1ICA_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_HDCFG_L1ICA_MASK)
/*! @} */

/*! @name P_PORT_ID - Program Port AXI ID */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PDMA_ID_MASK (0xFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PDMA_ID_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PDMA_ID_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PDMA_ID(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PDMA_ID_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PDMA_ID_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PF_ID_MASK (0xF0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PF_ID_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PF_ID_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PF_ID(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PF_ID_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_PF_ID_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_OCEM_ID_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_OCEM_ID_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_OCEM_ID_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_OCEM_ID(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_OCEM_ID_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_PORT_ID_OCEM_ID_MASK)
/*! @} */

/*! @name P_ADD0_START - PMSS ADD0 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD0_ATT0 - PMSS ADD0 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD0_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD1_START - PMSS ADD1 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD1_ATT0 - PMSS ADD1 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD1_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD2_START - PMSS ADD2 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD2_ATT0 - PMSS ADD2 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD2_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD3_START - PMSS ADD3 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD3_ATT0 - PMSS ADD3 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD3_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD4_START - PMSS ADD4 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD4_ATT0 - PMSS ADD4 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD4_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD5_START - PMSS ADD5 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD5_ATT0 - PMSS ADD5 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD5_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD6_START - PMSS ADD6 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD6_ATT0 - PMSS ADD6 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD6_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_ADD7_START - PMSS ADD7 START */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_P_REGION_START_MASK (0xFFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_P_REGION_START_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_P_REGION_START_WIDTH (20U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_P_REGION_START(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_P_REGION_START_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_P_REGION_START_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_INACTIVE_MASK (0x10000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_INACTIVE_SHIFT (28U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_INACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_INACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_INACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_START_INACTIVE_MASK)
/*! @} */

/*! @name P_ADD7_ATT0 - PMSS ADD7 ATT0 */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_LOCK_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_LOCK_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_LOCK_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_LOCK(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_LOCK_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_L1IC_LOCK_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_AP_MASK (0x30U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_AP_SHIFT (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_AP_WIDTH (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_AP(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_AP_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_AP_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_L2A_MASK (0xF00U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_L2A_SHIFT (8U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_L2A_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_L2A(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_L2A_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_L2A_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_RQOS_MASK (0xF000000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_RQOS_SHIFT (24U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_RQOS_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_RQOS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_RQOS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ADD7_ATT0_P_RQOS_MASK)
/*! @} */

/*! @name P_CCOSAR - Program Cache Software Operations */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOSAR_P_CCOSA_MASK (0xFFFFFFC0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOSAR_P_CCOSA_SHIFT (6U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOSAR_P_CCOSA_WIDTH (26U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOSAR_P_CCOSA(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_CCOSAR_P_CCOSA_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_CCOSAR_P_CCOSA_MASK)
/*! @} */

/*! @name P_CCOCR - Program Cache Software Operations Control */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_ACTIVE_MASK (0x1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_ACTIVE_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_ACTIVE_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_ACTIVE_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_ACTIVE_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_L1ICO_MASK (0x2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_L1ICO_SHIFT (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_L1ICO_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_L1ICO(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_L1ICO_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_L1ICO_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OT_MASK (0x3CU)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OT_SHIFT (2U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OT_WIDTH (4U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OT(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OT_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OT_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OS_MASK (0x80U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OS_SHIFT (7U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OS_WIDTH (1U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_OS_MASK)

#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_NOBPL_MASK (0xFFFF0000U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_NOBPL_SHIFT (16U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_NOBPL_WIDTH (16U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_NOBPL(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_NOBPL_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_CCOCR_P_NOBPL_MASK)
/*! @} */

/*! @name P_ECADD - Program ECC Error Address */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_P_ECADD_ECADD_MASK (0xFFFFFFE0U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ECADD_ECADD_SHIFT (5U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ECADD_ECADD_WIDTH (27U)
#define PROGRAM_MEMORY_SUBSYSTEM_P_ECADD_ECADD(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_P_ECADD_ECADD_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_P_ECADD_ECADD_MASK)
/*! @} */

/*! @name PMSSACS - PMSS Access Control */
/*! @{ */

#define PROGRAM_MEMORY_SUBSYSTEM_PMSSACS_PMSS_ACS_MASK (0xFFFFU)
#define PROGRAM_MEMORY_SUBSYSTEM_PMSSACS_PMSS_ACS_SHIFT (0U)
#define PROGRAM_MEMORY_SUBSYSTEM_PMSSACS_PMSS_ACS_WIDTH (16U)
#define PROGRAM_MEMORY_SUBSYSTEM_PMSSACS_PMSS_ACS(x) (((uint32_t)(((uint32_t)(x)) << PROGRAM_MEMORY_SUBSYSTEM_PMSSACS_PMSS_ACS_SHIFT)) & PROGRAM_MEMORY_SUBSYSTEM_PMSSACS_PMSS_ACS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PROGRAM_MEMORY_SUBSYSTEM_Register_Masks */

/*!
 * @}
 */ /* end of group PROGRAM_MEMORY_SUBSYSTEM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z27_PROGRAM_MEMORY_SUBSYSTEM_H_) */