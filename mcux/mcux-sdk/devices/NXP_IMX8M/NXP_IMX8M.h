/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * Peripheral Access Layer for DSP from IMX8MP
 */

#ifndef _NXP_IMX8M_H_
#define _NXP_IMX8M_H_

#ifndef __I
#define __I
#endif
#ifndef __O
#define __O
#endif
#ifndef __IO
#define __IO
#endif

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0500U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 186                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  Software0_IRQn               = 0,                /**< Cortex-A53 Software Generated Interrupt 0 */
  Software1_IRQn               = 1,                /**< Cortex-A53 Software Generated Interrupt 1 */
  Software2_IRQn               = 2,                /**< Cortex-A53 Software Generated Interrupt 2 */
  Software3_IRQn               = 3,                /**< Cortex-A53 Software Generated Interrupt 3 */
  Software4_IRQn               = 4,                /**< Cortex-A53 Software Generated Interrupt 4 */
  Software5_IRQn               = 5,                /**< Cortex-A53 Software Generated Interrupt 5 */
  Software6_IRQn               = 6,                /**< Cortex-A53 Software Generated Interrupt 6 */
  Software7_IRQn               = 7,                /**< Cortex-A53 Software Generated Interrupt 7 */
  Software8_IRQn               = 8,                /**< Cortex-A53 Software Generated Interrupt 8 */
  Software9_IRQn               = 9,                /**< Cortex-A53 Software Generated Interrupt 9 */
  Software10_IRQn              = 10,               /**< Cortex-A53 Software Generated Interrupt 10 */
  Software11_IRQn              = 11,               /**< Cortex-A53 Software Generated Interrupt 11 */
  Software12_IRQn              = 12,               /**< Cortex-A53 Software Generated Interrupt 12 */
  Software13_IRQn              = 13,               /**< Cortex-A53 Software Generated Interrupt 13 */
  Software14_IRQn              = 14,               /**< Cortex-A53 Software Generated Interrupt 14 */
  Software15_IRQn              = 15,               /**< Cortex-A53 Software Generated Interrupt 15 */
  VirtualMaintenance_IRQn      = 25,               /**< Cortex-A53 Virtual Maintenance Interrupt */
  HypervisorTimer_IRQn         = 26,               /**< Cortex-A53 Hypervisor Timer Interrupt */
  VirtualTimer_IRQn            = 27,               /**< Cortex-A53 Virtual Timer Interrupt */
  LegacyFastInt_IRQn           = 28,               /**< Cortex-A53 Legacy nFIQ signal Interrupt */
  SecurePhyTimer_IRQn          = 29,               /**< Cortex-A53 Secure Physical Timer Interrupt */
  NonSecurePhyTimer_IRQn       = 30,               /**< Cortex-A53 Non-secure Physical Timer Interrupt */
  LegacyIRQ_IRQn               = 31,               /**< Cortex-A53 Legacy nIRQ Interrupt */

  /* Device specific interrupts */
  GPR_IRQ_IRQn                 = 32,               /**< GPR Interrupt. Used to notify cores on exception condition while boot. */
  DAP_IRQn                     = 33,               /**< DAP Interrupt */
  SDMA1_IRQn                   = 34,               /**< AND of all 48 SDMA interrupts (events) from all the channels */
  GPU3D_IRQn                   = 35,               /**< GPU3D Interrupt */
  SNVS_IRQn                    = 36,               /**< ON-OFF button press shorter than 5 seconds (pulse event) */
  LCDIF1_IRQn                  = 37,               /**< LCDIF Sync Interrupt */
  LCDIF2_IRQn                  = 38,               /**< LCDIF Sync Interrupt */
  VPU_G1_IRQn                  = 39,               /**< VPU G1 Decoder Interrupt */
  VPU_G2_IRQn                  = 40,               /**< VPU G2 Decoder Interrupt */
  QOS_IRQn                     = 41,               /**< QOS interrupt */
  WDOG3_IRQn                   = 42,               /**< Watchdog Timer reset */
  HS_CP1_IRQn                  = 43,               /**< HS Interrupt Request */
  APBHDMA_IRQn                 = 44,               /**< GPMI operation channel 0-3 description complete interrupt */
  ML_IRQn                      = 45,               /**< Machine Learning Processor Interrupt */
  BCH_IRQn                     = 46,               /**< BCH operation complete interrupt */
  GPMI_IRQn                    = 47,               /**< GPMI operation TIMEOUT ERROR interrupt */
  ISI0_IRQn                    = 48,               /**< ISI Camera Channel 0 Interrupt */
  MIPI_CSI1_IRQn               = 49,               /**< MIPI CSI Interrupt */
  MIPI_DSI_IRQn                = 50,               /**< MIPI DSI Interrupt */
  SNVS_Consolidated_IRQn       = 51,               /**< SRTC Consolidated Interrupt. Non TZ. */
  SNVS_Security_IRQn           = 52,               /**< SRTC Security Interrupt. TZ. */
  CSU_IRQn                     = 53,               /**< CSU Interrupt Request. Indicates to the processor that one or more alarm inputs were asserted. */
  USDHC1_IRQn                  = 54,               /**< uSDHC1 Enhanced SDHC Interrupt Request */
  USDHC2_IRQn                  = 55,               /**< uSDHC2 Enhanced SDHC Interrupt Request */
  USDHC3_IRQn                  = 56,               /**< uSDHC3 Enhanced SDHC Interrupt Request */
  GPU2D_IRQn                   = 57,               /**< GPU2D Interrupt */
  UART1_IRQn                   = 58,               /**< UART-1 ORed interrupt */
  UART2_IRQn                   = 59,               /**< UART-2 ORed interrupt */
  UART3_IRQn                   = 60,               /**< UART-3 ORed interrupt */
  UART4_IRQn                   = 61,               /**< UART-4 ORed interrupt */
  VPU_IRQn                     = 62,               /**< VPU Encoder Interrupt */
  ECSPI1_IRQn                  = 63,               /**< ECSPI1 interrupt request line to the core. */
  ECSPI2_IRQn                  = 64,               /**< ECSPI2 interrupt request line to the core. */
  ECSPI3_IRQn                  = 65,               /**< ECSPI3 interrupt request line to the core. */
  SDMA3_IRQn                   = 66,               /**< AND of all 48 SDMA interrupts (events) from all the channels */
  I2C1_IRQn                    = 67,               /**< I2C-1 Interrupt */
  I2C2_IRQn                    = 68,               /**< I2C-2 Interrupt */
  I2C3_IRQn                    = 69,               /**< I2C-3 Interrupt */
  I2C4_IRQn                    = 70,               /**< I2C-4 Interrupt */
  RDC_IRQn                     = 71,               /**< RDC interrupt */
  USB1_IRQn                    = 72,               /**< USB1 Interrupt */
  USB2_IRQn                    = 73,               /**< USB-2 Interrupt */
  ISI1_IRQn                    = 74,               /**< ISI Camera Channel 1 Interrupt */
  HDMI_TX_IRQn                 = 75,               /**< HDMI TX Subsystem Interrupt */
  MICFIL_VoiceEvent_IRQn       = 76,               /**< Digital Microphone interface voice activity detector event interrupt */
  MICFIL_VoiceError_IRQn       = 77,               /**< Digital Microphone interface voice activity detector error interrupt */
  GPT6_IRQn                    = 78,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  SCTR_IRQ0_IRQn               = 79,               /**< ISO7816IP Interrupt 0 */
  SCTR_IRQ1_IRQn               = 80,               /**< ISO7816IP Interrupt 1 */
  ANAMIX_IRQn                  = 81,               /**< TempSensor (Temperature alarm). */
  I2S3_IRQn                    = 82,               /**< SAI3 Receive / Transmit Interrupt */
  GPT5_IRQn                    = 83,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT4_IRQn                    = 84,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT3_IRQn                    = 85,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT2_IRQn                    = 86,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT1_IRQn                    = 87,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPIO1_INT7_IRQn              = 88,               /**< Active HIGH Interrupt from INT7 from GPIO */
  GPIO1_INT6_IRQn              = 89,               /**< Active HIGH Interrupt from INT6 from GPIO */
  GPIO1_INT5_IRQn              = 90,               /**< Active HIGH Interrupt from INT5 from GPIO */
  GPIO1_INT4_IRQn              = 91,               /**< Active HIGH Interrupt from INT4 from GPIO */
  GPIO1_INT3_IRQn              = 92,               /**< Active HIGH Interrupt from INT3 from GPIO */
  GPIO1_INT2_IRQn              = 93,               /**< Active HIGH Interrupt from INT2 from GPIO */
  GPIO1_INT1_IRQn              = 94,               /**< Active HIGH Interrupt from INT1 from GPIO */
  GPIO1_INT0_IRQn              = 95,               /**< Active HIGH Interrupt from INT0 from GPIO */
  GPIO1_Combined_0_15_IRQn     = 96,               /**< Combined interrupt indication for GPIO1 signal 0 throughout 15 */
  GPIO1_Combined_16_31_IRQn    = 97,               /**< Combined interrupt indication for GPIO1 signal 16 throughout 31 */
  GPIO2_Combined_0_15_IRQn     = 98,               /**< Combined interrupt indication for GPIO2 signal 0 throughout 15 */
  GPIO2_Combined_16_31_IRQn    = 99,               /**< Combined interrupt indication for GPIO2 signal 16 throughout 31 */
  GPIO3_Combined_0_15_IRQn     = 100,              /**< Combined interrupt indication for GPIO3 signal 0 throughout 15 */
  GPIO3_Combined_16_31_IRQn    = 101,              /**< Combined interrupt indication for GPIO3 signal 16 throughout 31 */
  GPIO4_Combined_0_15_IRQn     = 102,              /**< Combined interrupt indication for GPIO4 signal 0 throughout 15 */
  GPIO4_Combined_16_31_IRQn    = 103,              /**< Combined interrupt indication for GPIO4 signal 16 throughout 31 */
  GPIO5_Combined_0_15_IRQn     = 104,              /**< Combined interrupt indication for GPIO5 signal 0 throughout 15 */
  GPIO5_Combined_16_31_IRQn    = 105,              /**< Combined interrupt indication for GPIO5 signal 16 throughout 31 */
  ISP1_IRQn                    = 106,              /**< ISP 1 ISP Interrupts */
  ISP2_IRQn                    = 107,              /**< ISP 2 ISP Interrupts */
  I2C5_IRQn                    = 108,              /**< I2C5 Interrupt */
  I2C6_IRQn                    = 109,              /**< I2C6 Interrupt */
  WDOG1_IRQn                   = 110,              /**< Watchdog Timer reset */
  WDOG2_IRQn                   = 111,              /**< Watchdog Timer reset */
  MIPI_CSI2_IRQn               = 112,              /**< MIPI CSI 2 Interrupt */
  PWM1_IRQn                    = 113,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  PWM2_IRQn                    = 114,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  PWM3_IRQn                    = 115,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  PWM4_IRQn                    = 116,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  CCM_IRQ1_IRQn                = 117,              /**< CCM Interrupt Request 1 */
  CCM_IRQ2_IRQn                = 118,              /**< CCM Interrupt Request 2 */
  GPC_IRQn                     = 119,              /**< GPC Interrupt Request 1 */
  MU_A53_IRQn                  = 120,              /**< Interrupt to A53 */
  SRC_IRQn                     = 121,              /**< SRC interrupt request */
  I2S56_IRQn                   = 122,              /**< SAI5/6 Receive / Transmit Interrupt */
  RTIC_IRQn                    = 123,              /**< RTIC Interrupt */
  CPU_PerformanceUnit_IRQn     = 124,              /**< Performance Unit Interrupts from Cheetah (interrnally: PMUIRQ[n] */
  CPU_CTI_Trigger_IRQn         = 125,              /**< CTI trigger outputs (internal: nCTIIRQ[n] */
  SRC_Combined_IRQn            = 126,              /**< Combined CPU wdog interrupts (4x) out of SRC. */
  I2S1_IRQn                    = 127,              /**< SAI1 Receive / Transmit Interrupt */
  I2S2_IRQn                    = 128,              /**< SAI2 Receive / Transmit Interrupt */
  MU_M7_IRQn                   = 129,              /**< Interrupt to M7 */
  DDR_PerformanceMonitor_IRQn  = 130,              /**< ddr Interrupt for performance monitor */
  DDR_Err_IRQn                 = 131,              /**< ddr Interrupt */
  DEWARP_IRQn                  = 132,              /**< Dewarp Interrupt */
  CPU_Error_AXI_IRQn           = 133,              /**< CPU Error indicator for AXI transaction with a write response error condition */
  CPU_Error_L2RAM_IRQn         = 134,              /**< CPU Error indicator for L2 RAM double-bit ECC error */
  SDMA2_IRQn                   = 135,              /**< AND of all 48 SDMA interrupts (events) from all the channels */
  SJC_IRQn                     = 136,              /**< Interrupt triggered by SJC register */
  CAAM_IRQ0_IRQn               = 137,              /**< CAAM interrupt queue for JQ */
  CAAM_IRQ1_IRQn               = 138,              /**< CAAM interrupt queue for JQ */
  FLEXSPI_IRQn                 = 139,              /**< Flexspi Interrupt */
  TZASC_IRQn                   = 140,              /**< TZASC (PL380) interrupt */
  MICFIL_IRQn                  = 141,              /**< Digital Microphone interface interrupt */
  MICFIL_Error_IRQn            = 142,              /**< Digital Microphone interface error interrupt */
  I2S7_IRQn                    = 143,              /**< SAI7 Receive / Transmit Interrupt */
  PERFMON1_IRQn                = 144,              /**< General Interrupt */
  PERFMON2_IRQn                = 145,              /**< General Interrupt */
  CAAM_Job_Ring2_IRQn          = 146,              /**< CAAM interrupt queue for JQ */
  CAAM_ERROR_IRQn              = 147,              /**< Recoverable error interrupt */
  HS_CP0_IRQn                  = 148,              /**< HS Interrupt Request */
  CM7_CTI_IRQn                 = 149,              /**< CTI trigger outputs from CM7 platform */
  ENET1_MAC0_Rx_Tx_Done1_IRQn  = 150,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET1_MAC0_Rx_Tx_Done2_IRQn  = 151,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET1_IRQn                   = 152,              /**< MAC 0 IRQ */
  ENET1_1588_IRQn              = 153,              /**< MAC 0 1588 Timer Interrupt - synchronous */
  ASRC_IRQn                    = 154,              /**< ASRC Interrupt */
  PCIE_CTRL1_0_IRQn            = 155,              /**< Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 0 */
  PCIE_CTRL1_1_IRQn            = 156,              /**< Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 1 */
  PCIE_CTRL1_2_IRQn            = 157,              /**< Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 2 */
  PCIE_CTRL1_3_IRQn            = 158,              /**< Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 3 */
  PCIE_CTRL1_4_IRQn            = 159,              /**< Channels interrupts requests */
  AUDIO_XCVR0_IRQn             = 160,              /**< eARC Interrupt 0 */
  AUDIO_XCVR1_IRQn             = 161,              /**< eARC Interrupt 1 */
  AUD2HTX_IRQn                 = 162,              /**< Audio to HDMI TX Audio Link Master Interrupt */
  EDMA1_ERR_IRQn               = 163,              /**< Audio Subsystem eDMA Error Interrupt */
  EDMA1_0_15_IRQn              = 164,              /**< Audio Subsystem eDMA Channel Interrupts, Logical OR of channels [15:0] */
  EDMA1_16_31_IRQn             = 165,              /**< Audio Subsystem eDMA Channel Interrupts, Logical OR of channels [31:16] */
  ENET_QOS_PMT_IRQn            = 166,              /**< ENET QOS TSN Interrupt from PMT */
  ENET_QOS_IRQn                = 167,              /**< ENET QOS TSN LPI RX exit/Host System/RX/TX Channels[4:0] Interrupt */
  MU2_A53_IRQn                 = 168,              /**< Interrupt to A53 (A53, Audio Processor MU) */
  MU2_AUDIO_IRQn               = 169,              /**< Interrupt to Audio Processor (A53, Audio Processor MU) */
  MU3_M7_IRQn                  = 170,              /**< Interrupt to M7 (M7, Audio Processor MU) */
  MU3_AUDIO_IRQn               = 171,              /**< Interrupt to Audio Processor (M7, Audio Processor MU) */
  PCIE_CTRL1_IRQn              = 172,              /**< RC/EP message transaction Interrupt */
  PCIE_CTRL1_ERR_IRQn          = 173,              /**< RC/EP PME Message and Error Interrupt */
  CAN_FD1_IRQn                 = 174,              /**< CAN-FD1 Interrupt from bus off/line error/RX warning/TX warning/wakeup/match in PN/timeout in PN/busoff done/FD error */
  CAN_FD1_ERROR_IRQn           = 175,              /**< CAN-FD1 Interrupt from correctable error/non correctable error int host/ non correctable error int internal */
  CAN_FD2_IRQn                 = 176,              /**< CAN-FD2 Interrupt from bus off/line error/RX warning/TX warning/wakeup/match in PN/timeout in PN/busoff done/FD error */
  CAN_FD2_ERROR_IRQn           = 177,              /**< CAN-FD2 Interrupt from correctable error/non correctable error int host/ non correctable error int internal */
  AUDIO_XCVR_IRQn              = 178,              /**< eARC PHY - SPDIF wakeup interrupt */
  DDR_ERR_IRQn                 = 179,              /**< DRAM Controller Error Interrupt  */
  USB1_WAKEUP_IRQn             = 180,              /**< USB-1 Wake-up Interrupt */
  USB2_WAKEUP_IRQn             = 181,              /**< USB-2 Wake-up Interrupt */
  MECC_IRQn                    = 182,              /**< OCRAM Memory ECC Interrupt */
  MECC_ERR_IRQn                = 183,              /**< OCRAM Memory ECC Error Interrupt */
  MECC_S_IRQn                  = 184,              /**< OCRAM_S Memory ECC Interrupt */
  MECC_S_ERR_IRQn              = 185               /**< OCRAM_S Memory ECC Error Interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Configuration of the Cortex-A53 Processor and Core Peripherals
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Configuration of the Cortex-A53 Processor and Core Peripherals
 * @{
 */

#define __CA53_REV                     0x0004    /**< Core revision r0p4 */
#define __GIC_PRIO_BITS                5         /**< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< FPU present or not */
#define __FPU_USED                     1         /**< Indicates whether an FPU is used or not */
#define __GIC_PRESENT                  1         /**< Defines if a GIC is present or not */
#define __MMU_PRESENT                  1         /**< MMU present or not */
#define __TIM_PRESENT                  1         /**< Defines if a Timer is present or not */
#define __CACHE_PRESENT                1         /**< CACHE present or not */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC SW_MUX_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC SW_MUX_CTL_PAD collections.
 */
typedef enum _iomuxc_sw_mux_ctl_pad
{
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO00 = 0U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO01 = 1U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO02 = 2U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 3U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO04 = 4U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO05 = 5U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO06 = 6U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO07 = 7U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO08 = 8U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO09 = 9U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO10 = 10U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO11 = 11U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO12 = 12U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO13 = 13U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO14 = 14U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO1_IO15 = 15U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_MDC = 16U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_MDIO = 17U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_TD3 = 18U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_TD2 = 19U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_TD1 = 20U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_TD0 = 21U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_TX_CTL = 22U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_TXC = 23U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_RX_CTL = 24U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_RXC = 25U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_RD0 = 26U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_RD1 = 27U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_RD2 = 28U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ENET_RD3 = 29U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_CLK  = 30U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_CMD  = 31U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA0 = 32U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA1 = 33U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA2 = 34U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA3 = 35U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA4 = 36U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA5 = 37U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA6 = 38U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_DATA7 = 39U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_RESET_B = 40U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD1_STROBE = 41U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_CD_B = 42U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_CLK  = 43U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_CMD  = 44U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_DATA0 = 45U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_DATA1 = 46U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_DATA2 = 47U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_DATA3 = 48U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_RESET_B = 49U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SD2_WP   = 50U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_ALE = 51U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_CE0_B = 52U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_CE1_B = 53U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_CE2_B = 54U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_CE3_B = 55U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_CLE = 56U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA00 = 57U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA01 = 58U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA02 = 59U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA03 = 60U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA04 = 61U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA05 = 62U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA06 = 63U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DATA07 = 64U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_DQS = 65U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_RE_B = 66U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_READY_B = 67U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_WE_B = 68U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_NAND_WP_B = 69U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_RXFS = 70U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_RXC = 71U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_RXD0 = 72U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_RXD1 = 73U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_RXD2 = 74U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_RXD3 = 75U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI5_MCLK = 76U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXFS = 77U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXC = 78U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD0 = 79U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD1 = 80U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD2 = 81U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD3 = 82U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD4 = 83U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD5 = 84U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD6 = 85U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_RXD7 = 86U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXFS = 87U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXC = 88U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD0 = 89U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD1 = 90U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD2 = 91U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD3 = 92U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD4 = 93U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD5 = 94U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD6 = 95U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_TXD7 = 96U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI1_MCLK = 97U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_RXFS = 98U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_RXC = 99U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_RXD0 = 100U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_TXFS = 101U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_TXC = 102U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_TXD0 = 103U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI2_MCLK = 104U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_RXFS = 105U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_RXC = 106U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_RXD = 107U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_TXFS = 108U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_TXC = 109U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_TXD = 110U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SAI3_MCLK = 111U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SPDIF_TX = 112U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SPDIF_RX = 113U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_SPDIF_EXT_CLK = 114U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI1_SCLK = 115U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI1_MOSI = 116U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI1_MISO = 117U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI1_SS0 = 118U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI2_SCLK = 119U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI2_MOSI = 120U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI2_MISO = 121U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_ECSPI2_SS0 = 122U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C1_SCL = 123U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C1_SDA = 124U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C2_SCL = 125U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C2_SDA = 126U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C3_SCL = 127U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C3_SDA = 128U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C4_SCL = 129U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_I2C4_SDA = 130U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART1_RXD = 131U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART1_TXD = 132U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART2_RXD = 133U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART2_TXD = 134U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART3_RXD = 135U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART3_TXD = 136U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART4_RXD = 137U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_UART4_TXD = 138U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_HDMI_DDC_SCL = 139U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_HDMI_DDC_SDA = 140U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_HDMI_CEC = 141U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_HDMI_HPD = 142U,        /**< IOMUXC SW_MUX_CTL_PAD index */
} iomuxc_sw_mux_ctl_pad_t;

/*!
 * @addtogroup iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC SW_PAD_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC SW_PAD_CTL_PAD collections.
 */
typedef enum _iomuxc_sw_pad_ctl_pad
{
    kIOMUXC_SW_PAD_CTL_PAD_BOOT_MODE0 = 0U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_BOOT_MODE1 = 1U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_BOOT_MODE2 = 2U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_BOOT_MODE3 = 3U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_JTAG_MOD = 4U,          /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_JTAG_TDI = 5U,          /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_JTAG_TMS = 6U,          /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_JTAG_TCK = 7U,          /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_JTAG_TDO = 8U,          /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO00 = 9U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO01 = 10U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO02 = 11U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 = 12U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO04 = 13U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO05 = 14U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06 = 15U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07 = 16U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO08 = 17U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO09 = 18U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO10 = 19U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO11 = 20U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO12 = 21U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO13 = 22U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO14 = 23U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO1_IO15 = 24U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_MDC = 25U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_MDIO = 26U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_TD3 = 27U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_TD2 = 28U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_TD1 = 29U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_TD0 = 30U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_TX_CTL = 31U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_TXC = 32U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_RX_CTL = 33U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_RXC = 34U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_RD0 = 35U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_RD1 = 36U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_RD2 = 37U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ENET_RD3 = 38U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_CLK  = 39U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_CMD  = 40U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA0 = 41U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA1 = 42U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA2 = 43U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA3 = 44U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA4 = 45U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA5 = 46U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA6 = 47U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_DATA7 = 48U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_RESET_B = 49U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD1_STROBE = 50U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_CD_B = 51U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_CLK  = 52U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_CMD  = 53U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_DATA0 = 54U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_DATA1 = 55U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_DATA2 = 56U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_DATA3 = 57U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_RESET_B = 58U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SD2_WP   = 59U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_ALE = 60U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_CE0_B = 61U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_CE1_B = 62U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_CE2_B = 63U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_CE3_B = 64U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_CLE = 65U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA00 = 66U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA01 = 67U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA02 = 68U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA03 = 69U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA04 = 70U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA05 = 71U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA06 = 72U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DATA07 = 73U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_DQS = 74U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_RE_B = 75U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_READY_B = 76U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_WE_B = 77U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_NAND_WP_B = 78U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_RXFS = 79U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_RXC = 80U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_RXD0 = 81U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_RXD1 = 82U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_RXD2 = 83U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_RXD3 = 84U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI5_MCLK = 85U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXFS = 86U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXC = 87U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD0 = 88U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD1 = 89U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD2 = 90U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD3 = 91U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD4 = 92U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD5 = 93U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD6 = 94U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_RXD7 = 95U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXFS = 96U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXC = 97U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD0 = 98U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD1 = 99U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD2 = 100U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD3 = 101U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD4 = 102U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD5 = 103U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD6 = 104U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_TXD7 = 105U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI1_MCLK = 106U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_RXFS = 107U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_RXC = 108U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_RXD0 = 109U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_TXFS = 110U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_TXC = 111U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_TXD0 = 112U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI2_MCLK = 113U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_RXFS = 114U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_RXC = 115U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_RXD = 116U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_TXFS = 117U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_TXC = 118U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_TXD = 119U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SAI3_MCLK = 120U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SPDIF_TX = 121U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SPDIF_RX = 122U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_SPDIF_EXT_CLK = 123U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI1_SCLK = 124U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI1_MOSI = 125U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI1_MISO = 126U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI1_SS0 = 127U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI2_SCLK = 128U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI2_MOSI = 129U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI2_MISO = 130U,     /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_ECSPI2_SS0 = 131U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C1_SCL = 132U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C1_SDA = 133U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C2_SCL = 134U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C2_SDA = 135U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C3_SCL = 136U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C3_SDA = 137U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C4_SCL = 138U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_I2C4_SDA = 139U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART1_RXD = 140U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART1_TXD = 141U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART2_RXD = 142U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART2_TXD = 143U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART3_RXD = 144U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART3_TXD = 145U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART4_RXD = 146U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_UART4_TXD = 147U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_HDMI_DDC_SCL = 148U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_HDMI_DDC_SDA = 149U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_HDMI_CEC = 150U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_HDMI_HPD = 151U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_CLKIN1   = 152U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_CLKIN2   = 153U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_CLKOUT1  = 154U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_CLKOUT2  = 155U,        /**< IOMUXC SW_PAD_CTL_PAD index */
} iomuxc_sw_pad_ctl_pad_t;

/* @} */

/*!
 * @brief Enumeration for the IOMUXC select input
 *
 * Defines the enumeration for the IOMUXC select input collections.
 */
typedef enum _iomuxc_select_input
{
    kIOMUXC_AUDIOMIX_PDM_MIC_PDM_BITSTREAM_SELECT_INPUT_0 = 0U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_PDM_MIC_PDM_BITSTREAM_SELECT_INPUT_1 = 1U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_PDM_MIC_PDM_BITSTREAM_SELECT_INPUT_2 = 2U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_PDM_MIC_PDM_BITSTREAM_SELECT_INPUT_3 = 3U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI1_RXSYNC_SELECT_INPUT = 4U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI1_TXBCLK_SELECT_INPUT = 5U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI1_TXSYNC_SELECT_INPUT = 6U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI2_RXDATA_SELECT_INPUT_1 = 7U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI3_MCLK_SELECT_INPUT = 8U,  /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI3_RXDATA_SELECT_INPUT_0 = 9U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI3_TXBCLK_SELECT_INPUT = 10U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI3_TXSYNC_SELECT_INPUT = 11U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_MCLK_SELECT_INPUT = 12U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_RXBCLK_SELECT_INPUT = 13U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_RXDATA_SELECT_INPUT_0 = 14U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_RXDATA_SELECT_INPUT_1 = 15U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_RXDATA_SELECT_INPUT_2 = 16U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_RXDATA_SELECT_INPUT_3 = 17U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_RXSYNC_SELECT_INPUT = 18U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_TXBCLK_SELECT_INPUT = 19U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI5_TXSYNC_SELECT_INPUT = 20U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI6_MCLK_SELECT_INPUT = 21U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI6_RXBCLK_SELECT_INPUT = 22U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI6_RXDATA_SELECT_INPUT_0 = 23U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI6_RXSYNC_SELECT_INPUT = 24U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI6_TXBCLK_SELECT_INPUT = 25U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI6_TXSYNC_SELECT_INPUT = 26U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI7_MCLK_SELECT_INPUT = 27U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI7_RXBCLK_SELECT_INPUT = 28U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI7_RXDATA_SELECT_INPUT_0 = 29U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI7_RXSYNC_SELECT_INPUT = 30U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI7_TXBCLK_SELECT_INPUT = 31U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SAI7_TXSYNC_SELECT_INPUT = 32U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_EARC_PHY_SPDIF_IN_SELECT_INPUT = 33U, /**< IOMUXC select input index */
    kIOMUXC_AUDIOMIX_SPDIF_EXTCLK_SELECT_INPUT = 34U, /**< IOMUXC select input index */
    kIOMUXC_CAN1_CANRX_SELECT_INPUT = 35U,         /**< IOMUXC select input index */
    kIOMUXC_CAN2_CANRX_SELECT_INPUT = 36U,         /**< IOMUXC select input index */
    kIOMUXC_CCM_GPC_PMIC_VFUNCTIONAL_READY_SELECT_INPUT = 37U, /**< IOMUXC select input index */
    kIOMUXC_ECSPI1_CSPI_CLK_IN_SELECT_INPUT = 38U, /**< IOMUXC select input index */
    kIOMUXC_ECSPI1_MISO_SELECT_INPUT = 39U,        /**< IOMUXC select input index */
    kIOMUXC_ECSPI1_MOSI_SELECT_INPUT = 40U,        /**< IOMUXC select input index */
    kIOMUXC_ECSPI1_SS_B_SELECT_INPUT_0 = 41U,      /**< IOMUXC select input index */
    kIOMUXC_ECSPI2_CSPI_CLK_IN_SELECT_INPUT = 42U, /**< IOMUXC select input index */
    kIOMUXC_ECSPI2_MISO_SELECT_INPUT = 43U,        /**< IOMUXC select input index */
    kIOMUXC_ECSPI2_MOSI_SELECT_INPUT = 44U,        /**< IOMUXC select input index */
    kIOMUXC_ECSPI2_SS_B_SELECT_INPUT_0 = 45U,      /**< IOMUXC select input index */
    kIOMUXC_ENET1_IPG_CLK_RMII_SELECT_INPUT = 46U, /**< IOMUXC select input index */
    kIOMUXC_ENET1_MDIO_SELECT_INPUT = 47U,         /**< IOMUXC select input index */
    kIOMUXC_ENET1_RXDATA_0_SELECT_INPUT = 48U,     /**< IOMUXC select input index */
    kIOMUXC_ENET1_RXDATA_1_SELECT_INPUT = 49U,     /**< IOMUXC select input index */
    kIOMUXC_ENET1_RXEN_SELECT_INPUT = 50U,         /**< IOMUXC select input index */
    kIOMUXC_ENET1_RXERR_SELECT_INPUT = 51U,        /**< IOMUXC select input index */
    kIOMUXC_ENET_QOS_GMII_MDI_I_SELECT_INPUT = 52U, /**< IOMUXC select input index */
    kIOMUXC_GPT1_CAPIN1_SELECT_INPUT = 53U,        /**< IOMUXC select input index */
    kIOMUXC_GPT1_CAPIN2_SELECT_INPUT = 54U,        /**< IOMUXC select input index */
    kIOMUXC_GPT1_CLKIN_SELECT_INPUT = 55U,         /**< IOMUXC select input index */
    kIOMUXC_PCIE_CLKREQ_B_SELECT_INPUT = 56U,      /**< IOMUXC select input index */
    kIOMUXC_I2C1_SCL_IN_SELECT_INPUT = 57U,        /**< IOMUXC select input index */
    kIOMUXC_I2C1_SDA_IN_SELECT_INPUT = 58U,        /**< IOMUXC select input index */
    kIOMUXC_I2C2_SCL_IN_SELECT_INPUT = 59U,        /**< IOMUXC select input index */
    kIOMUXC_I2C2_SDA_IN_SELECT_INPUT = 60U,        /**< IOMUXC select input index */
    kIOMUXC_I2C3_SCL_IN_SELECT_INPUT = 61U,        /**< IOMUXC select input index */
    kIOMUXC_I2C3_SDA_IN_SELECT_INPUT = 62U,        /**< IOMUXC select input index */
    kIOMUXC_I2C4_SCL_IN_SELECT_INPUT = 63U,        /**< IOMUXC select input index */
    kIOMUXC_I2C4_SDA_IN_SELECT_INPUT = 64U,        /**< IOMUXC select input index */
    kIOMUXC_I2C5_SCL_IN_SELECT_INPUT = 65U,        /**< IOMUXC select input index */
    kIOMUXC_I2C5_SDA_IN_SELECT_INPUT = 66U,        /**< IOMUXC select input index */
    kIOMUXC_I2C6_SCL_IN_SELECT_INPUT = 67U,        /**< IOMUXC select input index */
    kIOMUXC_I2C6_SDA_IN_SELECT_INPUT = 68U,        /**< IOMUXC select input index */
    kIOMUXC_ISP_FL_TRIG_0_SELECT_INPUT = 69U,      /**< IOMUXC select input index */
    kIOMUXC_ISP_FL_TRIG_1_SELECT_INPUT = 70U,      /**< IOMUXC select input index */
    kIOMUXC_ISP_SHUTTER_TRIG_0_SELECT_INPUT = 71U, /**< IOMUXC select input index */
    kIOMUXC_ISP_SHUTTER_TRIG_1_SELECT_INPUT = 72U, /**< IOMUXC select input index */
    kIOMUXC_UART1_UART_RTS_B_SELECT_INPUT = 73U,   /**< IOMUXC select input index */
    kIOMUXC_UART1_UART_RXD_MUX_SELECT_INPUT = 74U, /**< IOMUXC select input index */
    kIOMUXC_UART2_UART_RTS_B_SELECT_INPUT = 75U,   /**< IOMUXC select input index */
    kIOMUXC_UART2_UART_RXD_MUX_SELECT_INPUT = 76U, /**< IOMUXC select input index */
    kIOMUXC_UART3_UART_RTS_B_SELECT_INPUT = 77U,   /**< IOMUXC select input index */
    kIOMUXC_UART3_UART_RXD_MUX_SELECT_INPUT = 78U, /**< IOMUXC select input index */
    kIOMUXC_UART4_UART_RTS_B_SELECT_INPUT = 79U,   /**< IOMUXC select input index */
    kIOMUXC_UART4_UART_RXD_MUX_SELECT_INPUT = 80U, /**< IOMUXC select input index */
    kIOMUXC_USDHC3_CARD_CLK_IN_SELECT_INPUT = 81U, /**< IOMUXC select input index */
    kIOMUXC_USDHC3_CARD_DET_SELECT_INPUT = 82U,    /**< IOMUXC select input index */
    kIOMUXC_USDHC3_CMD_IN_SELECT_INPUT = 83U,      /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT0_IN_SELECT_INPUT = 84U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT1_IN_SELECT_INPUT = 85U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT2_IN_SELECT_INPUT = 86U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT3_IN_SELECT_INPUT = 87U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT4_IN_SELECT_INPUT = 88U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT5_IN_SELECT_INPUT = 89U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT6_IN_SELECT_INPUT = 90U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_DAT7_IN_SELECT_INPUT = 91U,     /**< IOMUXC select input index */
    kIOMUXC_USDHC3_STROBE_SELECT_INPUT = 92U,      /**< IOMUXC select input index */
    kIOMUXC_USDHC3_WP_ON_SELECT_INPUT = 93U,       /**< IOMUXC select input index */
} iomuxc_select_input_t;

/*!
 * @addtogroup rdc_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the RDC mapping
 *
 * Defines the structure for the RDC resource collections.
 */

typedef enum _rdc_master
{
    kRDC_Master_A53                 = 0U,          /**< ARM Cortex-A53 RDC Master */
    kRDC_Master_M7                  = 1U,          /**< ARM Cortex-M7 RDC Master */
    kRDC_PCIE_CTRL1                 = 2U,          /**< Reserved */
    kRDC_Master_SDMA3_PERIPH        = 3U,          /**< SDMA3 PERIPHERAL RDC Master */
    kRDC_Master_SDMA3_BURST         = 4U,          /**< SDMA3 BURST RDC Master */
    kRDC_Master_LCDIF1              = 5U,          /**< LCDIF1 RDC Master */
    kRDC_Master_ISI                 = 6U,          /**< ISI PORT RDC Master */
    kRDC_Master_NPU                 = 7U,          /**< NPU RDC Master */
    kRDC_Master_Coresight           = 8U,          /**< CORESIGHT RDC Master */
    kRDC_Master_DAP                 = 9U,          /**< DAP RDC Master */
    kRDC_Master_CAAM                = 10U,         /**< CAAM RDC Master */
    kRDC_Master_SDMA1_PERIPH        = 11U,         /**< SDMA1 PERIPHERAL RDC Master */
    kRDC_Master_SDMA1_BURST         = 12U,         /**< SDMA1 BURST RDC Master */
    kRDC_Master_APBHDMA             = 13U,         /**< APBH DMA RDC Master */
    kRDC_Master_RAWNAND             = 14U,         /**< RAW NAND RDC Master */
    kRDC_Master_USDHC1              = 15U,         /**< USDHC1 RDC Master */
    kRDC_Master_USDHC2              = 16U,         /**< USDHC2 RDC Master */
    kRDC_Master_USDHC3              = 17U,         /**< USDHC3 RDC Master */
    kRDC_Master_AUDIO_PROCESSOR     = 18U,         /**< AUDIO PROCESSOR RDC Master */
    kRDC_Master_USB1                = 19U,         /**< USB1 RDC Master */
    kRDC_Master_USB2                = 20U,         /**< USB2 RDC Master */
    kRDC_Master_TESTPORT            = 21U,         /**< TESTPORT RDC Master */
    kRDC_Master_ENET1TX             = 22U,         /**< ENET1 TX RDC Master */
    kRDC_Master_ENET1RX             = 23U,         /**< ENET1 RX RDC Master */
    kRDC_Master_SDMA2_PERIPH        = 24U,         /**< SDMA2 PERIPH RDC Master */
    kRDC_Master_SDMA2_BURST         = 24U,         /**< SDMA2 BURST RDC Master */
    kRDC_Master_SDMA2_SPBA2         = 24U,         /**< SDMA2 to SPBA2 RDC Master */
    kRDC_Master_SDMA3_SPBA2         = 25U,         /**< SDMA3 to SPBA2 RDC Master */
    kRDC_Master_SDMA1_SPBA1         = 26U,         /**< SDMA1 to SPBA1 RDC Master */
    kRDC_Master_LCDIF2              = 27U,         /**< LCDIF2 RDC Master */
    kRDC_Master_HDMI_TX             = 28U,         /**< HDMI_TX RDC Master */
    kRDC_Master_ENET2               = 29U,         /**< ENET2 RDC Master */
    kRDC_Master_GPU3D               = 30U,         /**< GPU3D RDC Master */
    kRDC_Master_GPU2D               = 31U,         /**< GPU2D RDC Master */
    kRDC_Master_VPU_G1              = 32U,         /**< VPU_G1 RDC Master */
    kRDC_Master_VPU_G2              = 33U,         /**< VPU_G2 RDC Master */
    kRDC_Master_VPU_VC8000E         = 34U,         /**< VPU_VC8000E RDC Master */
    kRDC_Master_AUDIO_EDMA          = 35U,         /**< AUDIO_EDMA RDC Master */
    kRDC_Master_ISP1                = 36U,         /**< ISP1 RDC Master */
    kRDC_Master_ISP2                = 37U,         /**< ISP2 RDC Master */
    kRDC_Master_DEWARP              = 38U,         /**< DEWARP RDC Master */
    kRDC_Master_GIC500              = 39U,         /**< GIC500 RDC Master */
} rdc_master_t;

typedef enum _rdc_mem
{
    kRDC_Mem_MRC0_0                 = 0U,          /**< DEBUG(DAP). Region resolution 4KB. */
    kRDC_Mem_MRC0_1                 = 1U,
    kRDC_Mem_MRC0_2                 = 2U,
    kRDC_Mem_MRC0_3                 = 3U,
    kRDC_Mem_MRC1_0                 = 4U,          /**< QSPI. Region resolution 4KB. */
    kRDC_Mem_MRC1_1                 = 5U,
    kRDC_Mem_MRC1_2                 = 6U,
    kRDC_Mem_MRC1_3                 = 7U,
    kRDC_Mem_MRC1_4                 = 8U,
    kRDC_Mem_MRC1_5                 = 9U,
    kRDC_Mem_MRC1_6                 = 10U,
    kRDC_Mem_MRC1_7                 = 11U,
    kRDC_Mem_MRC2_0                 = 12U,         /**< OCRAM. Region resolution 128B. */
    kRDC_Mem_MRC2_1                 = 13U,
    kRDC_Mem_MRC2_2                 = 14U,
    kRDC_Mem_MRC2_3                 = 15U,
    kRDC_Mem_MRC2_4                 = 16U,
    kRDC_Mem_MRC3_0                 = 17U,         /**< OCRAM_S. Region resolution 128B. */
    kRDC_Mem_MRC3_1                 = 18U,
    kRDC_Mem_MRC3_2                 = 19U,
    kRDC_Mem_MRC3_3                 = 20U,
    kRDC_Mem_MRC3_4                 = 21U,
    kRDC_Mem_MRC4_0                 = 22U,         /**< TCM. Region resolution 128B. */
    kRDC_Mem_MRC4_1                 = 23U,
    kRDC_Mem_MRC4_2                 = 24U,
    kRDC_Mem_MRC4_3                 = 25U,
    kRDC_Mem_MRC4_4                 = 26U,
    kRDC_Mem_MRC5_0                 = 27U,         /**< GIC. Region resolution 4KB. */
    kRDC_Mem_MRC5_1                 = 28U,
    kRDC_Mem_MRC5_2                 = 29U,
    kRDC_Mem_MRC5_3                 = 30U,
    kRDC_Mem_MRC6_0                 = 31U,         /**< GPU. Region resolution 4KB. */
    kRDC_Mem_MRC6_1                 = 32U,
    kRDC_Mem_MRC6_2                 = 33U,
    kRDC_Mem_MRC6_3                 = 34U,
    kRDC_Mem_MRC6_4                 = 35U,
    kRDC_Mem_MRC6_5                 = 36U,
    kRDC_Mem_MRC6_6                 = 37U,
    kRDC_Mem_MRC6_7                 = 38U,
    kRDC_Mem_MRC7_0                 = 39U,         /**< DRAM. Region resolution 4KB. */
    kRDC_Mem_MRC7_1                 = 40U,
    kRDC_Mem_MRC7_2                 = 41U,
    kRDC_Mem_MRC7_3                 = 42U,
    kRDC_Mem_MRC7_4                 = 43U,
    kRDC_Mem_MRC7_5                 = 44U,
    kRDC_Mem_MRC7_6                 = 45U,
    kRDC_Mem_MRC7_7                 = 46U,
    kRDC_Mem_MRC8_0                 = 47U,         /**< DDRC(REG). Region resolution 4KB. */
    kRDC_Mem_MRC8_1                 = 48U,
    kRDC_Mem_MRC8_2                 = 49U,
    kRDC_Mem_MRC8_3                 = 50U,
    kRDC_Mem_MRC8_4                 = 51U,
    kRDC_Mem_MRC9_0                 = 52U,         /**< PCIe1, USB1/2. Region resolution 4KB. */
    kRDC_Mem_MRC9_1                 = 53U,
    kRDC_Mem_MRC9_2                 = 54U,
    kRDC_Mem_MRC9_3                 = 55U,
    kRDC_Mem_MRC9_4                 = 56U,
    kRDC_Mem_MRC9_5                 = 57U,
    kRDC_Mem_MRC9_6                 = 58U,
    kRDC_Mem_MRC9_7                 = 59U,
    kRDC_Mem_MRC10_0                = 60U,         /**< VPU. Region resolution 4KB. */
    kRDC_Mem_MRC10_1                = 61U,
    kRDC_Mem_MRC10_2                = 62U,
    kRDC_Mem_MRC10_3                = 63U,
    kRDC_Mem_MRC11_0                = 64U,         /**< NPU. Region resolution 4KB. */
    kRDC_Mem_MRC11_1                = 65U,
    kRDC_Mem_MRC11_2                = 66U,
    kRDC_Mem_MRC11_3                = 67U,
    kRDC_Mem_MRC12_0                = 68U,         /**< AUDIO PROCESSOR. Region resolution 4KB. */
    kRDC_Mem_MRC12_1                = 69U,
    kRDC_Mem_MRC12_2                = 70U,
    kRDC_Mem_MRC12_3                = 71U,
    kRDC_Mem_MRC13_0                = 72U,         /**< OCRAM_A. Region resolution 128B. */
    kRDC_Mem_MRC13_1                = 73U,
    kRDC_Mem_MRC13_2                = 74U,
    kRDC_Mem_MRC13_3                = 75U,
    kRDC_Mem_MRC13_4                = 76U,
} rdc_mem_t;

typedef enum _rdc_periph
{
    kRDC_Periph_GPIO1               = 0U,          /**< GPIO1 RDC Peripheral */
    kRDC_Periph_GPIO2               = 1U,          /**< GPIO2 RDC Peripheral */
    kRDC_Periph_GPIO3               = 2U,          /**< GPIO3 RDC Peripheral */
    kRDC_Periph_GPIO4               = 3U,          /**< GPIO4 RDC Peripheral */
    kRDC_Periph_GPIO5               = 4U,          /**< GPIO5 RDC Peripheral */
    kRDC_Periph_MU2_A               = 5U,          /**< MU_2_A (A53, Audio Processor) RDC Peripheral */
    kRDC_Periph_ANA_TSENSOR         = 6U,          /**< ANA_TSENSOR RDC Peripheral */
    kRDC_Periph_ANA_OSC             = 7U,          /**< ANA_OSC RDC Peripheral */
    kRDC_Periph_WDOG1               = 8U,          /**< WDOG1 RDC Peripheral */
    kRDC_Periph_WDOG2               = 9U,          /**< WDOG2 RDC Peripheral */
    kRDC_Periph_WDOG3               = 10U,         /**< WDOG3 RDC Peripheral */
    kRDC_Periph_OCRAM_MECC          = 11U,         /**< OCRAM MECC RDC Peripheral */
    kRDC_Periph_OCRAM_S_MECC        = 12U,         /**< OCRAM_S MECC RDC Peripheral */
    kRDC_Periph_GPT1                = 13U,         /**< GPT1 RDC Peripheral */
    kRDC_Periph_GPT2                = 14U,         /**< GPT2 RDC Peripheral */
    kRDC_Periph_GPT3                = 15U,         /**< GPT3 RDC Peripheral */
    kRDC_Periph_MU2_B               = 16U,         /**< MU_2_B (A53, Audio Processor) RDC Peripheral */
    kRDC_Periph_ROMCP               = 17U,         /**< ROMCP RDC Peripheral */
    kRDC_Periph_MU3_A               = 18U,         /**< MU_3_A (M7, Audio Processor) RDC Peripheral */
    kRDC_Periph_IOMUXC              = 19U,         /**< IOMUXC RDC Peripheral */
    kRDC_Periph_IOMUXC_GPR          = 20U,         /**< IOMUXC_GPR RDC Peripheral */
    kRDC_Periph_OCOTP_CTRL          = 21U,         /**< OCOTP_CTRL RDC Peripheral */
    kRDC_Periph_ANA_PLL             = 22U,         /**< ANA_PLL RDC Peripheral */
    kRDC_Periph_SNVS_HP             = 23U,         /**< SNVS_HP GPR RDC Peripheral */
    kRDC_Periph_CCM                 = 24U,         /**< CCM RDC Peripheral */
    kRDC_Periph_SRC                 = 25U,         /**< SRC RDC Peripheral */
    kRDC_Periph_GPC                 = 26U,         /**< GPC RDC Peripheral */
    kRDC_Periph_SEMAPHORE1          = 27U,         /**< SEMAPHORE1 RDC Peripheral */
    kRDC_Periph_SEMAPHORE2          = 28U,         /**< SEMAPHORE2 RDC Peripheral */
    kRDC_Periph_RDC                 = 29U,         /**< RDC RDC Peripheral */
    kRDC_Periph_CSU                 = 30U,         /**< CSU RDC Peripheral */
    kRDC_Periph_MU3_B               = 31U,         /**< MU_3_B (M7, Audio Processor) RDC Peripheral */
    kRDC_Periph_ISI                 = 32U,         /**< ISI RDC Peripheral */
    kRDC_Periph_ISP0                = 33U,         /**< ISP0 RDC Peripheral */
    kRDC_Periph_ISP1                = 34U,         /**< ISP1 RDC Peripheral */
    kRDC_Periph_IPS_DEWARP          = 35U,         /**< IPS DEWARP RDC Peripheral */
    kRDC_Periph_MIPI_CSI0           = 36U,         /**< MIPI CSI0 RDC Peripheral */
    kRDC_Periph_HSIOMIX_BLK_CTL     = 37U,         /**< HSIOMIX BLK CTL RDC Peripheral */
    kRDC_Periph_PWM1                = 38U,         /**< PWM1 RDC Peripheral */
    kRDC_Periph_PWM2                = 39U,         /**< PWM2 RDC Peripheral */
    kRDC_Periph_PWM3                = 40U,         /**< PWM3 RDC Peripheral */
    kRDC_Periph_PWM4                = 41U,         /**< PWM4 RDC Peripheral */
    kRDC_Periph_SYS_COUNTER_RD      = 42U,         /**< System counter read RDC Peripheral */
    kRDC_Periph_SYS_COUNTER_CMP     = 43U,         /**< System counter compare RDC Peripheral */
    kRDC_Periph_SYS_COUNTER_CTRL    = 44U,         /**< System counter control RDC Peripheral */
    kRDC_Periph_I2C5                = 45U,         /**< I2C1 RDC Peripheral */
    kRDC_Periph_GPT6                = 46U,         /**< GPT6 RDC Peripheral */
    kRDC_Periph_GPT5                = 47U,         /**< GPT5 RDC Peripheral */
    kRDC_Periph_GPT4                = 48U,         /**< GPT4 RDC Peripheral */
    kRDC_Periph_MIPI_CSI1           = 49U,         /**< MIPI CSI1 RDC Peripheral */
    kRDC_Periph_MIPI_DSI0           = 50U,         /**< MIPI DSI0 RDC Peripheral */
    kRDC_Periph_MEDIAMIX_BLK_CTL    = 51U,         /**< MEDIAMIX BLK CTL RDC Peripheral */
    kRDC_Periph_LCDIF1              = 52U,         /**< LCDIF1 RDC Peripheral */
    kRDC_Periph_EDMA                = 53U,         /**< EDMA RDC Peripheral */
    kRDC_Periph_EDMA_0_15           = 54U,         /**< EDMA Channels [0:15] RDC Peripheral */
    kRDC_Periph_EDMA_16_31          = 55U,         /**< EDMA Channels [1:31] RDC Peripheral */
    kRDC_Periph_TZASC               = 56U,         /**< TZASC RDC Peripheral */
    kRDC_Periph_I2C6                = 57U,         /**< I2C6 RDC Peripheral */
    kRDC_Periph_CAAM                = 58U,         /**< CAAM RDC Peripheral */
    kRDC_Periph_LCDIF2              = 59U,         /**< LCDIF2 RDC Peripheral */
    kRDC_Periph_PERFMON1            = 60U,         /**< PERFMON1 RDC Peripheral */
    kRDC_Periph_PERFMON2            = 61U,         /**< PERFMON2 RDC Peripheral */
    kRDC_Periph_PLATFORM_CTRL       = 62U,         /**< PLATFORM_CTRL RDC Peripheral */
    kRDC_Periph_QOSC                = 63U,         /**< QOSC RDC Peripheral */
    kRDC_Periph_LVDS0               = 64U,         /**< LVDS0 RDC Peripheral */
    kRDC_Periph_LVDS1               = 65U,         /**< LVDS1 RDC Peripheral */
    kRDC_Periph_I2C1                = 66U,         /**< I2C1 RDC Peripheral */
    kRDC_Periph_I2C2                = 67U,         /**< I2C2 RDC Peripheral */
    kRDC_Periph_I2C3                = 68U,         /**< I2C3 RDC Peripheral */
    kRDC_Periph_I2C4                = 69U,         /**< I2C4 RDC Peripheral */
    kRDC_Periph_UART4               = 70U,         /**< UART4 RDC Peripheral */
    kRDC_Periph_HDMI_TX             = 71U,         /**< HDMI TX RDC Peripheral */
    kRDC_Periph_IRQ_STEER           = 72U,         /**< IRQ STEER (Audio Processor) RDC Peripheral */
    kRDC_Periph_SDMA2               = 73U,         /**< SDMA2 RDC Peripheral */
    kRDC_Periph_MU1_A               = 74U,         /**< MU1_A RDC Peripheral */
    kRDC_Periph_MU1_B               = 75U,         /**< MU1_B RDC Peripheral */
    kRDC_Periph_SEMAPHORE_HS        = 76U,         /**< SEMAPHORE_HS RDC Peripheral */
    kRDC_Periph_SAI1                = 78U,         /**< SAI1 RDC Peripheral */
    kRDC_Periph_SAI2                = 79U,         /**< SAI2 RDC Peripheral */
    kRDC_Periph_SAI3                = 80U,         /**< SAI3 RDC Peripheral */
    kRDC_Periph_CAN_FD1             = 81U,         /**< CAN_FD1 RDC Peripheral */
    kRDC_Periph_SAI5                = 82U,         /**< SAI5 RDC Peripheral */
    kRDC_Periph_SAI6                = 83U,         /**< SAI6 RDC Peripheral */
    kRDC_Periph_USDHC1              = 84U,         /**< USDHC1 RDC Peripheral */
    kRDC_Periph_USDHC2              = 85U,         /**< USDHC2 RDC Peripheral */
    kRDC_Periph_USDHC3              = 86U,         /**< USDHC3 RDC Peripheral */
    kRDC_Periph_PCIE_PHY1           = 87U,         /**< PCIE PHY1 RDC Peripheral */
    kRDC_Periph_HDMI_TX_AUDLNK_MSTR = 88U,         /**< HDMI TX AUDLNK MSTR RDC Peripheral */
    kRDC_Periph_CAN_FD2             = 89U,         /**< CAN_FD2 RDC Peripheral */
    kRDC_Periph_SPBA2               = 90U,         /**< SPBA2 RDC Peripheral */
    kRDC_Periph_QSPI                = 91U,         /**< QSPI RDC Peripheral */
    kRDC_Periph_AUDIO_BLK_CTRL      = 92U,         /**< AUDIO BLK CTRL RDC Peripheral */
    kRDC_Periph_SDMA1               = 93U,         /**< SDMA1 RDC Peripheral */
    kRDC_Periph_ENET1               = 94U,         /**< ENET1 RDC Peripheral */
    kRDC_Periph_ENET2_TSN           = 95U,         /**< ENET2 TSN RDC Peripheral */
    kRDC_Periph_SPDIF1              = 97U,         /**< SPDIF1 RDC Peripheral */
    kRDC_Periph_ECSPI1              = 98U,         /**< ECSPI1 RDC Peripheral */
    kRDC_Periph_ECSPI2              = 99U,         /**< ECSPI2 RDC Peripheral */
    kRDC_Periph_ECSPI3              = 100U,        /**< ECSPI3 RDC Peripheral */
    kRDC_Periph_SAI7                = 101U,        /**< SAI7 RDC Peripheral */
    kRDC_Periph_UART1               = 102U,        /**< UART1 RDC Peripheral */
    kRDC_Periph_UART3               = 104U,        /**< UART3 RDC Peripheral */
    kRDC_Periph_UART2               = 105U,        /**< UART2 RDC Peripheral */
    kRDC_Periph_PDM                 = 106U,        /**< PDM (MICFIL) RDC Peripheral */
    kRDC_Periph_AUDIO_XCVR_RX       = 107U,        /**< AUDIO XCVR RX RDC (eARC)Peripheral */
    kRDC_Periph_SDMA3               = 109U,        /**< SDMA3 RDC Peripheral */
    kRDC_Periph_SPBA1               = 111U,        /**< SPBA1 RDC Peripheral */
} rdc_periph_t;

/* @} */

/*!
 * @}
 */ /* end of group Mapping_Information */

/* ----------------------------------------------------------------------------
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR0;                              /**< General Purpose Register, offset: 0x0 */
  __IO uint32_t GPR0_SET;                          /**< General Purpose Register, offset: 0x4 */
  __IO uint32_t GPR0_CLR;                          /**< General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR0_TOG;                          /**< General Purpose Register, offset: 0xC */
       uint8_t RESERVED_0[2032];
  struct {                                         /* offset: 0x800, array step: 0x10 */
    __IO uint32_t PLL_CTRL;                          /**< CCM PLL Control Register, array offset: 0x800, array step: 0x10 */
    __IO uint32_t PLL_CTRL_SET;                      /**< CCM PLL Control Register, array offset: 0x804, array step: 0x10 */
    __IO uint32_t PLL_CTRL_CLR;                      /**< CCM PLL Control Register, array offset: 0x808, array step: 0x10 */
    __IO uint32_t PLL_CTRL_TOG;                      /**< CCM PLL Control Register, array offset: 0x80C, array step: 0x10 */
  } PLL_CTRL[39];
       uint8_t RESERVED_1[13712];
  struct {                                         /* offset: 0x4000, array step: 0x10 */
    __IO uint32_t CCGR;                              /**< CCM Clock Gating Register, array offset: 0x4000, array step: 0x10 */
    __IO uint32_t CCGR_SET;                          /**< CCM Clock Gating Register, array offset: 0x4004, array step: 0x10 */
    __IO uint32_t CCGR_CLR;                          /**< CCM Clock Gating Register, array offset: 0x4008, array step: 0x10 */
    __IO uint32_t CCGR_TOG;                          /**< CCM Clock Gating Register, array offset: 0x400C, array step: 0x10 */
  } CCGR[192];
       uint8_t RESERVED_2[13312];
  struct {                                         /* offset: 0x8000, array step: 0x80 */
    __IO uint32_t TARGET_ROOT;                       /**< Target Register, array offset: 0x8000, array step: 0x80 */
    __IO uint32_t TARGET_ROOT_SET;                   /**< Target Register, array offset: 0x8004, array step: 0x80 */
    __IO uint32_t TARGET_ROOT_CLR;                   /**< Target Register, array offset: 0x8008, array step: 0x80 */
    __IO uint32_t TARGET_ROOT_TOG;                   /**< Target Register, array offset: 0x800C, array step: 0x80 */
    __IO uint32_t MISC;                              /**< Miscellaneous Register, array offset: 0x8010, array step: 0x80 */
    __IO uint32_t MISC_ROOT_SET;                     /**< Miscellaneous Register, array offset: 0x8014, array step: 0x80 */
    __IO uint32_t MISC_ROOT_CLR;                     /**< Miscellaneous Register, array offset: 0x8018, array step: 0x80 */
    __IO uint32_t MISC_ROOT_TOG;                     /**< Miscellaneous Register, array offset: 0x801C, array step: 0x80 */
    __IO uint32_t POST;                              /**< Post Divider Register, array offset: 0x8020, array step: 0x80 */
    __IO uint32_t POST_ROOT_SET;                     /**< Post Divider Register, array offset: 0x8024, array step: 0x80 */
    __IO uint32_t POST_ROOT_CLR;                     /**< Post Divider Register, array offset: 0x8028, array step: 0x80 */
    __IO uint32_t POST_ROOT_TOG;                     /**< Post Divider Register, array offset: 0x802C, array step: 0x80 */
    __IO uint32_t PRE;                               /**< Pre Divider Register, array offset: 0x8030, array step: 0x80 */
    __IO uint32_t PRE_ROOT_SET;                      /**< Pre Divider Register, array offset: 0x8034, array step: 0x80 */
    __IO uint32_t PRE_ROOT_CLR;                      /**< Pre Divider Register, array offset: 0x8038, array step: 0x80 */
    __IO uint32_t PRE_ROOT_TOG;                      /**< Pre Divider Register, array offset: 0x803C, array step: 0x80 */
         uint8_t RESERVED_0[48];
    __IO uint32_t ACCESS_CTRL;                       /**< Access Control Register, array offset: 0x8070, array step: 0x80 */
    __IO uint32_t ACCESS_CTRL_ROOT_SET;              /**< Access Control Register, array offset: 0x8074, array step: 0x80 */
    __IO uint32_t ACCESS_CTRL_ROOT_CLR;              /**< Access Control Register, array offset: 0x8078, array step: 0x80 */
    __IO uint32_t ACCESS_CTRL_ROOT_TOG;              /**< Access Control Register, array offset: 0x807C, array step: 0x80 */
  } ROOT[142];
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name GPR0 - General Purpose Register */
/*! @{ */

#define CCM_GPR0_GP0_MASK                        (0xFFFFFFFFU)
#define CCM_GPR0_GP0_SHIFT                       (0U)
#define CCM_GPR0_GP0(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_GP0_SHIFT)) & CCM_GPR0_GP0_MASK)
/*! @} */

/*! @name GPR0_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR0_SET_GP0_MASK                    (0xFFFFFFFFU)
#define CCM_GPR0_SET_GP0_SHIFT                   (0U)
#define CCM_GPR0_SET_GP0(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_SET_GP0_SHIFT)) & CCM_GPR0_SET_GP0_MASK)
/*! @} */

/*! @name GPR0_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR0_CLR_GP0_MASK                    (0xFFFFFFFFU)
#define CCM_GPR0_CLR_GP0_SHIFT                   (0U)
#define CCM_GPR0_CLR_GP0(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_CLR_GP0_SHIFT)) & CCM_GPR0_CLR_GP0_MASK)
/*! @} */

/*! @name GPR0_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR0_TOG_GP0_MASK                    (0xFFFFFFFFU)
#define CCM_GPR0_TOG_GP0_SHIFT                   (0U)
#define CCM_GPR0_TOG_GP0(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_TOG_GP0_SHIFT)) & CCM_GPR0_TOG_GP0_MASK)
/*! @} */

/*! @name PLL_CTRL - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_SETTING0_MASK               (0x3U)
#define CCM_PLL_CTRL_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING0_SHIFT)) & CCM_PLL_CTRL_SETTING0_MASK)

#define CCM_PLL_CTRL_SETTING1_MASK               (0x30U)
#define CCM_PLL_CTRL_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING1_SHIFT)) & CCM_PLL_CTRL_SETTING1_MASK)

#define CCM_PLL_CTRL_SETTING2_MASK               (0x300U)
#define CCM_PLL_CTRL_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING2_SHIFT)) & CCM_PLL_CTRL_SETTING2_MASK)

#define CCM_PLL_CTRL_SETTING3_MASK               (0x3000U)
#define CCM_PLL_CTRL_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING3_SHIFT)) & CCM_PLL_CTRL_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL */
#define CCM_PLL_CTRL_COUNT                       (39U)

/*! @name PLL_CTRL_SET - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_SET_SETTING0_MASK           (0x3U)
#define CCM_PLL_CTRL_SET_SETTING0_SHIFT          (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING0(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING0_SHIFT)) & CCM_PLL_CTRL_SET_SETTING0_MASK)

#define CCM_PLL_CTRL_SET_SETTING1_MASK           (0x30U)
#define CCM_PLL_CTRL_SET_SETTING1_SHIFT          (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING1(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING1_SHIFT)) & CCM_PLL_CTRL_SET_SETTING1_MASK)

#define CCM_PLL_CTRL_SET_SETTING2_MASK           (0x300U)
#define CCM_PLL_CTRL_SET_SETTING2_SHIFT          (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING2(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING2_SHIFT)) & CCM_PLL_CTRL_SET_SETTING2_MASK)

#define CCM_PLL_CTRL_SET_SETTING3_MASK           (0x3000U)
#define CCM_PLL_CTRL_SET_SETTING3_SHIFT          (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING3(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING3_SHIFT)) & CCM_PLL_CTRL_SET_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL_SET */
#define CCM_PLL_CTRL_SET_COUNT                   (39U)

/*! @name PLL_CTRL_CLR - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_CLR_SETTING0_MASK           (0x3U)
#define CCM_PLL_CTRL_CLR_SETTING0_SHIFT          (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING0(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING0_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING0_MASK)

#define CCM_PLL_CTRL_CLR_SETTING1_MASK           (0x30U)
#define CCM_PLL_CTRL_CLR_SETTING1_SHIFT          (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING1(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING1_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING1_MASK)

#define CCM_PLL_CTRL_CLR_SETTING2_MASK           (0x300U)
#define CCM_PLL_CTRL_CLR_SETTING2_SHIFT          (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING2(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING2_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING2_MASK)

#define CCM_PLL_CTRL_CLR_SETTING3_MASK           (0x3000U)
#define CCM_PLL_CTRL_CLR_SETTING3_SHIFT          (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING3(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING3_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL_CLR */
#define CCM_PLL_CTRL_CLR_COUNT                   (39U)

/*! @name PLL_CTRL_TOG - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_TOG_SETTING0_MASK           (0x3U)
#define CCM_PLL_CTRL_TOG_SETTING0_SHIFT          (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING0(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING0_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING0_MASK)

#define CCM_PLL_CTRL_TOG_SETTING1_MASK           (0x30U)
#define CCM_PLL_CTRL_TOG_SETTING1_SHIFT          (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING1(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING1_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING1_MASK)

#define CCM_PLL_CTRL_TOG_SETTING2_MASK           (0x300U)
#define CCM_PLL_CTRL_TOG_SETTING2_SHIFT          (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING2(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING2_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING2_MASK)

#define CCM_PLL_CTRL_TOG_SETTING3_MASK           (0x3000U)
#define CCM_PLL_CTRL_TOG_SETTING3_SHIFT          (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING3(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING3_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL_TOG */
#define CCM_PLL_CTRL_TOG_COUNT                   (39U)

/*! @name CCGR - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_SETTING0_MASK                   (0x3U)
#define CCM_CCGR_SETTING0_SHIFT                  (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING0(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING0_SHIFT)) & CCM_CCGR_SETTING0_MASK)

#define CCM_CCGR_SETTING1_MASK                   (0x30U)
#define CCM_CCGR_SETTING1_SHIFT                  (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING1(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING1_SHIFT)) & CCM_CCGR_SETTING1_MASK)

#define CCM_CCGR_SETTING2_MASK                   (0x300U)
#define CCM_CCGR_SETTING2_SHIFT                  (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING2(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING2_SHIFT)) & CCM_CCGR_SETTING2_MASK)

#define CCM_CCGR_SETTING3_MASK                   (0x3000U)
#define CCM_CCGR_SETTING3_SHIFT                  (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING3(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING3_SHIFT)) & CCM_CCGR_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR */
#define CCM_CCGR_COUNT                           (192U)

/*! @name CCGR_SET - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_SET_SETTING0_MASK               (0x3U)
#define CCM_CCGR_SET_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING0_SHIFT)) & CCM_CCGR_SET_SETTING0_MASK)

#define CCM_CCGR_SET_SETTING1_MASK               (0x30U)
#define CCM_CCGR_SET_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING1_SHIFT)) & CCM_CCGR_SET_SETTING1_MASK)

#define CCM_CCGR_SET_SETTING2_MASK               (0x300U)
#define CCM_CCGR_SET_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING2_SHIFT)) & CCM_CCGR_SET_SETTING2_MASK)

#define CCM_CCGR_SET_SETTING3_MASK               (0x3000U)
#define CCM_CCGR_SET_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING3_SHIFT)) & CCM_CCGR_SET_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR_SET */
#define CCM_CCGR_SET_COUNT                       (192U)

/*! @name CCGR_CLR - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_CLR_SETTING0_MASK               (0x3U)
#define CCM_CCGR_CLR_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING0_SHIFT)) & CCM_CCGR_CLR_SETTING0_MASK)

#define CCM_CCGR_CLR_SETTING1_MASK               (0x30U)
#define CCM_CCGR_CLR_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING1_SHIFT)) & CCM_CCGR_CLR_SETTING1_MASK)

#define CCM_CCGR_CLR_SETTING2_MASK               (0x300U)
#define CCM_CCGR_CLR_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING2_SHIFT)) & CCM_CCGR_CLR_SETTING2_MASK)

#define CCM_CCGR_CLR_SETTING3_MASK               (0x3000U)
#define CCM_CCGR_CLR_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING3_SHIFT)) & CCM_CCGR_CLR_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR_CLR */
#define CCM_CCGR_CLR_COUNT                       (192U)

/*! @name CCGR_TOG - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_TOG_SETTING0_MASK               (0x3U)
#define CCM_CCGR_TOG_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING0_SHIFT)) & CCM_CCGR_TOG_SETTING0_MASK)

#define CCM_CCGR_TOG_SETTING1_MASK               (0x30U)
#define CCM_CCGR_TOG_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING1_SHIFT)) & CCM_CCGR_TOG_SETTING1_MASK)

#define CCM_CCGR_TOG_SETTING2_MASK               (0x300U)
#define CCM_CCGR_TOG_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING2_SHIFT)) & CCM_CCGR_TOG_SETTING2_MASK)

#define CCM_CCGR_TOG_SETTING3_MASK               (0x3000U)
#define CCM_CCGR_TOG_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING3_SHIFT)) & CCM_CCGR_TOG_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR_TOG */
#define CCM_CCGR_TOG_COUNT                       (192U)

/*! @name TARGET_ROOT - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_POST_PODF_MASK           (0x3FU)
#define CCM_TARGET_ROOT_POST_PODF_SHIFT          (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_POST_PODF(x)             (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_POST_PODF_MASK)

#define CCM_TARGET_ROOT_PRE_PODF_MASK            (0x70000U)
#define CCM_TARGET_ROOT_PRE_PODF_SHIFT           (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_PRE_PODF(x)              (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_MUX_MASK                 (0x7000000U)
#define CCM_TARGET_ROOT_MUX_SHIFT                (24U)
#define CCM_TARGET_ROOT_MUX(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_MUX_SHIFT)) & CCM_TARGET_ROOT_MUX_MASK)

#define CCM_TARGET_ROOT_ENABLE_MASK              (0x10000000U)
#define CCM_TARGET_ROOT_ENABLE_SHIFT             (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_ENABLE_SHIFT)) & CCM_TARGET_ROOT_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT */
#define CCM_TARGET_ROOT_COUNT                    (142U)

/*! @name TARGET_ROOT_SET - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_SET_POST_PODF_MASK       (0x3FU)
#define CCM_TARGET_ROOT_SET_POST_PODF_SHIFT      (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_SET_POST_PODF(x)         (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_SET_POST_PODF_MASK)

#define CCM_TARGET_ROOT_SET_PRE_PODF_MASK        (0x70000U)
#define CCM_TARGET_ROOT_SET_PRE_PODF_SHIFT       (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_SET_PRE_PODF(x)          (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_SET_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_SET_MUX_MASK             (0x7000000U)
#define CCM_TARGET_ROOT_SET_MUX_SHIFT            (24U)
#define CCM_TARGET_ROOT_SET_MUX(x)               (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_MUX_SHIFT)) & CCM_TARGET_ROOT_SET_MUX_MASK)

#define CCM_TARGET_ROOT_SET_ENABLE_MASK          (0x10000000U)
#define CCM_TARGET_ROOT_SET_ENABLE_SHIFT         (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_SET_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_ENABLE_SHIFT)) & CCM_TARGET_ROOT_SET_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT_SET */
#define CCM_TARGET_ROOT_SET_COUNT                (142U)

/*! @name TARGET_ROOT_CLR - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_CLR_POST_PODF_MASK       (0x3FU)
#define CCM_TARGET_ROOT_CLR_POST_PODF_SHIFT      (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_CLR_POST_PODF(x)         (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_CLR_POST_PODF_MASK)

#define CCM_TARGET_ROOT_CLR_PRE_PODF_MASK        (0x70000U)
#define CCM_TARGET_ROOT_CLR_PRE_PODF_SHIFT       (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_CLR_PRE_PODF(x)          (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_CLR_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_CLR_MUX_MASK             (0x7000000U)
#define CCM_TARGET_ROOT_CLR_MUX_SHIFT            (24U)
#define CCM_TARGET_ROOT_CLR_MUX(x)               (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_MUX_SHIFT)) & CCM_TARGET_ROOT_CLR_MUX_MASK)

#define CCM_TARGET_ROOT_CLR_ENABLE_MASK          (0x10000000U)
#define CCM_TARGET_ROOT_CLR_ENABLE_SHIFT         (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_CLR_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_ENABLE_SHIFT)) & CCM_TARGET_ROOT_CLR_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT_CLR */
#define CCM_TARGET_ROOT_CLR_COUNT                (142U)

/*! @name TARGET_ROOT_TOG - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_TOG_POST_PODF_MASK       (0x3FU)
#define CCM_TARGET_ROOT_TOG_POST_PODF_SHIFT      (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_TOG_POST_PODF(x)         (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_TOG_POST_PODF_MASK)

#define CCM_TARGET_ROOT_TOG_PRE_PODF_MASK        (0x70000U)
#define CCM_TARGET_ROOT_TOG_PRE_PODF_SHIFT       (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_TOG_PRE_PODF(x)          (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_TOG_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_TOG_MUX_MASK             (0x7000000U)
#define CCM_TARGET_ROOT_TOG_MUX_SHIFT            (24U)
#define CCM_TARGET_ROOT_TOG_MUX(x)               (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_MUX_SHIFT)) & CCM_TARGET_ROOT_TOG_MUX_MASK)

#define CCM_TARGET_ROOT_TOG_ENABLE_MASK          (0x10000000U)
#define CCM_TARGET_ROOT_TOG_ENABLE_SHIFT         (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_TOG_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_ENABLE_SHIFT)) & CCM_TARGET_ROOT_TOG_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT_TOG */
#define CCM_TARGET_ROOT_TOG_COUNT                (142U)

/*! @name MISC - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_AUTHEN_FAIL_MASK                (0x1U)
#define CCM_MISC_AUTHEN_FAIL_SHIFT               (0U)
#define CCM_MISC_AUTHEN_FAIL(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_MISC_AUTHEN_FAIL_SHIFT)) & CCM_MISC_AUTHEN_FAIL_MASK)

#define CCM_MISC_TIMEOUT_MASK                    (0x10U)
#define CCM_MISC_TIMEOUT_SHIFT                   (4U)
#define CCM_MISC_TIMEOUT(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_MISC_TIMEOUT_SHIFT)) & CCM_MISC_TIMEOUT_MASK)

#define CCM_MISC_VIOLATE_MASK                    (0x100U)
#define CCM_MISC_VIOLATE_SHIFT                   (8U)
#define CCM_MISC_VIOLATE(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_MISC_VIOLATE_SHIFT)) & CCM_MISC_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC */
#define CCM_MISC_COUNT                           (142U)

/*! @name MISC_ROOT_SET - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_ROOT_SET_AUTHEN_FAIL_MASK       (0x1U)
#define CCM_MISC_ROOT_SET_AUTHEN_FAIL_SHIFT      (0U)
#define CCM_MISC_ROOT_SET_AUTHEN_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_SET_AUTHEN_FAIL_SHIFT)) & CCM_MISC_ROOT_SET_AUTHEN_FAIL_MASK)

#define CCM_MISC_ROOT_SET_TIMEOUT_MASK           (0x10U)
#define CCM_MISC_ROOT_SET_TIMEOUT_SHIFT          (4U)
#define CCM_MISC_ROOT_SET_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_SET_TIMEOUT_SHIFT)) & CCM_MISC_ROOT_SET_TIMEOUT_MASK)

#define CCM_MISC_ROOT_SET_VIOLATE_MASK           (0x100U)
#define CCM_MISC_ROOT_SET_VIOLATE_SHIFT          (8U)
#define CCM_MISC_ROOT_SET_VIOLATE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_SET_VIOLATE_SHIFT)) & CCM_MISC_ROOT_SET_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC_ROOT_SET */
#define CCM_MISC_ROOT_SET_COUNT                  (142U)

/*! @name MISC_ROOT_CLR - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_ROOT_CLR_AUTHEN_FAIL_MASK       (0x1U)
#define CCM_MISC_ROOT_CLR_AUTHEN_FAIL_SHIFT      (0U)
#define CCM_MISC_ROOT_CLR_AUTHEN_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_CLR_AUTHEN_FAIL_SHIFT)) & CCM_MISC_ROOT_CLR_AUTHEN_FAIL_MASK)

#define CCM_MISC_ROOT_CLR_TIMEOUT_MASK           (0x10U)
#define CCM_MISC_ROOT_CLR_TIMEOUT_SHIFT          (4U)
#define CCM_MISC_ROOT_CLR_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_CLR_TIMEOUT_SHIFT)) & CCM_MISC_ROOT_CLR_TIMEOUT_MASK)

#define CCM_MISC_ROOT_CLR_VIOLATE_MASK           (0x100U)
#define CCM_MISC_ROOT_CLR_VIOLATE_SHIFT          (8U)
#define CCM_MISC_ROOT_CLR_VIOLATE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_CLR_VIOLATE_SHIFT)) & CCM_MISC_ROOT_CLR_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC_ROOT_CLR */
#define CCM_MISC_ROOT_CLR_COUNT                  (142U)

/*! @name MISC_ROOT_TOG - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_ROOT_TOG_AUTHEN_FAIL_MASK       (0x1U)
#define CCM_MISC_ROOT_TOG_AUTHEN_FAIL_SHIFT      (0U)
#define CCM_MISC_ROOT_TOG_AUTHEN_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_TOG_AUTHEN_FAIL_SHIFT)) & CCM_MISC_ROOT_TOG_AUTHEN_FAIL_MASK)

#define CCM_MISC_ROOT_TOG_TIMEOUT_MASK           (0x10U)
#define CCM_MISC_ROOT_TOG_TIMEOUT_SHIFT          (4U)
#define CCM_MISC_ROOT_TOG_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_TOG_TIMEOUT_SHIFT)) & CCM_MISC_ROOT_TOG_TIMEOUT_MASK)

#define CCM_MISC_ROOT_TOG_VIOLATE_MASK           (0x100U)
#define CCM_MISC_ROOT_TOG_VIOLATE_SHIFT          (8U)
#define CCM_MISC_ROOT_TOG_VIOLATE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_TOG_VIOLATE_SHIFT)) & CCM_MISC_ROOT_TOG_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC_ROOT_TOG */
#define CCM_MISC_ROOT_TOG_COUNT                  (142U)

/*! @name POST - Post Divider Register */
/*! @{ */

#define CCM_POST_POST_PODF_MASK                  (0x3FU)
#define CCM_POST_POST_PODF_SHIFT                 (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_POST_PODF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_POST_POST_PODF_SHIFT)) & CCM_POST_POST_PODF_MASK)

#define CCM_POST_BUSY1_MASK                      (0x80U)
#define CCM_POST_BUSY1_SHIFT                     (7U)
#define CCM_POST_BUSY1(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_POST_BUSY1_SHIFT)) & CCM_POST_BUSY1_MASK)

#define CCM_POST_SELECT_MASK                     (0x10000000U)
#define CCM_POST_SELECT_SHIFT                    (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_SELECT(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_POST_SELECT_SHIFT)) & CCM_POST_SELECT_MASK)

#define CCM_POST_BUSY2_MASK                      (0x80000000U)
#define CCM_POST_BUSY2_SHIFT                     (31U)
#define CCM_POST_BUSY2(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_POST_BUSY2_SHIFT)) & CCM_POST_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST */
#define CCM_POST_COUNT                           (142U)

/*! @name POST_ROOT_SET - Post Divider Register */
/*! @{ */

#define CCM_POST_ROOT_SET_POST_PODF_MASK         (0x3FU)
#define CCM_POST_ROOT_SET_POST_PODF_SHIFT        (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_ROOT_SET_POST_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_POST_PODF_SHIFT)) & CCM_POST_ROOT_SET_POST_PODF_MASK)

#define CCM_POST_ROOT_SET_BUSY1_MASK             (0x80U)
#define CCM_POST_ROOT_SET_BUSY1_SHIFT            (7U)
#define CCM_POST_ROOT_SET_BUSY1(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_BUSY1_SHIFT)) & CCM_POST_ROOT_SET_BUSY1_MASK)

#define CCM_POST_ROOT_SET_SELECT_MASK            (0x10000000U)
#define CCM_POST_ROOT_SET_SELECT_SHIFT           (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_ROOT_SET_SELECT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_SELECT_SHIFT)) & CCM_POST_ROOT_SET_SELECT_MASK)

#define CCM_POST_ROOT_SET_BUSY2_MASK             (0x80000000U)
#define CCM_POST_ROOT_SET_BUSY2_SHIFT            (31U)
#define CCM_POST_ROOT_SET_BUSY2(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_BUSY2_SHIFT)) & CCM_POST_ROOT_SET_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST_ROOT_SET */
#define CCM_POST_ROOT_SET_COUNT                  (142U)

/*! @name POST_ROOT_CLR - Post Divider Register */
/*! @{ */

#define CCM_POST_ROOT_CLR_POST_PODF_MASK         (0x3FU)
#define CCM_POST_ROOT_CLR_POST_PODF_SHIFT        (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_ROOT_CLR_POST_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_POST_PODF_SHIFT)) & CCM_POST_ROOT_CLR_POST_PODF_MASK)

#define CCM_POST_ROOT_CLR_BUSY1_MASK             (0x80U)
#define CCM_POST_ROOT_CLR_BUSY1_SHIFT            (7U)
#define CCM_POST_ROOT_CLR_BUSY1(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_BUSY1_SHIFT)) & CCM_POST_ROOT_CLR_BUSY1_MASK)

#define CCM_POST_ROOT_CLR_SELECT_MASK            (0x10000000U)
#define CCM_POST_ROOT_CLR_SELECT_SHIFT           (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_ROOT_CLR_SELECT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_SELECT_SHIFT)) & CCM_POST_ROOT_CLR_SELECT_MASK)

#define CCM_POST_ROOT_CLR_BUSY2_MASK             (0x80000000U)
#define CCM_POST_ROOT_CLR_BUSY2_SHIFT            (31U)
#define CCM_POST_ROOT_CLR_BUSY2(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_BUSY2_SHIFT)) & CCM_POST_ROOT_CLR_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST_ROOT_CLR */
#define CCM_POST_ROOT_CLR_COUNT                  (142U)

/*! @name POST_ROOT_TOG - Post Divider Register */
/*! @{ */

#define CCM_POST_ROOT_TOG_POST_PODF_MASK         (0x3FU)
#define CCM_POST_ROOT_TOG_POST_PODF_SHIFT        (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_ROOT_TOG_POST_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_POST_PODF_SHIFT)) & CCM_POST_ROOT_TOG_POST_PODF_MASK)

#define CCM_POST_ROOT_TOG_BUSY1_MASK             (0x80U)
#define CCM_POST_ROOT_TOG_BUSY1_SHIFT            (7U)
#define CCM_POST_ROOT_TOG_BUSY1(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_BUSY1_SHIFT)) & CCM_POST_ROOT_TOG_BUSY1_MASK)

#define CCM_POST_ROOT_TOG_SELECT_MASK            (0x10000000U)
#define CCM_POST_ROOT_TOG_SELECT_SHIFT           (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_ROOT_TOG_SELECT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_SELECT_SHIFT)) & CCM_POST_ROOT_TOG_SELECT_MASK)

#define CCM_POST_ROOT_TOG_BUSY2_MASK             (0x80000000U)
#define CCM_POST_ROOT_TOG_BUSY2_SHIFT            (31U)
#define CCM_POST_ROOT_TOG_BUSY2(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_BUSY2_SHIFT)) & CCM_POST_ROOT_TOG_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST_ROOT_TOG */
#define CCM_POST_ROOT_TOG_COUNT                  (142U)

/*! @name PRE - Pre Divider Register */
/*! @{ */

#define CCM_PRE_PRE_PODF_B_MASK                  (0x7U)
#define CCM_PRE_PRE_PODF_B_SHIFT                 (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_PRE_PODF_B(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_PRE_PRE_PODF_B_SHIFT)) & CCM_PRE_PRE_PODF_B_MASK)

#define CCM_PRE_BUSY0_MASK                       (0x8U)
#define CCM_PRE_BUSY0_SHIFT                      (3U)
#define CCM_PRE_BUSY0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY0_SHIFT)) & CCM_PRE_BUSY0_MASK)

#define CCM_PRE_MUX_B_MASK                       (0x700U)
#define CCM_PRE_MUX_B_SHIFT                      (8U)
#define CCM_PRE_MUX_B(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_MUX_B_SHIFT)) & CCM_PRE_MUX_B_MASK)

#define CCM_PRE_EN_B_MASK                        (0x1000U)
#define CCM_PRE_EN_B_SHIFT                       (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_EN_B(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_PRE_EN_B_SHIFT)) & CCM_PRE_EN_B_MASK)

#define CCM_PRE_BUSY1_MASK                       (0x8000U)
#define CCM_PRE_BUSY1_SHIFT                      (15U)
#define CCM_PRE_BUSY1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY1_SHIFT)) & CCM_PRE_BUSY1_MASK)

#define CCM_PRE_PRE_PODF_A_MASK                  (0x70000U)
#define CCM_PRE_PRE_PODF_A_SHIFT                 (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_PRE_PODF_A(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_PRE_PRE_PODF_A_SHIFT)) & CCM_PRE_PRE_PODF_A_MASK)

#define CCM_PRE_BUSY3_MASK                       (0x80000U)
#define CCM_PRE_BUSY3_SHIFT                      (19U)
#define CCM_PRE_BUSY3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY3_SHIFT)) & CCM_PRE_BUSY3_MASK)

#define CCM_PRE_MUX_A_MASK                       (0x7000000U)
#define CCM_PRE_MUX_A_SHIFT                      (24U)
#define CCM_PRE_MUX_A(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_MUX_A_SHIFT)) & CCM_PRE_MUX_A_MASK)

#define CCM_PRE_EN_A_MASK                        (0x10000000U)
#define CCM_PRE_EN_A_SHIFT                       (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_EN_A(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_PRE_EN_A_SHIFT)) & CCM_PRE_EN_A_MASK)

#define CCM_PRE_BUSY4_MASK                       (0x80000000U)
#define CCM_PRE_BUSY4_SHIFT                      (31U)
#define CCM_PRE_BUSY4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY4_SHIFT)) & CCM_PRE_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE */
#define CCM_PRE_COUNT                            (142U)

/*! @name PRE_ROOT_SET - Pre Divider Register */
/*! @{ */

#define CCM_PRE_ROOT_SET_PRE_PODF_B_MASK         (0x7U)
#define CCM_PRE_ROOT_SET_PRE_PODF_B_SHIFT        (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_SET_PRE_PODF_B(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_PRE_PODF_B_SHIFT)) & CCM_PRE_ROOT_SET_PRE_PODF_B_MASK)

#define CCM_PRE_ROOT_SET_BUSY0_MASK              (0x8U)
#define CCM_PRE_ROOT_SET_BUSY0_SHIFT             (3U)
#define CCM_PRE_ROOT_SET_BUSY0(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY0_SHIFT)) & CCM_PRE_ROOT_SET_BUSY0_MASK)

#define CCM_PRE_ROOT_SET_MUX_B_MASK              (0x700U)
#define CCM_PRE_ROOT_SET_MUX_B_SHIFT             (8U)
#define CCM_PRE_ROOT_SET_MUX_B(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_MUX_B_SHIFT)) & CCM_PRE_ROOT_SET_MUX_B_MASK)

#define CCM_PRE_ROOT_SET_EN_B_MASK               (0x1000U)
#define CCM_PRE_ROOT_SET_EN_B_SHIFT              (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_ROOT_SET_EN_B(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_EN_B_SHIFT)) & CCM_PRE_ROOT_SET_EN_B_MASK)

#define CCM_PRE_ROOT_SET_BUSY1_MASK              (0x8000U)
#define CCM_PRE_ROOT_SET_BUSY1_SHIFT             (15U)
#define CCM_PRE_ROOT_SET_BUSY1(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY1_SHIFT)) & CCM_PRE_ROOT_SET_BUSY1_MASK)

#define CCM_PRE_ROOT_SET_PRE_PODF_A_MASK         (0x70000U)
#define CCM_PRE_ROOT_SET_PRE_PODF_A_SHIFT        (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_SET_PRE_PODF_A(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_PRE_PODF_A_SHIFT)) & CCM_PRE_ROOT_SET_PRE_PODF_A_MASK)

#define CCM_PRE_ROOT_SET_BUSY3_MASK              (0x80000U)
#define CCM_PRE_ROOT_SET_BUSY3_SHIFT             (19U)
#define CCM_PRE_ROOT_SET_BUSY3(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY3_SHIFT)) & CCM_PRE_ROOT_SET_BUSY3_MASK)

#define CCM_PRE_ROOT_SET_MUX_A_MASK              (0x7000000U)
#define CCM_PRE_ROOT_SET_MUX_A_SHIFT             (24U)
#define CCM_PRE_ROOT_SET_MUX_A(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_MUX_A_SHIFT)) & CCM_PRE_ROOT_SET_MUX_A_MASK)

#define CCM_PRE_ROOT_SET_EN_A_MASK               (0x10000000U)
#define CCM_PRE_ROOT_SET_EN_A_SHIFT              (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_ROOT_SET_EN_A(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_EN_A_SHIFT)) & CCM_PRE_ROOT_SET_EN_A_MASK)

#define CCM_PRE_ROOT_SET_BUSY4_MASK              (0x80000000U)
#define CCM_PRE_ROOT_SET_BUSY4_SHIFT             (31U)
#define CCM_PRE_ROOT_SET_BUSY4(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY4_SHIFT)) & CCM_PRE_ROOT_SET_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE_ROOT_SET */
#define CCM_PRE_ROOT_SET_COUNT                   (142U)

/*! @name PRE_ROOT_CLR - Pre Divider Register */
/*! @{ */

#define CCM_PRE_ROOT_CLR_PRE_PODF_B_MASK         (0x7U)
#define CCM_PRE_ROOT_CLR_PRE_PODF_B_SHIFT        (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_CLR_PRE_PODF_B(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_PRE_PODF_B_SHIFT)) & CCM_PRE_ROOT_CLR_PRE_PODF_B_MASK)

#define CCM_PRE_ROOT_CLR_BUSY0_MASK              (0x8U)
#define CCM_PRE_ROOT_CLR_BUSY0_SHIFT             (3U)
#define CCM_PRE_ROOT_CLR_BUSY0(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY0_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY0_MASK)

#define CCM_PRE_ROOT_CLR_MUX_B_MASK              (0x700U)
#define CCM_PRE_ROOT_CLR_MUX_B_SHIFT             (8U)
#define CCM_PRE_ROOT_CLR_MUX_B(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_MUX_B_SHIFT)) & CCM_PRE_ROOT_CLR_MUX_B_MASK)

#define CCM_PRE_ROOT_CLR_EN_B_MASK               (0x1000U)
#define CCM_PRE_ROOT_CLR_EN_B_SHIFT              (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_ROOT_CLR_EN_B(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_EN_B_SHIFT)) & CCM_PRE_ROOT_CLR_EN_B_MASK)

#define CCM_PRE_ROOT_CLR_BUSY1_MASK              (0x8000U)
#define CCM_PRE_ROOT_CLR_BUSY1_SHIFT             (15U)
#define CCM_PRE_ROOT_CLR_BUSY1(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY1_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY1_MASK)

#define CCM_PRE_ROOT_CLR_PRE_PODF_A_MASK         (0x70000U)
#define CCM_PRE_ROOT_CLR_PRE_PODF_A_SHIFT        (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_CLR_PRE_PODF_A(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_PRE_PODF_A_SHIFT)) & CCM_PRE_ROOT_CLR_PRE_PODF_A_MASK)

#define CCM_PRE_ROOT_CLR_BUSY3_MASK              (0x80000U)
#define CCM_PRE_ROOT_CLR_BUSY3_SHIFT             (19U)
#define CCM_PRE_ROOT_CLR_BUSY3(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY3_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY3_MASK)

#define CCM_PRE_ROOT_CLR_MUX_A_MASK              (0x7000000U)
#define CCM_PRE_ROOT_CLR_MUX_A_SHIFT             (24U)
#define CCM_PRE_ROOT_CLR_MUX_A(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_MUX_A_SHIFT)) & CCM_PRE_ROOT_CLR_MUX_A_MASK)

#define CCM_PRE_ROOT_CLR_EN_A_MASK               (0x10000000U)
#define CCM_PRE_ROOT_CLR_EN_A_SHIFT              (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_ROOT_CLR_EN_A(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_EN_A_SHIFT)) & CCM_PRE_ROOT_CLR_EN_A_MASK)

#define CCM_PRE_ROOT_CLR_BUSY4_MASK              (0x80000000U)
#define CCM_PRE_ROOT_CLR_BUSY4_SHIFT             (31U)
#define CCM_PRE_ROOT_CLR_BUSY4(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY4_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE_ROOT_CLR */
#define CCM_PRE_ROOT_CLR_COUNT                   (142U)

/*! @name PRE_ROOT_TOG - Pre Divider Register */
/*! @{ */

#define CCM_PRE_ROOT_TOG_PRE_PODF_B_MASK         (0x7U)
#define CCM_PRE_ROOT_TOG_PRE_PODF_B_SHIFT        (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_TOG_PRE_PODF_B(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_PRE_PODF_B_SHIFT)) & CCM_PRE_ROOT_TOG_PRE_PODF_B_MASK)

#define CCM_PRE_ROOT_TOG_BUSY0_MASK              (0x8U)
#define CCM_PRE_ROOT_TOG_BUSY0_SHIFT             (3U)
#define CCM_PRE_ROOT_TOG_BUSY0(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY0_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY0_MASK)

#define CCM_PRE_ROOT_TOG_MUX_B_MASK              (0x700U)
#define CCM_PRE_ROOT_TOG_MUX_B_SHIFT             (8U)
#define CCM_PRE_ROOT_TOG_MUX_B(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_MUX_B_SHIFT)) & CCM_PRE_ROOT_TOG_MUX_B_MASK)

#define CCM_PRE_ROOT_TOG_EN_B_MASK               (0x1000U)
#define CCM_PRE_ROOT_TOG_EN_B_SHIFT              (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_ROOT_TOG_EN_B(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_EN_B_SHIFT)) & CCM_PRE_ROOT_TOG_EN_B_MASK)

#define CCM_PRE_ROOT_TOG_BUSY1_MASK              (0x8000U)
#define CCM_PRE_ROOT_TOG_BUSY1_SHIFT             (15U)
#define CCM_PRE_ROOT_TOG_BUSY1(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY1_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY1_MASK)

#define CCM_PRE_ROOT_TOG_PRE_PODF_A_MASK         (0x70000U)
#define CCM_PRE_ROOT_TOG_PRE_PODF_A_SHIFT        (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_TOG_PRE_PODF_A(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_PRE_PODF_A_SHIFT)) & CCM_PRE_ROOT_TOG_PRE_PODF_A_MASK)

#define CCM_PRE_ROOT_TOG_BUSY3_MASK              (0x80000U)
#define CCM_PRE_ROOT_TOG_BUSY3_SHIFT             (19U)
#define CCM_PRE_ROOT_TOG_BUSY3(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY3_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY3_MASK)

#define CCM_PRE_ROOT_TOG_MUX_A_MASK              (0x7000000U)
#define CCM_PRE_ROOT_TOG_MUX_A_SHIFT             (24U)
#define CCM_PRE_ROOT_TOG_MUX_A(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_MUX_A_SHIFT)) & CCM_PRE_ROOT_TOG_MUX_A_MASK)

#define CCM_PRE_ROOT_TOG_EN_A_MASK               (0x10000000U)
#define CCM_PRE_ROOT_TOG_EN_A_SHIFT              (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_ROOT_TOG_EN_A(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_EN_A_SHIFT)) & CCM_PRE_ROOT_TOG_EN_A_MASK)

#define CCM_PRE_ROOT_TOG_BUSY4_MASK              (0x80000000U)
#define CCM_PRE_ROOT_TOG_BUSY4_SHIFT             (31U)
#define CCM_PRE_ROOT_TOG_BUSY4(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY4_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE_ROOT_TOG */
#define CCM_PRE_ROOT_TOG_COUNT                   (142U)

/*! @name ACCESS_CTRL - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_DOMAIN0_INFO_MASK        (0xFU)
#define CCM_ACCESS_CTRL_DOMAIN0_INFO_SHIFT       (0U)
#define CCM_ACCESS_CTRL_DOMAIN0_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_DOMAIN1_INFO_MASK        (0xF0U)
#define CCM_ACCESS_CTRL_DOMAIN1_INFO_SHIFT       (4U)
#define CCM_ACCESS_CTRL_DOMAIN1_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_DOMAIN2_INFO_MASK        (0xF00U)
#define CCM_ACCESS_CTRL_DOMAIN2_INFO_SHIFT       (8U)
#define CCM_ACCESS_CTRL_DOMAIN2_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_DOMAIN3_INFO_MASK        (0xF000U)
#define CCM_ACCESS_CTRL_DOMAIN3_INFO_SHIFT       (12U)
#define CCM_ACCESS_CTRL_DOMAIN3_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_OWNER_ID_MASK            (0x30000U)
#define CCM_ACCESS_CTRL_OWNER_ID_SHIFT           (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_OWNER_ID(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_MUTEX_MASK               (0x100000U)
#define CCM_ACCESS_CTRL_MUTEX_SHIFT              (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_MUTEX(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_MUTEX_MASK)

#define CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_MASK   (0x1000000U)
#define CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_SHIFT  (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN0_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_MASK   (0x2000000U)
#define CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_SHIFT  (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN1_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_MASK   (0x4000000U)
#define CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_SHIFT  (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN2_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_MASK   (0x8000000U)
#define CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_SHIFT  (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN3_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_SEMA_EN_MASK             (0x10000000U)
#define CCM_ACCESS_CTRL_SEMA_EN_SHIFT            (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_SEMA_EN(x)               (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_LOCK_MASK                (0x80000000U)
#define CCM_ACCESS_CTRL_LOCK_SHIFT               (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_LOCK_SHIFT)) & CCM_ACCESS_CTRL_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL */
#define CCM_ACCESS_CTRL_COUNT                    (142U)

/*! @name ACCESS_CTRL_ROOT_SET - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_MASK (0xFU)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_SHIFT (0U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_MASK (0xF0U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_SHIFT (4U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_MASK (0xF00U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_SHIFT (8U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_MASK (0xF000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_SHIFT (12U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_MASK   (0x30000U)
#define CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_SHIFT  (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_MUTEX_MASK      (0x100000U)
#define CCM_ACCESS_CTRL_ROOT_SET_MUTEX_SHIFT     (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_ROOT_SET_MUTEX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_MUTEX_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_MASK (0x1000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_SHIFT (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_MASK (0x2000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_SHIFT (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_MASK (0x4000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_SHIFT (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_MASK (0x8000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_SHIFT (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_MASK    (0x10000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_SHIFT   (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_LOCK_MASK       (0x80000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_LOCK_SHIFT      (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_ROOT_SET_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_LOCK_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL_ROOT_SET */
#define CCM_ACCESS_CTRL_ROOT_SET_COUNT           (142U)

/*! @name ACCESS_CTRL_ROOT_CLR - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_MASK (0xFU)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_SHIFT (0U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_MASK (0xF0U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_SHIFT (4U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_MASK (0xF00U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_SHIFT (8U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_MASK (0xF000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_SHIFT (12U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_MASK   (0x30000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_SHIFT  (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_MASK      (0x100000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_SHIFT     (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_MUTEX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_MASK (0x1000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_SHIFT (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_MASK (0x2000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_SHIFT (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_MASK (0x4000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_SHIFT (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_MASK (0x8000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_SHIFT (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_MASK    (0x10000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_SHIFT   (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_LOCK_MASK       (0x80000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_LOCK_SHIFT      (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_LOCK_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL_ROOT_CLR */
#define CCM_ACCESS_CTRL_ROOT_CLR_COUNT           (142U)

/*! @name ACCESS_CTRL_ROOT_TOG - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_MASK (0xFU)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_SHIFT (0U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_MASK (0xF0U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_SHIFT (4U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_MASK (0xF00U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_SHIFT (8U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_MASK (0xF000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_SHIFT (12U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_MASK   (0x30000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_SHIFT  (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_MASK      (0x100000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_SHIFT     (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_MUTEX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_MASK (0x1000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_SHIFT (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_MASK (0x2000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_SHIFT (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_MASK (0x4000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_SHIFT (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_MASK (0x8000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_SHIFT (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_MASK    (0x10000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_SHIFT   (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_LOCK_MASK       (0x80000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_LOCK_SHIFT      (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_LOCK_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL_ROOT_TOG */
#define CCM_ACCESS_CTRL_ROOT_TOG_COUNT           (142U)


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/* CCM - Peripheral instance base addresses */
/** Peripheral CCM base address */
#define CCM_BASE                                 (0x30380000u)
/** Peripheral CCM base pointer */
#define CCM                                      ((CCM_Type *)CCM_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM }
/** Interrupt vectors for the CCM peripheral type */
#define CCM_IRQS                                 { CCM_IRQ1_IRQn, CCM_IRQ2_IRQn }

/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- CCM_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_ANALOG_Peripheral_Access_Layer CCM_ANALOG Peripheral Access Layer
 * @{
 */

/** CCM_ANALOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t AUDIO_PLL1_GEN_CTRL;               /**< AUDIO PLL1 General Function Control Register, offset: 0x0 */
  __IO uint32_t AUDIO_PLL1_FDIV_CTL0;              /**< AUDIO PLL1 Divide and Fraction Data Control 0 Register, offset: 0x4 */
  __IO uint32_t AUDIO_PLL1_FDIV_CTL1;              /**< AUDIO PLL1 Divide and Fraction Data Control 1 Register, offset: 0x8 */
  __IO uint32_t AUDIO_PLL1_SSCG_CTRL;              /**< AUDIO PLL1 PLL SSCG Control Register, offset: 0xC */
  __IO uint32_t AUDIO_PLL1_MNIT_CTRL;              /**< AUDIO PLL1 PLL Monitoring Control Register, offset: 0x10 */
  __IO uint32_t AUDIO_PLL2_GEN_CTRL;               /**< AUDIO PLL2 General Function Control Register, offset: 0x14 */
  __IO uint32_t AUDIO_PLL2_FDIV_CTL0;              /**< AUDIO PLL2 Divide and Fraction Data Control 0 Register, offset: 0x18 */
  __IO uint32_t AUDIO_PLL2_FDIV_CTL1;              /**< AUDIO PLL2 Divide and Fraction Data Control 1 Register, offset: 0x1C */
  __IO uint32_t AUDIO_PLL2_SSCG_CTRL;              /**< AUDIO PLL2 PLL SSCG Control Register, offset: 0x20 */
  __IO uint32_t AUDIO_PLL2_MNIT_CTRL;              /**< AUDIO PLL2 PLL Monitoring Control Register, offset: 0x24 */
  __IO uint32_t VIDEO_PLL1_GEN_CTRL;               /**< VIDEO PLL1 General Function Control Register, offset: 0x28 */
  __IO uint32_t VIDEO_PLL1_FDIV_CTL0;              /**< VIDEO PLL1 Divide and Fraction Data Control 0 Register, offset: 0x2C */
  __IO uint32_t VIDEO_PLL1_FDIV_CTL1;              /**< VIDEO PLL1 Divide and Fraction Data Control 1 Register, offset: 0x30 */
  __IO uint32_t VIDEO_PLL1_SSCG_CTRL;              /**< VIDEO PLL1 PLL SSCG Control Register, offset: 0x34 */
  __IO uint32_t VIDEO_PLL1_MNIT_CTRL;              /**< VIDEO PLL1 PLL Monitoring Control Register, offset: 0x38 */
       uint8_t RESERVED_0[20];
  __IO uint32_t DRAM_PLL_GEN_CTRL;                 /**< DRAM PLL General Function Control Register, offset: 0x50 */
  __IO uint32_t DRAM_PLL_FDIV_CTL0;                /**< DRAM PLL Divide and Fraction Data Control 0 Register, offset: 0x54 */
  __IO uint32_t DRAM_PLL_FDIV_CTL1;                /**< DRAM PLL Divide and Fraction Data Control 1 Register, offset: 0x58 */
  __IO uint32_t DRAM_PLL_SSCG_CTRL;                /**< DRAM PLL PLL SSCG Control Register, offset: 0x5C */
  __IO uint32_t DRAM_PLL_MNIT_CTRL;                /**< DRAM PLL PLL Monitoring Control Register, offset: 0x60 */
  __IO uint32_t GPU_PLL_GEN_CTRL;                  /**< GPU PLL General Function Control Register, offset: 0x64 */
  __IO uint32_t GPU_PLL_FDIV_CTL0;                 /**< GPU PLL Divide and Fraction Data Control 0 Register, offset: 0x68 */
  __IO uint32_t GPU_PLL_LOCKD_CTRL;                /**< PLL Lock Detector Control Register, offset: 0x6C */
  __IO uint32_t GPU_PLL_MNIT_CTRL;                 /**< PLL Monitoring Control Register, offset: 0x70 */
  __IO uint32_t VPU_PLL_GEN_CTRL;                  /**< VPU PLL General Function Control Register, offset: 0x74 */
  __IO uint32_t VPU_PLL_FDIV_CTL0;                 /**< VPU PLL Divide and Fraction Data Control 0 Register, offset: 0x78 */
  __IO uint32_t VPU_PLL_LOCKD_CTRL;                /**< PLL Lock Detector Control Register, offset: 0x7C */
  __IO uint32_t VPU_PLL_MNIT_CTRL;                 /**< PLL Monitoring Control Register, offset: 0x80 */
  __IO uint32_t ARM_PLL_GEN_CTRL;                  /**< ARM PLL General Function Control Register, offset: 0x84 */
  __IO uint32_t ARM_PLL_FDIV_CTL0;                 /**< ARM PLL Divide and Fraction Data Control 0 Register, offset: 0x88 */
  __IO uint32_t ARM_PLL_LOCKD_CTRL;                /**< PLL Lock Detector Control Register, offset: 0x8C */
  __IO uint32_t ARM_PLL_MNIT_CTRL;                 /**< PLL Monitoring Control Register, offset: 0x90 */
  __IO uint32_t SYS_PLL1_GEN_CTRL;                 /**< SYS PLL1 General Function Control Register, offset: 0x94 */
  __IO uint32_t SYS_PLL1_FDIV_CTL0;                /**< SYS PLL1 Divide and Fraction Data Control 0 Register, offset: 0x98 */
  __IO uint32_t SYS_PLL1_LOCKD_CTRL;               /**< PLL Lock Detector Control Register, offset: 0x9C */
       uint8_t RESERVED_1[96];
  __IO uint32_t SYS_PLL1_MNIT_CTRL;                /**< PLL Monitoring Control Register, offset: 0x100 */
  __IO uint32_t SYS_PLL2_GEN_CTRL;                 /**< SYS PLL2 General Function Control Register, offset: 0x104 */
  __IO uint32_t SYS_PLL2_FDIV_CTL0;                /**< SYS PLL2 Divide and Fraction Data Control 0 Register, offset: 0x108 */
  __IO uint32_t SYS_PLL2_LOCKD_CTRL;               /**< PLL Lock Detector Control Register, offset: 0x10C */
  __IO uint32_t SYS_PLL2_MNIT_CTRL;                /**< PLL Monitoring Control Register, offset: 0x110 */
  __IO uint32_t SYS_PLL3_GEN_CTRL;                 /**< SYS PLL3 General Function Control Register, offset: 0x114 */
  __IO uint32_t SYS_PLL3_FDIV_CTL0;                /**< SYS PLL3 Divide and Fraction Data Control 0 Register, offset: 0x118 */
  __IO uint32_t SYS_PLL3_LOCKD_CTRL;               /**< PLL Lock Detector Control Register, offset: 0x11C */
  __IO uint32_t SYS_PLL3_MNIT_CTRL;                /**< PLL Monitoring Control Register, offset: 0x120 */
  __IO uint32_t OSC_MISC_CFG;                      /**< Osc Misc Configuration Register, offset: 0x124 */
  __IO uint32_t ANAMIX_PLL_MNIT_CTL;               /**< PLL Clock Output for Test Enable and Select Register, offset: 0x128 */
       uint8_t RESERVED_2[1748];
  __I  uint32_t DIGPROG;                           /**< DIGPROG Register, offset: 0x800 */
} CCM_ANALOG_Type;

/* ----------------------------------------------------------------------------
   -- CCM_ANALOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_ANALOG_Register_Masks CCM_ANALOG Register Masks
 * @{
 */

/*! @name AUDIO_PLL1_GEN_CTRL - AUDIO PLL1 General Function Control Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x1000U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (12U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_MASK (0x2000U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_SHIFT (13U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (16U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name AUDIO_PLL1_FDIV_CTL0 - AUDIO PLL1 Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name AUDIO_PLL1_FDIV_CTL1 - AUDIO PLL1 Divide and Fraction Data Control 1 Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM_MASK (0xFFFFU)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM_SHIFT (0U)
#define CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM_MASK)
/*! @} */

/*! @name AUDIO_PLL1_SSCG_CTRL - AUDIO PLL1 PLL SSCG Control Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SEL_PF_MASK (0x3U)
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SEL_PF_SHIFT (0U)
/*! SEL_PF
 *  0b00..Down spread
 *  0b01..Up spread
 *  0b1x..Center spread
 */
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SEL_PF(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SEL_PF_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SEL_PF_MASK)

#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_MASK (0x3F0U)
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MRAT_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_MASK (0xFF000U)
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT (12U)
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SSCG_EN_MASK (0x80000000U)
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SSCG_EN_SHIFT (31U)
/*! SSCG_EN
 *  0b1..Enable Spread Spectrum Mode
 *  0b0..Disable Spread Spectrum Mode
 */
#define CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SSCG_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SSCG_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_SSCG_CTRL_SSCG_EN_MASK)
/*! @} */

/*! @name AUDIO_PLL1_MNIT_CTRL - AUDIO PLL1 PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_ICP_MASK (0x7U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_ICP_SHIFT (0U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_ICP(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_EN_MASK (0x8U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_EN_SHIFT (3U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_EXTAFC_MASK (0x1F0U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_EXTAFC_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_EXTAFC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FEED_EN_MASK (0x4000U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FEED_EN_SHIFT (14U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FSEL_MASK (0x8000U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FSEL_SHIFT (15U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FSEL(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFCINIT_SEL_MASK (0x20000U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFCINIT_SEL_SHIFT (17U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x40000U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (18U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_MASK (0x80000U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_SHIFT (19U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_SEL_MASK (0x100000U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_SEL_SHIFT (20U)
#define CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL1_MNIT_CTRL_AFC_SEL_MASK)
/*! @} */

/*! @name AUDIO_PLL2_GEN_CTRL - AUDIO PLL2 General Function Control Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x1000U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (12U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_MASK (0x2000U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_SHIFT (13U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (16U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name AUDIO_PLL2_FDIV_CTL0 - AUDIO PLL2 Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name AUDIO_PLL2_FDIV_CTL1 - AUDIO PLL2 Divide and Fraction Data Control 1 Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL1_PLL_DSM_MASK (0xFFFFU)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL1_PLL_DSM_SHIFT (0U)
#define CCM_ANALOG_AUDIO_PLL2_FDIV_CTL1_PLL_DSM(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_FDIV_CTL1_PLL_DSM_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_FDIV_CTL1_PLL_DSM_MASK)
/*! @} */

/*! @name AUDIO_PLL2_SSCG_CTRL - AUDIO PLL2 PLL SSCG Control Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SEL_PF_MASK (0x3U)
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SEL_PF_SHIFT (0U)
/*! SEL_PF
 *  0b00..Down spread
 *  0b01..Up spread
 *  0b1x..Center spread
 */
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SEL_PF(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SEL_PF_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SEL_PF_MASK)

#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MRAT_CTL_MASK (0x3F0U)
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MRAT_CTL_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MRAT_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MRAT_CTL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MRAT_CTL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MFREQ_CTL_MASK (0xFF000U)
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT (12U)
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MFREQ_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_PLL_MFREQ_CTL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SSCG_EN_MASK (0x80000000U)
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SSCG_EN_SHIFT (31U)
/*! SSCG_EN
 *  0b1..Enable Spread Spectrum Mode
 *  0b0..Disable Spread Spectrum Mode
 */
#define CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SSCG_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SSCG_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_SSCG_CTRL_SSCG_EN_MASK)
/*! @} */

/*! @name AUDIO_PLL2_MNIT_CTRL - AUDIO PLL2 PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_ICP_MASK (0x7U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_ICP_SHIFT (0U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_ICP(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_EN_MASK (0x8U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_EN_SHIFT (3U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_EXTAFC_MASK (0x1F0U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_EXTAFC_SHIFT (4U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_EXTAFC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FEED_EN_MASK (0x4000U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FEED_EN_SHIFT (14U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FSEL_MASK (0x8000U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FSEL_SHIFT (15U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FSEL(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFCINIT_SEL_MASK (0x20000U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFCINIT_SEL_SHIFT (17U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x40000U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (18U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_MASK (0x80000U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_SHIFT (19U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_SEL_MASK (0x100000U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_SEL_SHIFT (20U)
#define CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_AUDIO_PLL2_MNIT_CTRL_AFC_SEL_MASK)
/*! @} */

/*! @name VIDEO_PLL1_GEN_CTRL - VIDEO PLL1 General Function Control Register */
/*! @{ */

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x1000U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (12U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_MASK (0x2000U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_SHIFT (13U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (16U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name VIDEO_PLL1_FDIV_CTL0 - VIDEO PLL1 Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name VIDEO_PLL1_FDIV_CTL1 - VIDEO PLL1 Divide and Fraction Data Control 1 Register */
/*! @{ */

#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL1_PLL_DSM_MASK (0xFFFFU)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL1_PLL_DSM_SHIFT (0U)
#define CCM_ANALOG_VIDEO_PLL1_FDIV_CTL1_PLL_DSM(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_FDIV_CTL1_PLL_DSM_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_FDIV_CTL1_PLL_DSM_MASK)
/*! @} */

/*! @name VIDEO_PLL1_SSCG_CTRL - VIDEO PLL1 PLL SSCG Control Register */
/*! @{ */

#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SEL_PF_MASK (0x3U)
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SEL_PF_SHIFT (0U)
/*! SEL_PF
 *  0b00..Down spread
 *  0b01..Up spread
 *  0b1x..Center spread
 */
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SEL_PF(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SEL_PF_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SEL_PF_MASK)

#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_MASK (0x3F0U)
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_SHIFT (4U)
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MRAT_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MRAT_CTL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_MASK (0xFF000U)
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT (12U)
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_PLL_MFREQ_CTL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SSCG_EN_MASK (0x80000000U)
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SSCG_EN_SHIFT (31U)
/*! SSCG_EN
 *  0b1..Enable Spread Spectrum Mode
 *  0b0..Disable Spread Spectrum Mode
 */
#define CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SSCG_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SSCG_EN_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_SSCG_CTRL_SSCG_EN_MASK)
/*! @} */

/*! @name VIDEO_PLL1_MNIT_CTRL - VIDEO PLL1 PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_ICP_MASK (0x7U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_ICP_SHIFT (0U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_ICP(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_EN_MASK (0x8U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_EN_SHIFT (3U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_EXTAFC_MASK (0x1F0U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_EXTAFC_SHIFT (4U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_EXTAFC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FEED_EN_MASK (0x4000U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FEED_EN_SHIFT (14U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FSEL_MASK (0x8000U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FSEL_SHIFT (15U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FSEL(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFCINIT_SEL_MASK (0x20000U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFCINIT_SEL_SHIFT (17U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x40000U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (18U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_MASK (0x80000U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_SHIFT (19U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_SEL_MASK (0x100000U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_SEL_SHIFT (20U)
#define CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_VIDEO_PLL1_MNIT_CTRL_AFC_SEL_MASK)
/*! @} */

/*! @name DRAM_PLL_GEN_CTRL - DRAM PLL General Function Control Register */
/*! @{ */

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x1000U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (12U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_MASK (0x2000U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_SHIFT (13U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (16U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_DRAM_PLL_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name DRAM_PLL_FDIV_CTL0 - DRAM PLL Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_DRAM_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name DRAM_PLL_FDIV_CTL1 - DRAM PLL Divide and Fraction Data Control 1 Register */
/*! @{ */

#define CCM_ANALOG_DRAM_PLL_FDIV_CTL1_PLL_DSM_MASK (0xFFFFU)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL1_PLL_DSM_SHIFT (0U)
#define CCM_ANALOG_DRAM_PLL_FDIV_CTL1_PLL_DSM(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_FDIV_CTL1_PLL_DSM_SHIFT)) & CCM_ANALOG_DRAM_PLL_FDIV_CTL1_PLL_DSM_MASK)
/*! @} */

/*! @name DRAM_PLL_SSCG_CTRL - DRAM PLL PLL SSCG Control Register */
/*! @{ */

#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SEL_PF_MASK (0x3U)
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SEL_PF_SHIFT (0U)
/*! SEL_PF
 *  0b00..Down spread
 *  0b01..Up spread
 *  0b1x..Center spread
 */
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SEL_PF(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SEL_PF_SHIFT)) & CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SEL_PF_MASK)

#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MRAT_CTL_MASK (0x3F0U)
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MRAT_CTL_SHIFT (4U)
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MRAT_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MRAT_CTL_SHIFT)) & CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MRAT_CTL_MASK)

#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MFREQ_CTL_MASK (0xFF000U)
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT (12U)
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MFREQ_CTL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MFREQ_CTL_SHIFT)) & CCM_ANALOG_DRAM_PLL_SSCG_CTRL_PLL_MFREQ_CTL_MASK)

#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SSCG_EN_MASK (0x80000000U)
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SSCG_EN_SHIFT (31U)
/*! SSCG_EN
 *  0b1..Enable Spread Spectrum Mode
 *  0b0..Disable Spread Spectrum Mode
 */
#define CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SSCG_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SSCG_EN_SHIFT)) & CCM_ANALOG_DRAM_PLL_SSCG_CTRL_SSCG_EN_MASK)
/*! @} */

/*! @name DRAM_PLL_MNIT_CTRL - DRAM PLL PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_ICP_MASK   (0x7U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_ICP_SHIFT  (0U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_ICP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_EN_MASK (0x8U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_EN_SHIFT (3U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_EXTAFC_MASK (0x1F0U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_EXTAFC_SHIFT (4U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_EXTAFC(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FEED_EN_MASK (0x4000U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FEED_EN_SHIFT (14U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FSEL_MASK  (0x8000U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FSEL_SHIFT (15U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FSEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFCINIT_SEL_MASK (0x20000U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT (17U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x40000U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (18U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_MASK (0x80000U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT (19U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_SEL_MASK (0x100000U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_SEL_SHIFT (20U)
#define CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_DRAM_PLL_MNIT_CTRL_AFC_SEL_MASK)
/*! @} */

/*! @name GPU_PLL_GEN_CTRL - GPU PLL General Function Control Register */
/*! @{ */

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x400U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (10U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_MASK (0x800U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_SHIFT (11U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000000U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (28U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SEL_MASK (0x20000000U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SEL_SHIFT (29U)
/*! PLL_LOCK_SEL
 *  0b0..Using PLL maximum lock time
 *  0b1..Using PLL output lock
 */
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SEL_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SEL_MASK)

#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_GPU_PLL_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name GPU_PLL_FDIV_CTL0 - GPU PLL Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_GPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name GPU_PLL_LOCKD_CTRL - PLL Lock Detector Control Register */
/*! @{ */

#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_IN_MASK (0x3U)
#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_IN_SHIFT (0U)
#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_IN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_IN_SHIFT)) & CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_IN_MASK)

#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_MASK (0xCU)
#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_SHIFT (2U)
#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_OUT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_SHIFT)) & CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_MASK)

#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_MASK (0x30U)
#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_SHIFT (4U)
#define CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_DLY(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_SHIFT)) & CCM_ANALOG_GPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_MASK)
/*! @} */

/*! @name GPU_PLL_MNIT_CTRL - PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_ICP_MASK    (0x3U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_ICP_SHIFT   (0U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_ICP(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_EN_MASK (0x4U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_EN_SHIFT (2U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_EXTAFC_MASK (0xF8U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_EXTAFC_SHIFT (3U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_EXTAFC(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FEED_EN_MASK (0x2000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FEED_EN_SHIFT (13U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FEED_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FSEL_MASK   (0x4000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FSEL_SHIFT  (14U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FSEL(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFCINIT_SEL_MASK (0x10000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT (16U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x20000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (17U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_MASK (0x40000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT (18U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_SEL_MASK (0x80000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_SEL_SHIFT (19U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_SEL(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_AFC_SEL_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FOUT_MASK_MASK (0x100000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FOUT_MASK_SHIFT (20U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_FOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_FOUT_MASK_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_FOUT_MASK_MASK)

#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_LRD_EN_MASK (0x200000U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_LRD_EN_SHIFT (21U)
#define CCM_ANALOG_GPU_PLL_MNIT_CTRL_LRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_GPU_PLL_MNIT_CTRL_LRD_EN_SHIFT)) & CCM_ANALOG_GPU_PLL_MNIT_CTRL_LRD_EN_MASK)
/*! @} */

/*! @name VPU_PLL_GEN_CTRL - VPU PLL General Function Control Register */
/*! @{ */

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x400U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (10U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_MASK (0x800U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_SHIFT (11U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000000U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (28U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SEL_MASK (0x20000000U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SEL_SHIFT (29U)
/*! PLL_LOCK_SEL
 *  0b0..Using PLL maximum lock time
 *  0b1..Using PLL output lock
 */
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SEL_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SEL_MASK)

#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_VPU_PLL_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name VPU_PLL_FDIV_CTL0 - VPU PLL Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_VPU_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name VPU_PLL_LOCKD_CTRL - PLL Lock Detector Control Register */
/*! @{ */

#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_IN_MASK (0x3U)
#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_IN_SHIFT (0U)
#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_IN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_IN_SHIFT)) & CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_IN_MASK)

#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_MASK (0xCU)
#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_SHIFT (2U)
#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_OUT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_SHIFT)) & CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_OUT_MASK)

#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_MASK (0x30U)
#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_SHIFT (4U)
#define CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_DLY(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_SHIFT)) & CCM_ANALOG_VPU_PLL_LOCKD_CTRL_LOCK_CON_DLY_MASK)
/*! @} */

/*! @name VPU_PLL_MNIT_CTRL - PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_ICP_MASK    (0x3U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_ICP_SHIFT   (0U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_ICP(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_EN_MASK (0x4U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_EN_SHIFT (2U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_EXTAFC_MASK (0xF8U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_EXTAFC_SHIFT (3U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_EXTAFC(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FEED_EN_MASK (0x2000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FEED_EN_SHIFT (13U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FEED_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FSEL_MASK   (0x4000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FSEL_SHIFT  (14U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FSEL(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFCINIT_SEL_MASK (0x10000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT (16U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x20000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (17U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_MASK (0x40000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT (18U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_SEL_MASK (0x80000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_SEL_SHIFT (19U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_SEL(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_AFC_SEL_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FOUT_MASK_MASK (0x100000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FOUT_MASK_SHIFT (20U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_FOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_FOUT_MASK_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_FOUT_MASK_MASK)

#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_LRD_EN_MASK (0x200000U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_LRD_EN_SHIFT (21U)
#define CCM_ANALOG_VPU_PLL_MNIT_CTRL_LRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_VPU_PLL_MNIT_CTRL_LRD_EN_SHIFT)) & CCM_ANALOG_VPU_PLL_MNIT_CTRL_LRD_EN_MASK)
/*! @} */

/*! @name ARM_PLL_GEN_CTRL - ARM PLL General Function Control Register */
/*! @{ */

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x400U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (10U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_MASK (0x800U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_SHIFT (11U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000000U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (28U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SEL_MASK (0x20000000U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SEL_SHIFT (29U)
/*! PLL_LOCK_SEL
 *  0b0..Using PLL maximum lock time
 *  0b1..Using PLL output lock
 */
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SEL_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SEL_MASK)

#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_ARM_PLL_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name ARM_PLL_FDIV_CTL0 - ARM PLL Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_ARM_PLL_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name ARM_PLL_LOCKD_CTRL - PLL Lock Detector Control Register */
/*! @{ */

#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_IN_MASK (0x3U)
#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_IN_SHIFT (0U)
#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_IN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_IN_SHIFT)) & CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_IN_MASK)

#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_OUT_MASK (0xCU)
#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_OUT_SHIFT (2U)
#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_OUT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_OUT_SHIFT)) & CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_OUT_MASK)

#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_DLY_MASK (0x30U)
#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_DLY_SHIFT (4U)
#define CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_DLY(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_DLY_SHIFT)) & CCM_ANALOG_ARM_PLL_LOCKD_CTRL_LOCK_CON_DLY_MASK)
/*! @} */

/*! @name ARM_PLL_MNIT_CTRL - PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_ICP_MASK    (0x3U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_ICP_SHIFT   (0U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_ICP(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_EN_MASK (0x4U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_EN_SHIFT (2U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_EXTAFC_MASK (0xF8U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_EXTAFC_SHIFT (3U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_EXTAFC(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FEED_EN_MASK (0x2000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FEED_EN_SHIFT (13U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FEED_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FSEL_MASK   (0x4000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FSEL_SHIFT  (14U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FSEL(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFCINIT_SEL_MASK (0x10000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT (16U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x20000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (17U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_MASK (0x40000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT (18U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_SEL_MASK (0x80000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_SEL_SHIFT (19U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_SEL(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_AFC_SEL_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FOUT_MASK_MASK (0x100000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FOUT_MASK_SHIFT (20U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_FOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_FOUT_MASK_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_FOUT_MASK_MASK)

#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_LRD_EN_MASK (0x200000U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_LRD_EN_SHIFT (21U)
#define CCM_ANALOG_ARM_PLL_MNIT_CTRL_LRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ARM_PLL_MNIT_CTRL_LRD_EN_SHIFT)) & CCM_ANALOG_ARM_PLL_MNIT_CTRL_LRD_EN_MASK)
/*! @} */

/*! @name SYS_PLL1_GEN_CTRL - SYS PLL1 General Function Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x400U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (10U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_MASK (0x800U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_SHIFT (11U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_MASK (0x1000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_SHIFT (12U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_MASK (0x2000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_SHIFT (13U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV2_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_MASK (0x4000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_SHIFT (14U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_MASK (0x8000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_SHIFT (15U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV3_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_MASK (0x10000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_SHIFT (16U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_MASK (0x20000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_SHIFT (17U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV4_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_MASK (0x40000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_SHIFT (18U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_MASK (0x80000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_SHIFT (19U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV5_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_MASK (0x100000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_SHIFT (20U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_MASK (0x200000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_SHIFT (21U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV6_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_MASK (0x400000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_SHIFT (22U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_MASK (0x800000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_SHIFT (23U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV8_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_MASK (0x1000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_SHIFT (24U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_MASK (0x2000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_SHIFT (25U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV10_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_MASK (0x4000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_SHIFT (26U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_MASK (0x8000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_SHIFT (27U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_DIV20_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (28U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SEL_MASK (0x20000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SEL_SHIFT (29U)
/*! PLL_LOCK_SEL
 *  0b0..Using PLL maximum lock time
 *  0b1..Using PLL output lock
 */
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name SYS_PLL1_FDIV_CTL0 - SYS PLL1 Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name SYS_PLL1_LOCKD_CTRL - PLL Lock Detector Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_IN_MASK (0x3U)
#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_IN_SHIFT (0U)
#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_IN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_IN_SHIFT)) & CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_IN_MASK)

#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_OUT_MASK (0xCU)
#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_OUT_SHIFT (2U)
#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_OUT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_OUT_SHIFT)) & CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_OUT_MASK)

#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_DLY_MASK (0x30U)
#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_DLY_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_DLY(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_DLY_SHIFT)) & CCM_ANALOG_SYS_PLL1_LOCKD_CTRL_LOCK_CON_DLY_MASK)
/*! @} */

/*! @name SYS_PLL1_MNIT_CTRL - PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_ICP_MASK   (0x3U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_ICP_SHIFT  (0U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_ICP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_EN_MASK (0x4U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_EN_SHIFT (2U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_EXTAFC_MASK (0xF8U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_EXTAFC_SHIFT (3U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_EXTAFC(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FEED_EN_MASK (0x2000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FEED_EN_SHIFT (13U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FSEL_MASK  (0x4000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FSEL_SHIFT (14U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FSEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFCINIT_SEL_MASK (0x10000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFCINIT_SEL_SHIFT (16U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x20000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (17U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_MASK (0x40000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_SHIFT (18U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_SEL_MASK (0x80000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_SEL_SHIFT (19U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_AFC_SEL_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FOUT_MASK_MASK (0x100000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FOUT_MASK_SHIFT (20U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FOUT_MASK_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_FOUT_MASK_MASK)

#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_LRD_EN_MASK (0x200000U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_LRD_EN_SHIFT (21U)
#define CCM_ANALOG_SYS_PLL1_MNIT_CTRL_LRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL1_MNIT_CTRL_LRD_EN_SHIFT)) & CCM_ANALOG_SYS_PLL1_MNIT_CTRL_LRD_EN_MASK)
/*! @} */

/*! @name SYS_PLL2_GEN_CTRL - SYS PLL2 General Function Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x400U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (10U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_MASK (0x800U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_SHIFT (11U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_MASK (0x1000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_SHIFT (12U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_MASK (0x2000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_SHIFT (13U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV2_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_MASK (0x4000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_SHIFT (14U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_MASK (0x8000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_SHIFT (15U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV3_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_MASK (0x10000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_SHIFT (16U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_MASK (0x20000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_SHIFT (17U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV4_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_MASK (0x40000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_SHIFT (18U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_MASK (0x80000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_SHIFT (19U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV5_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_MASK (0x100000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_SHIFT (20U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_MASK (0x200000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_SHIFT (21U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV6_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_MASK (0x400000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_SHIFT (22U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_MASK (0x800000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_SHIFT (23U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV8_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_MASK (0x1000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_SHIFT (24U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_MASK (0x2000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_SHIFT (25U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV10_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_MASK (0x4000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_SHIFT (26U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_MASK (0x8000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_SHIFT (27U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_DIV20_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (28U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SEL_MASK (0x20000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SEL_SHIFT (29U)
/*! PLL_LOCK_SEL
 *  0b0..Using PLL maximum lock time
 *  0b1..Using PLL output lock
 */
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_SYS_PLL2_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name SYS_PLL2_FDIV_CTL0 - SYS PLL2 Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL2_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name SYS_PLL2_LOCKD_CTRL - PLL Lock Detector Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_IN_MASK (0x3U)
#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_IN_SHIFT (0U)
#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_IN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_IN_SHIFT)) & CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_IN_MASK)

#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_OUT_MASK (0xCU)
#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_OUT_SHIFT (2U)
#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_OUT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_OUT_SHIFT)) & CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_OUT_MASK)

#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_DLY_MASK (0x30U)
#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_DLY_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_DLY(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_DLY_SHIFT)) & CCM_ANALOG_SYS_PLL2_LOCKD_CTRL_LOCK_CON_DLY_MASK)
/*! @} */

/*! @name SYS_PLL2_MNIT_CTRL - PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_ICP_MASK   (0x3U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_ICP_SHIFT  (0U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_ICP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_EN_MASK (0x4U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_EN_SHIFT (2U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_EXTAFC_MASK (0xF8U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_EXTAFC_SHIFT (3U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_EXTAFC(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FEED_EN_MASK (0x2000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FEED_EN_SHIFT (13U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FSEL_MASK  (0x4000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FSEL_SHIFT (14U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FSEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFCINIT_SEL_MASK (0x10000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFCINIT_SEL_SHIFT (16U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x20000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (17U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_MASK (0x40000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_SHIFT (18U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_SEL_MASK (0x80000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_SEL_SHIFT (19U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_AFC_SEL_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FOUT_MASK_MASK (0x100000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FOUT_MASK_SHIFT (20U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FOUT_MASK_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_FOUT_MASK_MASK)

#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_LRD_EN_MASK (0x200000U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_LRD_EN_SHIFT (21U)
#define CCM_ANALOG_SYS_PLL2_MNIT_CTRL_LRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL2_MNIT_CTRL_LRD_EN_SHIFT)) & CCM_ANALOG_SYS_PLL2_MNIT_CTRL_LRD_EN_MASK)
/*! @} */

/*! @name SYS_PLL3_GEN_CTRL - SYS PLL3 General Function Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_REF_CLK_SEL_MASK (0x3U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT (0U)
/*! PLL_REF_CLK_SEL
 *  0b00..24M_REF_CLK
 *  0b01..PAD_CLK
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_REF_CLK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_REF_CLK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PAD_CLK_SEL_MASK (0xCU)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PAD_CLK_SEL_SHIFT (2U)
/*! PAD_CLK_SEL
 *  0b00..CLKIN1 XOR CLKIN2
 *  0b01..CLKIN2
 *  0b10..CLKIN1
 *  0b11..Reserved
 */
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PAD_CLK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PAD_CLK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_BYPASS_MASK (0x10U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_BYPASS_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_BYPASS_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_BYPASS_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_OVERRIDE_MASK (0x100U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT (8U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_MASK (0x200U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_SHIFT (9U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_RST_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK (0x400U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT (10U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_OVERRIDE_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_OVERRIDE_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_MASK (0x800U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_SHIFT (11U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_CLKE_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_EXT_BYPASS_MASK (0x10000000U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_EXT_BYPASS_SHIFT (28U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_EXT_BYPASS_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_EXT_BYPASS_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SEL_MASK (0x20000000U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SEL_SHIFT (29U)
/*! PLL_LOCK_SEL
 *  0b0..Using PLL maximum lock time
 *  0b1..Using PLL output lock
 */
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SEL_MASK)

#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_MASK (0x80000000U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SHIFT (31U)
#define CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_SHIFT)) & CCM_ANALOG_SYS_PLL3_GEN_CTRL_PLL_LOCK_MASK)
/*! @} */

/*! @name SYS_PLL3_FDIV_CTL0 - SYS PLL3 Divide and Fraction Data Control 0 Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_POST_DIV_MASK (0x7U)
#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_POST_DIV_SHIFT (0U)
#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_POST_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_POST_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_POST_DIV_MASK)

#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_PRE_DIV_MASK (0x3F0U)
#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_PRE_DIV_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_PRE_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_PRE_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_PRE_DIV_MASK)

#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_MAIN_DIV_MASK (0x3FF000U)
#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_MAIN_DIV_SHIFT (12U)
#define CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_MAIN_DIV(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_MAIN_DIV_SHIFT)) & CCM_ANALOG_SYS_PLL3_FDIV_CTL0_PLL_MAIN_DIV_MASK)
/*! @} */

/*! @name SYS_PLL3_LOCKD_CTRL - PLL Lock Detector Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_IN_MASK (0x3U)
#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_IN_SHIFT (0U)
#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_IN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_IN_SHIFT)) & CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_IN_MASK)

#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_OUT_MASK (0xCU)
#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_OUT_SHIFT (2U)
#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_OUT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_OUT_SHIFT)) & CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_OUT_MASK)

#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_DLY_MASK (0x30U)
#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_DLY_SHIFT (4U)
#define CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_DLY(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_DLY_SHIFT)) & CCM_ANALOG_SYS_PLL3_LOCKD_CTRL_LOCK_CON_DLY_MASK)
/*! @} */

/*! @name SYS_PLL3_MNIT_CTRL - PLL Monitoring Control Register */
/*! @{ */

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_ICP_MASK   (0x3U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_ICP_SHIFT  (0U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_ICP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_ICP_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_ICP_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_EN_MASK (0x4U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_EN_SHIFT (2U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_EN_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_EN_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_EXTAFC_MASK (0xF8U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_EXTAFC_SHIFT (3U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_EXTAFC(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_EXTAFC_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_EXTAFC_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FEED_EN_MASK (0x2000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FEED_EN_SHIFT (13U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FEED_EN_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FEED_EN_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FSEL_MASK  (0x4000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FSEL_SHIFT (14U)
/*! FSEL
 *  0b0..FEED_OUT = FREF
 *  0b1..FEED_OUT = FEED
 */
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FSEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FSEL_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FSEL_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFCINIT_SEL_MASK (0x10000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFCINIT_SEL_SHIFT (16U)
/*! AFCINIT_SEL
 *  0b0..nominal delay
 *  0b1..nominal delay * 2
 */
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFCINIT_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFCINIT_SEL_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_EN_MASK (0x20000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT (17U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_EN_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_EN_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_MASK (0x40000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_SHIFT (18U)
/*! PBIAS_CTRL
 *  0b0..0.50*VDD
 *  0b1..0.67*VDD
 */
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_PBIAS_CTRL_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_SEL_MASK (0x80000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_SEL_SHIFT (19U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_SEL_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_AFC_SEL_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FOUT_MASK_MASK (0x100000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FOUT_MASK_SHIFT (20U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FOUT_MASK_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_FOUT_MASK_MASK)

#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_LRD_EN_MASK (0x200000U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_LRD_EN_SHIFT (21U)
#define CCM_ANALOG_SYS_PLL3_MNIT_CTRL_LRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_SYS_PLL3_MNIT_CTRL_LRD_EN_SHIFT)) & CCM_ANALOG_SYS_PLL3_MNIT_CTRL_LRD_EN_MASK)
/*! @} */

/*! @name OSC_MISC_CFG - Osc Misc Configuration Register */
/*! @{ */

#define CCM_ANALOG_OSC_MISC_CFG_OSC_32K_SEL_MASK (0x1U)
#define CCM_ANALOG_OSC_MISC_CFG_OSC_32K_SEL_SHIFT (0U)
/*! OSC_32K_SEL
 *  0b0..Divided by 24M clock
 *  0b1..32K Oscillator
 */
#define CCM_ANALOG_OSC_MISC_CFG_OSC_32K_SEL(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_OSC_MISC_CFG_OSC_32K_SEL_SHIFT)) & CCM_ANALOG_OSC_MISC_CFG_OSC_32K_SEL_MASK)
/*! @} */

/*! @name ANAMIX_PLL_MNIT_CTL - PLL Clock Output for Test Enable and Select Register */
/*! @{ */

#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_DIV_VAL_MASK (0xFU)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_DIV_VAL_SHIFT (0U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_DIV_VAL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_DIV_VAL_SHIFT)) & CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_DIV_VAL_MASK)

#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_SEL_MASK (0xF0U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_SEL_SHIFT (4U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_SEL_SHIFT)) & CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_SEL_MASK)

#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_CKE_MASK (0x100U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_CKE_SHIFT (8U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_CKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_CKE_SHIFT)) & CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT1_OUTPUT_CKE_MASK)

#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_DIV_VAL_MASK (0xF0000U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_DIV_VAL_SHIFT (16U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_DIV_VAL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_DIV_VAL_SHIFT)) & CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_DIV_VAL_MASK)

#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_SEL_MASK (0xF00000U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_SEL_SHIFT (20U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_SEL_SHIFT)) & CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_SEL_MASK)

#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_CKE_MASK (0x1000000U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_CKE_SHIFT (24U)
#define CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_CKE(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_CKE_SHIFT)) & CCM_ANALOG_ANAMIX_PLL_MNIT_CTL_CLKOUT2_OUTPUT_CKE_MASK)
/*! @} */

/*! @name DIGPROG - DIGPROG Register */
/*! @{ */

#define CCM_ANALOG_DIGPROG_DIGPROG_MINOR_MASK    (0xFFU)
#define CCM_ANALOG_DIGPROG_DIGPROG_MINOR_SHIFT   (0U)
#define CCM_ANALOG_DIGPROG_DIGPROG_MINOR(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DIGPROG_DIGPROG_MINOR_SHIFT)) & CCM_ANALOG_DIGPROG_DIGPROG_MINOR_MASK)

#define CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_LOWER_MASK (0xFF00U)
#define CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_LOWER_SHIFT (8U)
#define CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_LOWER(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_LOWER_SHIFT)) & CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_LOWER_MASK)

#define CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_UPPER_MASK (0xFF0000U)
#define CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_UPPER_SHIFT (16U)
#define CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_UPPER(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_UPPER_SHIFT)) & CCM_ANALOG_DIGPROG_DIGPROG_MAJOR_UPPER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CCM_ANALOG_Register_Masks */


/* CCM_ANALOG - Peripheral instance base addresses */
/** Peripheral CCM_ANALOG base address */
#define CCM_ANALOG_BASE                          (0x30360000u)
/** Peripheral CCM_ANALOG base pointer */
#define CCM_ANALOG                               ((CCM_ANALOG_Type *)CCM_ANALOG_BASE)
/** Array initializer of CCM_ANALOG peripheral base addresses */
#define CCM_ANALOG_BASE_ADDRS                    { CCM_ANALOG_BASE }
/** Array initializer of CCM_ANALOG peripheral base pointers */
#define CCM_ANALOG_BASE_PTRS                     { CCM_ANALOG }

/*!
 * @}
 */ /* end of group CCM_ANALOG_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- IOMUXC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Peripheral_Access_Layer IOMUXC Peripheral Access Layer
 * @{
 */

/** IOMUXC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[20];
  __IO uint32_t SW_MUX_CTL_PAD[143];               /**< SW_MUX_CTL_PAD_GPIO1_IO00 SW MUX Control Register..SW_MUX_CTL_PAD_HDMI_HPD SW MUX Control Register, array offset: 0x14, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD[156];               /**< SW_PAD_CTL_PAD_BOOT_MODE0 SW PAD Control Register..SW_PAD_CTL_PAD_CLKOUT2 SW PAD Control Register, array offset: 0x250, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[94];                  /**< AUDIOMIX_PDM_MIC_PDM_BITSTREAM_SELECT_INPUT_0 DAISY Register..USDHC3_WP_ON_SELECT_INPUT DAISY Register, array offset: 0x4C0, array step: 0x4 */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_GPIO1_IO00 SW MUX Control Register..SW_MUX_CTL_PAD_HDMI_HPD SW MUX Control Register */
/*! @{ */

#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK      (0x7U)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT     (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: GPIO1_IO00 of instance: gpio1
 *  0b001..Select mux mode: ALT1 mux port: CCM_ENET_PHY_REF_CLK_ROOT of instance: ccm
 *  0b011..Select mux mode: ALT3 mux port: ISP_FL_TRIG_0 of instance: isp
 *  0b101..Select mux mode: ALT5 mux port: ANAMIX_REF_CLK_32K of instance: anamix
 *  0b110..Select mux mode: ALT6 mux port: CCM_EXT_CLK1 of instance: ccm
 */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK)

#define IOMUXC_SW_MUX_CTL_PAD_SION_MASK          (0x10U)
#define IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT         (4U)
/*! SION - Software Input On Field.
 *  0b1..Force input path of pad GPIO1_IO00
 *  0b0..Input Path is determined by functionality
 */
#define IOMUXC_SW_MUX_CTL_PAD_SION(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_SION_MASK)
/*! @} */

/* The count of IOMUXC_SW_MUX_CTL_PAD */
#define IOMUXC_SW_MUX_CTL_PAD_COUNT              (143U)

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_BOOT_MODE0 SW PAD Control Register..SW_PAD_CTL_PAD_CLKOUT2 SW PAD Control Register */
/*! @{ */

#define IOMUXC_SW_PAD_CTL_PAD_DSE_MASK           (0x6U)
#define IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT          (1U)
/*! DSE - Drive Strength Field
 *  0b00..X1
 *  0b10..X2
 *  0b01..X4
 *  0b11..X6
 */
#define IOMUXC_SW_PAD_CTL_PAD_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK          (0x10U)
#define IOMUXC_SW_PAD_CTL_PAD_FSEL_SHIFT         (4U)
/*! FSEL - Slew Rate Field
 *  0b0..Slow Slew Rate (SR=1)
 *  0b1..Fast Slew Rate (SR=0)
 */
#define IOMUXC_SW_PAD_CTL_PAD_FSEL(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_FSEL_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_ODE_MASK           (0x20U)
#define IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT          (5U)
/*! ODE - Open Drain Field
 *  0b0..Open Drain Disable
 *  0b1..Open Drain Enable
 */
#define IOMUXC_SW_PAD_CTL_PAD_ODE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_ODE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PUE_MASK           (0x40U)
#define IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT          (6U)
/*! PUE - Pull Up / Down Config. Field
 *  0b0..Weak pull down
 *  0b1..Weak pull up
 */
#define IOMUXC_SW_PAD_CTL_PAD_PUE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_HYS_MASK           (0x80U)
#define IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT          (7U)
/*! HYS - Input Select Field
 *  0b0..CMOS
 *  0b1..Schmitt
 */
#define IOMUXC_SW_PAD_CTL_PAD_HYS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_HYS_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PE_MASK            (0x100U)
#define IOMUXC_SW_PAD_CTL_PAD_PE_SHIFT           (8U)
/*! PE - Pull Select Field
 *  0b0..Pull Disable
 *  0b1..Pull Enable
 */
#define IOMUXC_SW_PAD_CTL_PAD_PE(x)              (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PE_MASK)
/*! @} */

/* The count of IOMUXC_SW_PAD_CTL_PAD */
#define IOMUXC_SW_PAD_CTL_PAD_COUNT              (156U)

/*! @name SELECT_INPUT - AUDIOMIX_PDM_MIC_PDM_BITSTREAM_SELECT_INPUT_0 DAISY Register..USDHC3_WP_ON_SELECT_INPUT DAISY Register */
/*! @{ */

#define IOMUXC_SELECT_INPUT_DAISY_MASK           (0xFU)  /* Merged from fields with different position or width, of widths (1, 2, 3, 4), largest definition used */
#define IOMUXC_SELECT_INPUT_DAISY_SHIFT          (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b000..Selecting Pad: ENET_TD1 for Mode: ALT3
 *  0b001..Selecting Pad: ENET_RD1 for Mode: ALT3
 *  0b010..Selecting Pad: SD2_DATA0 for Mode: ALT4
 *  0b011..Selecting Pad: SAI5_RXD0 for Mode: ALT4
 *  0b100..Selecting Pad: SAI1_RXD0 for Mode: ALT3
 *  0b101..Selecting Pad: SAI3_RXFS for Mode: ALT6
 */
#define IOMUXC_SELECT_INPUT_DAISY(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 3, 4), largest definition used */
/*! @} */

/* The count of IOMUXC_SELECT_INPUT */
#define IOMUXC_SELECT_INPUT_COUNT                (94U)


/*!
 * @}
 */ /* end of group IOMUXC_Register_Masks */


/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x30330000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/*!
 * @}
 */ /* end of group IOMUXC_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __I  uint32_t URXD;                              /**< UART Receiver Register, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __O  uint32_t UTXD;                              /**< UART Transmitter Register, offset: 0x40 */
       uint8_t RESERVED_1[60];
  __IO uint32_t UCR1;                              /**< UART Control Register 1, offset: 0x80 */
  __IO uint32_t UCR2;                              /**< UART Control Register 2, offset: 0x84 */
  __IO uint32_t UCR3;                              /**< UART Control Register 3, offset: 0x88 */
  __IO uint32_t UCR4;                              /**< UART Control Register 4, offset: 0x8C */
  __IO uint32_t UFCR;                              /**< UART FIFO Control Register, offset: 0x90 */
  __IO uint32_t USR1;                              /**< UART Status Register 1, offset: 0x94 */
  __IO uint32_t USR2;                              /**< UART Status Register 2, offset: 0x98 */
  __IO uint32_t UESC;                              /**< UART Escape Character Register, offset: 0x9C */
  __IO uint32_t UTIM;                              /**< UART Escape Timer Register, offset: 0xA0 */
  __IO uint32_t UBIR;                              /**< UART BRM Incremental Register, offset: 0xA4 */
  __IO uint32_t UBMR;                              /**< UART BRM Modulator Register, offset: 0xA8 */
  __I  uint32_t UBRC;                              /**< UART Baud Rate Count Register, offset: 0xAC */
  __IO uint32_t ONEMS;                             /**< UART One Millisecond Register, offset: 0xB0 */
  __IO uint32_t UTS;                               /**< UART Test Register, offset: 0xB4 */
  __IO uint32_t UMCR;                              /**< UART RS-485 Mode Control Register, offset: 0xB8 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name URXD - UART Receiver Register */
/*! @{ */

#define UART_URXD_RX_DATA_MASK                   (0xFFU)
#define UART_URXD_RX_DATA_SHIFT                  (0U)
#define UART_URXD_RX_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << UART_URXD_RX_DATA_SHIFT)) & UART_URXD_RX_DATA_MASK)

#define UART_URXD_PRERR_MASK                     (0x400U)
#define UART_URXD_PRERR_SHIFT                    (10U)
/*! PRERR
 *  0b0..= No parity error was detected for data in the RX_DATA field
 *  0b1..= A parity error was detected for data in the RX_DATA field
 */
#define UART_URXD_PRERR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_URXD_PRERR_SHIFT)) & UART_URXD_PRERR_MASK)

#define UART_URXD_BRK_MASK                       (0x800U)
#define UART_URXD_BRK_SHIFT                      (11U)
/*! BRK
 *  0b0..The current character is not a BREAK character
 *  0b1..The current character is a BREAK character
 */
#define UART_URXD_BRK(x)                         (((uint32_t)(((uint32_t)(x)) << UART_URXD_BRK_SHIFT)) & UART_URXD_BRK_MASK)

#define UART_URXD_FRMERR_MASK                    (0x1000U)
#define UART_URXD_FRMERR_SHIFT                   (12U)
/*! FRMERR
 *  0b0..The current character has no framing error
 *  0b1..The current character has a framing error
 */
#define UART_URXD_FRMERR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_URXD_FRMERR_SHIFT)) & UART_URXD_FRMERR_MASK)

#define UART_URXD_OVRRUN_MASK                    (0x2000U)
#define UART_URXD_OVRRUN_SHIFT                   (13U)
/*! OVRRUN
 *  0b0..No RxFIFO overrun was detected
 *  0b1..A RxFIFO overrun was detected
 */
#define UART_URXD_OVRRUN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_URXD_OVRRUN_SHIFT)) & UART_URXD_OVRRUN_MASK)

#define UART_URXD_ERR_MASK                       (0x4000U)
#define UART_URXD_ERR_SHIFT                      (14U)
/*! ERR
 *  0b0..No error status was detected
 *  0b1..An error status was detected
 */
#define UART_URXD_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_URXD_ERR_SHIFT)) & UART_URXD_ERR_MASK)

#define UART_URXD_CHARRDY_MASK                   (0x8000U)
#define UART_URXD_CHARRDY_SHIFT                  (15U)
/*! CHARRDY
 *  0b0..Character in RX_DATA field and associated flags are invalid.
 *  0b1..Character in RX_DATA field and associated flags valid and ready for reading.
 */
#define UART_URXD_CHARRDY(x)                     (((uint32_t)(((uint32_t)(x)) << UART_URXD_CHARRDY_SHIFT)) & UART_URXD_CHARRDY_MASK)
/*! @} */

/*! @name UTXD - UART Transmitter Register */
/*! @{ */

#define UART_UTXD_TX_DATA_MASK                   (0xFFU)
#define UART_UTXD_TX_DATA_SHIFT                  (0U)
#define UART_UTXD_TX_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UTXD_TX_DATA_SHIFT)) & UART_UTXD_TX_DATA_MASK)
/*! @} */

/*! @name UCR1 - UART Control Register 1 */
/*! @{ */

#define UART_UCR1_UARTEN_MASK                    (0x1U)
#define UART_UCR1_UARTEN_SHIFT                   (0U)
/*! UARTEN
 *  0b0..Disable the UART
 *  0b1..Enable the UART
 */
#define UART_UCR1_UARTEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_UARTEN_SHIFT)) & UART_UCR1_UARTEN_MASK)

#define UART_UCR1_DOZE_MASK                      (0x2U)
#define UART_UCR1_DOZE_SHIFT                     (1U)
/*! DOZE
 *  0b0..The UART is enabled when in DOZE state
 *  0b1..The UART is disabled when in DOZE state
 */
#define UART_UCR1_DOZE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_DOZE_SHIFT)) & UART_UCR1_DOZE_MASK)

#define UART_UCR1_ATDMAEN_MASK                   (0x4U)
#define UART_UCR1_ATDMAEN_SHIFT                  (2U)
/*! ATDMAEN
 *  0b0..Disable AGTIM DMA request
 *  0b1..Enable AGTIM DMA request
 */
#define UART_UCR1_ATDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ATDMAEN_SHIFT)) & UART_UCR1_ATDMAEN_MASK)

#define UART_UCR1_TXDMAEN_MASK                   (0x8U)
#define UART_UCR1_TXDMAEN_SHIFT                  (3U)
/*! TXDMAEN
 *  0b0..Disable transmit DMA request
 *  0b1..Enable transmit DMA request
 */
#define UART_UCR1_TXDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TXDMAEN_SHIFT)) & UART_UCR1_TXDMAEN_MASK)

#define UART_UCR1_SNDBRK_MASK                    (0x10U)
#define UART_UCR1_SNDBRK_SHIFT                   (4U)
/*! SNDBRK
 *  0b0..Do not send a BREAK character
 *  0b1..Send a BREAK character (continuous 0s)
 */
#define UART_UCR1_SNDBRK(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_SNDBRK_SHIFT)) & UART_UCR1_SNDBRK_MASK)

#define UART_UCR1_RTSDEN_MASK                    (0x20U)
#define UART_UCR1_RTSDEN_SHIFT                   (5U)
/*! RTSDEN
 *  0b0..Disable RTSD interrupt
 *  0b1..Enable RTSD interrupt
 */
#define UART_UCR1_RTSDEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RTSDEN_SHIFT)) & UART_UCR1_RTSDEN_MASK)

#define UART_UCR1_TXMPTYEN_MASK                  (0x40U)
#define UART_UCR1_TXMPTYEN_SHIFT                 (6U)
/*! TXMPTYEN
 *  0b0..Disable the transmitter FIFO empty interrupt
 *  0b1..Enable the transmitter FIFO empty interrupt
 */
#define UART_UCR1_TXMPTYEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TXMPTYEN_SHIFT)) & UART_UCR1_TXMPTYEN_MASK)

#define UART_UCR1_IREN_MASK                      (0x80U)
#define UART_UCR1_IREN_SHIFT                     (7U)
/*! IREN
 *  0b0..Disable the IR interface
 *  0b1..Enable the IR interface
 */
#define UART_UCR1_IREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_IREN_SHIFT)) & UART_UCR1_IREN_MASK)

#define UART_UCR1_RXDMAEN_MASK                   (0x100U)
#define UART_UCR1_RXDMAEN_SHIFT                  (8U)
/*! RXDMAEN
 *  0b0..Disable DMA request
 *  0b1..Enable DMA request
 */
#define UART_UCR1_RXDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RXDMAEN_SHIFT)) & UART_UCR1_RXDMAEN_MASK)

#define UART_UCR1_RRDYEN_MASK                    (0x200U)
#define UART_UCR1_RRDYEN_SHIFT                   (9U)
/*! RRDYEN
 *  0b0..Disables the RRDY interrupt
 *  0b1..Enables the RRDY interrupt
 */
#define UART_UCR1_RRDYEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RRDYEN_SHIFT)) & UART_UCR1_RRDYEN_MASK)

#define UART_UCR1_ICD_MASK                       (0xC00U)
#define UART_UCR1_ICD_SHIFT                      (10U)
/*! ICD
 *  0b00..Idle for more than 4 frames
 *  0b01..Idle for more than 8 frames
 *  0b10..Idle for more than 16 frames
 *  0b11..Idle for more than 32 frames
 */
#define UART_UCR1_ICD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ICD_SHIFT)) & UART_UCR1_ICD_MASK)

#define UART_UCR1_IDEN_MASK                      (0x1000U)
#define UART_UCR1_IDEN_SHIFT                     (12U)
/*! IDEN
 *  0b0..Disable the IDLE interrupt
 *  0b1..Enable the IDLE interrupt
 */
#define UART_UCR1_IDEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_IDEN_SHIFT)) & UART_UCR1_IDEN_MASK)

#define UART_UCR1_TRDYEN_MASK                    (0x2000U)
#define UART_UCR1_TRDYEN_SHIFT                   (13U)
/*! TRDYEN
 *  0b0..Disable the transmitter ready interrupt
 *  0b1..Enable the transmitter ready interrupt
 */
#define UART_UCR1_TRDYEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TRDYEN_SHIFT)) & UART_UCR1_TRDYEN_MASK)

#define UART_UCR1_ADBR_MASK                      (0x4000U)
#define UART_UCR1_ADBR_SHIFT                     (14U)
/*! ADBR
 *  0b0..Disable automatic detection of baud rate
 *  0b1..Enable automatic detection of baud rate
 */
#define UART_UCR1_ADBR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ADBR_SHIFT)) & UART_UCR1_ADBR_MASK)

#define UART_UCR1_ADEN_MASK                      (0x8000U)
#define UART_UCR1_ADEN_SHIFT                     (15U)
/*! ADEN
 *  0b0..Disable the automatic baud rate detection interrupt
 *  0b1..Enable the automatic baud rate detection interrupt
 */
#define UART_UCR1_ADEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ADEN_SHIFT)) & UART_UCR1_ADEN_MASK)
/*! @} */

/*! @name UCR2 - UART Control Register 2 */
/*! @{ */

#define UART_UCR2_SRST_MASK                      (0x1U)
#define UART_UCR2_SRST_SHIFT                     (0U)
/*! SRST
 *  0b0..Reset the transmit and receive state machines, all FIFOs and register USR1, USR2, UBIR, UBMR, UBRC , URXD, UTXD and UTS[6-3].
 *  0b1..No reset
 */
#define UART_UCR2_SRST(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_SRST_SHIFT)) & UART_UCR2_SRST_MASK)

#define UART_UCR2_RXEN_MASK                      (0x2U)
#define UART_UCR2_RXEN_SHIFT                     (1U)
/*! RXEN
 *  0b0..Disable the receiver
 *  0b1..Enable the receiver
 */
#define UART_UCR2_RXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RXEN_SHIFT)) & UART_UCR2_RXEN_MASK)

#define UART_UCR2_TXEN_MASK                      (0x4U)
#define UART_UCR2_TXEN_SHIFT                     (2U)
/*! TXEN
 *  0b0..Disable the transmitter
 *  0b1..Enable the transmitter
 */
#define UART_UCR2_TXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_TXEN_SHIFT)) & UART_UCR2_TXEN_MASK)

#define UART_UCR2_ATEN_MASK                      (0x8U)
#define UART_UCR2_ATEN_SHIFT                     (3U)
/*! ATEN
 *  0b0..AGTIM interrupt disabled
 *  0b1..AGTIM interrupt enabled
 */
#define UART_UCR2_ATEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ATEN_SHIFT)) & UART_UCR2_ATEN_MASK)

#define UART_UCR2_RTSEN_MASK                     (0x10U)
#define UART_UCR2_RTSEN_SHIFT                    (4U)
/*! RTSEN
 *  0b0..Disable request to send interrupt
 *  0b1..Enable request to send interrupt
 */
#define UART_UCR2_RTSEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RTSEN_SHIFT)) & UART_UCR2_RTSEN_MASK)

#define UART_UCR2_WS_MASK                        (0x20U)
#define UART_UCR2_WS_SHIFT                       (5U)
/*! WS
 *  0b0..7-bit transmit and receive character length (not including START, STOP or PARITY bits)
 *  0b1..8-bit transmit and receive character length (not including START, STOP or PARITY bits)
 */
#define UART_UCR2_WS(x)                          (((uint32_t)(((uint32_t)(x)) << UART_UCR2_WS_SHIFT)) & UART_UCR2_WS_MASK)

#define UART_UCR2_STPB_MASK                      (0x40U)
#define UART_UCR2_STPB_SHIFT                     (6U)
/*! STPB
 *  0b0..The transmitter sends 1 stop bit. The receiver expects 1 or more stop bits.
 *  0b1..The transmitter sends 2 stop bits. The receiver expects 2 or more stop bits.
 */
#define UART_UCR2_STPB(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_STPB_SHIFT)) & UART_UCR2_STPB_MASK)

#define UART_UCR2_PROE_MASK                      (0x80U)
#define UART_UCR2_PROE_SHIFT                     (7U)
/*! PROE
 *  0b0..Even parity
 *  0b1..Odd parity
 */
#define UART_UCR2_PROE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_PROE_SHIFT)) & UART_UCR2_PROE_MASK)

#define UART_UCR2_PREN_MASK                      (0x100U)
#define UART_UCR2_PREN_SHIFT                     (8U)
/*! PREN
 *  0b0..Disable parity generator and checker
 *  0b1..Enable parity generator and checker
 */
#define UART_UCR2_PREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_PREN_SHIFT)) & UART_UCR2_PREN_MASK)

#define UART_UCR2_RTEC_MASK                      (0x600U)
#define UART_UCR2_RTEC_SHIFT                     (9U)
/*! RTEC
 *  0b00..Trigger interrupt on a rising edge
 *  0b01..Trigger interrupt on a falling edge
 *  0b1x..Trigger interrupt on any edge
 */
#define UART_UCR2_RTEC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RTEC_SHIFT)) & UART_UCR2_RTEC_MASK)

#define UART_UCR2_ESCEN_MASK                     (0x800U)
#define UART_UCR2_ESCEN_SHIFT                    (11U)
/*! ESCEN
 *  0b0..Disable escape sequence detection
 *  0b1..Enable escape sequence detection
 */
#define UART_UCR2_ESCEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ESCEN_SHIFT)) & UART_UCR2_ESCEN_MASK)

#define UART_UCR2_CTS_MASK                       (0x1000U)
#define UART_UCR2_CTS_SHIFT                      (12U)
/*! CTS
 *  0b0..The CTS_B pin is high (inactive)
 *  0b1..The CTS_B pin is low (active)
 */
#define UART_UCR2_CTS(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR2_CTS_SHIFT)) & UART_UCR2_CTS_MASK)

#define UART_UCR2_CTSC_MASK                      (0x2000U)
#define UART_UCR2_CTSC_SHIFT                     (13U)
/*! CTSC
 *  0b0..The CTS_B pin is controlled by the CTS bit
 *  0b1..The CTS_B pin is controlled by the receiver
 */
#define UART_UCR2_CTSC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_CTSC_SHIFT)) & UART_UCR2_CTSC_MASK)

#define UART_UCR2_IRTS_MASK                      (0x4000U)
#define UART_UCR2_IRTS_SHIFT                     (14U)
/*! IRTS
 *  0b0..Transmit only when the RTS pin is asserted
 *  0b1..Ignore the RTS pin
 */
#define UART_UCR2_IRTS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_IRTS_SHIFT)) & UART_UCR2_IRTS_MASK)

#define UART_UCR2_ESCI_MASK                      (0x8000U)
#define UART_UCR2_ESCI_SHIFT                     (15U)
/*! ESCI
 *  0b0..Disable the escape sequence interrupt
 *  0b1..Enable the escape sequence interrupt
 */
#define UART_UCR2_ESCI(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ESCI_SHIFT)) & UART_UCR2_ESCI_MASK)
/*! @} */

/*! @name UCR3 - UART Control Register 3 */
/*! @{ */

#define UART_UCR3_ACIEN_MASK                     (0x1U)
#define UART_UCR3_ACIEN_SHIFT                    (0U)
/*! ACIEN
 *  0b0..ACST interrupt disabled
 *  0b1..ACST interrupt enabled
 */
#define UART_UCR3_ACIEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR3_ACIEN_SHIFT)) & UART_UCR3_ACIEN_MASK)

#define UART_UCR3_INVT_MASK                      (0x2U)
#define UART_UCR3_INVT_SHIFT                     (1U)
/*! INVT
 *  0b0..TXD is not inverted
 *  0b1..TXD is inverted
 *  0b0..TXD Active low transmission
 *  0b1..TXD Active high transmission
 */
#define UART_UCR3_INVT(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR3_INVT_SHIFT)) & UART_UCR3_INVT_MASK)

#define UART_UCR3_RXDMUXSEL_MASK                 (0x4U)
#define UART_UCR3_RXDMUXSEL_SHIFT                (2U)
#define UART_UCR3_RXDMUXSEL(x)                   (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RXDMUXSEL_SHIFT)) & UART_UCR3_RXDMUXSEL_MASK)

#define UART_UCR3_DTRDEN_MASK                    (0x8U)
#define UART_UCR3_DTRDEN_SHIFT                   (3U)
#define UART_UCR3_DTRDEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DTRDEN_SHIFT)) & UART_UCR3_DTRDEN_MASK)

#define UART_UCR3_AWAKEN_MASK                    (0x10U)
#define UART_UCR3_AWAKEN_SHIFT                   (4U)
/*! AWAKEN
 *  0b0..Disable the AWAKE interrupt
 *  0b1..Enable the AWAKE interrupt
 */
#define UART_UCR3_AWAKEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_AWAKEN_SHIFT)) & UART_UCR3_AWAKEN_MASK)

#define UART_UCR3_AIRINTEN_MASK                  (0x20U)
#define UART_UCR3_AIRINTEN_SHIFT                 (5U)
/*! AIRINTEN
 *  0b0..Disable the AIRINT interrupt
 *  0b1..Enable the AIRINT interrupt
 */
#define UART_UCR3_AIRINTEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_AIRINTEN_SHIFT)) & UART_UCR3_AIRINTEN_MASK)

#define UART_UCR3_RXDSEN_MASK                    (0x40U)
#define UART_UCR3_RXDSEN_SHIFT                   (6U)
/*! RXDSEN
 *  0b0..Disable the RXDS interrupt
 *  0b1..Enable the RXDS interrupt
 */
#define UART_UCR3_RXDSEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RXDSEN_SHIFT)) & UART_UCR3_RXDSEN_MASK)

#define UART_UCR3_ADNIMP_MASK                    (0x80U)
#define UART_UCR3_ADNIMP_SHIFT                   (7U)
/*! ADNIMP
 *  0b0..Autobaud detection new features selected
 *  0b1..Keep old autobaud detection mechanism
 */
#define UART_UCR3_ADNIMP(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_ADNIMP_SHIFT)) & UART_UCR3_ADNIMP_MASK)

#define UART_UCR3_RI_MASK                        (0x100U)
#define UART_UCR3_RI_SHIFT                       (8U)
#define UART_UCR3_RI(x)                          (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RI_SHIFT)) & UART_UCR3_RI_MASK)

#define UART_UCR3_DCD_MASK                       (0x200U)
#define UART_UCR3_DCD_SHIFT                      (9U)
#define UART_UCR3_DCD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DCD_SHIFT)) & UART_UCR3_DCD_MASK)

#define UART_UCR3_DSR_MASK                       (0x400U)
#define UART_UCR3_DSR_SHIFT                      (10U)
#define UART_UCR3_DSR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DSR_SHIFT)) & UART_UCR3_DSR_MASK)

#define UART_UCR3_FRAERREN_MASK                  (0x800U)
#define UART_UCR3_FRAERREN_SHIFT                 (11U)
/*! FRAERREN
 *  0b0..Disable the frame error interrupt
 *  0b1..Enable the frame error interrupt
 */
#define UART_UCR3_FRAERREN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_FRAERREN_SHIFT)) & UART_UCR3_FRAERREN_MASK)

#define UART_UCR3_PARERREN_MASK                  (0x1000U)
#define UART_UCR3_PARERREN_SHIFT                 (12U)
/*! PARERREN
 *  0b0..Disable the parity error interrupt
 *  0b1..Enable the parity error interrupt
 */
#define UART_UCR3_PARERREN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_PARERREN_SHIFT)) & UART_UCR3_PARERREN_MASK)

#define UART_UCR3_DTREN_MASK                     (0x2000U)
#define UART_UCR3_DTREN_SHIFT                    (13U)
#define UART_UCR3_DTREN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DTREN_SHIFT)) & UART_UCR3_DTREN_MASK)

#define UART_UCR3_DPEC_MASK                      (0xC000U)
#define UART_UCR3_DPEC_SHIFT                     (14U)
#define UART_UCR3_DPEC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DPEC_SHIFT)) & UART_UCR3_DPEC_MASK)
/*! @} */

/*! @name UCR4 - UART Control Register 4 */
/*! @{ */

#define UART_UCR4_DREN_MASK                      (0x1U)
#define UART_UCR4_DREN_SHIFT                     (0U)
/*! DREN
 *  0b0..Disable RDR interrupt
 *  0b1..Enable RDR interrupt
 */
#define UART_UCR4_DREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_DREN_SHIFT)) & UART_UCR4_DREN_MASK)

#define UART_UCR4_OREN_MASK                      (0x2U)
#define UART_UCR4_OREN_SHIFT                     (1U)
/*! OREN
 *  0b0..Disable ORE interrupt
 *  0b1..Enable ORE interrupt
 */
#define UART_UCR4_OREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_OREN_SHIFT)) & UART_UCR4_OREN_MASK)

#define UART_UCR4_BKEN_MASK                      (0x4U)
#define UART_UCR4_BKEN_SHIFT                     (2U)
/*! BKEN
 *  0b0..Disable the BRCD interrupt
 *  0b1..Enable the BRCD interrupt
 */
#define UART_UCR4_BKEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_BKEN_SHIFT)) & UART_UCR4_BKEN_MASK)

#define UART_UCR4_TCEN_MASK                      (0x8U)
#define UART_UCR4_TCEN_SHIFT                     (3U)
/*! TCEN
 *  0b0..Disable TXDC interrupt
 *  0b1..Enable TXDC interrupt
 */
#define UART_UCR4_TCEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_TCEN_SHIFT)) & UART_UCR4_TCEN_MASK)

#define UART_UCR4_LPBYP_MASK                     (0x10U)
#define UART_UCR4_LPBYP_SHIFT                    (4U)
/*! LPBYP
 *  0b0..Low power features enabled
 *  0b1..Low power features disabled
 */
#define UART_UCR4_LPBYP(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_LPBYP_SHIFT)) & UART_UCR4_LPBYP_MASK)

#define UART_UCR4_IRSC_MASK                      (0x20U)
#define UART_UCR4_IRSC_SHIFT                     (5U)
/*! IRSC
 *  0b0..The vote logic uses the sampling clock (16x baud rate) for normal operation
 *  0b1..The vote logic uses the UART reference clock
 */
#define UART_UCR4_IRSC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_IRSC_SHIFT)) & UART_UCR4_IRSC_MASK)

#define UART_UCR4_IDDMAEN_MASK                   (0x40U)
#define UART_UCR4_IDDMAEN_SHIFT                  (6U)
/*! IDDMAEN
 *  0b0..DMA IDLE interrupt disabled
 *  0b1..DMA IDLE interrupt enabled
 */
#define UART_UCR4_IDDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR4_IDDMAEN_SHIFT)) & UART_UCR4_IDDMAEN_MASK)

#define UART_UCR4_WKEN_MASK                      (0x80U)
#define UART_UCR4_WKEN_SHIFT                     (7U)
/*! WKEN
 *  0b0..Disable the WAKE interrupt
 *  0b1..Enable the WAKE interrupt
 */
#define UART_UCR4_WKEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_WKEN_SHIFT)) & UART_UCR4_WKEN_MASK)

#define UART_UCR4_ENIRI_MASK                     (0x100U)
#define UART_UCR4_ENIRI_SHIFT                    (8U)
/*! ENIRI
 *  0b0..Serial infrared Interrupt disabled
 *  0b1..Serial infrared Interrupt enabled
 */
#define UART_UCR4_ENIRI(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_ENIRI_SHIFT)) & UART_UCR4_ENIRI_MASK)

#define UART_UCR4_INVR_MASK                      (0x200U)
#define UART_UCR4_INVR_SHIFT                     (9U)
/*! INVR
 *  0b0..RXD input is not inverted
 *  0b1..RXD input is inverted
 *  0b0..RXD active low detection
 *  0b1..RXD active high detection
 */
#define UART_UCR4_INVR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_INVR_SHIFT)) & UART_UCR4_INVR_MASK)

#define UART_UCR4_CTSTL_MASK                     (0xFC00U)
#define UART_UCR4_CTSTL_SHIFT                    (10U)
/*! CTSTL
 *  0b000000..0 characters received
 *  0b000001..1 characters in the RxFIFO
 *  0b100000..32 characters in the RxFIFO (maximum)
 */
#define UART_UCR4_CTSTL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_CTSTL_SHIFT)) & UART_UCR4_CTSTL_MASK)
/*! @} */

/*! @name UFCR - UART FIFO Control Register */
/*! @{ */

#define UART_UFCR_RXTL_MASK                      (0x3FU)
#define UART_UFCR_RXTL_SHIFT                     (0U)
/*! RXTL
 *  0b000000..0 characters received
 *  0b000001..RxFIFO has 1 character
 *  0b011111..RxFIFO has 31 characters
 *  0b100000..RxFIFO has 32 characters (maximum)
 */
#define UART_UFCR_RXTL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UFCR_RXTL_SHIFT)) & UART_UFCR_RXTL_MASK)

#define UART_UFCR_DCEDTE_MASK                    (0x40U)
#define UART_UFCR_DCEDTE_SHIFT                   (6U)
/*! DCEDTE
 *  0b0..DCE mode selected
 *  0b1..DTE mode selected
 */
#define UART_UFCR_DCEDTE(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UFCR_DCEDTE_SHIFT)) & UART_UFCR_DCEDTE_MASK)

#define UART_UFCR_RFDIV_MASK                     (0x380U)
#define UART_UFCR_RFDIV_SHIFT                    (7U)
/*! RFDIV
 *  0b000..Divide input clock by 6
 *  0b001..Divide input clock by 5
 *  0b010..Divide input clock by 4
 *  0b011..Divide input clock by 3
 *  0b100..Divide input clock by 2
 *  0b101..Divide input clock by 1
 *  0b110..Divide input clock by 7
 *  0b111..Reserved
 */
#define UART_UFCR_RFDIV(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UFCR_RFDIV_SHIFT)) & UART_UFCR_RFDIV_MASK)

#define UART_UFCR_TXTL_MASK                      (0xFC00U)
#define UART_UFCR_TXTL_SHIFT                     (10U)
/*! TXTL
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..TxFIFO has 2 or fewer characters
 *  0b011111..TxFIFO has 31 or fewer characters
 *  0b100000..TxFIFO has 32 characters (maximum)
 */
#define UART_UFCR_TXTL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UFCR_TXTL_SHIFT)) & UART_UFCR_TXTL_MASK)
/*! @} */

/*! @name USR1 - UART Status Register 1 */
/*! @{ */

#define UART_USR1_SAD_MASK                       (0x8U)
#define UART_USR1_SAD_SHIFT                      (3U)
/*! SAD
 *  0b0..No slave address detected
 *  0b1..Slave address detected
 */
#define UART_USR1_SAD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR1_SAD_SHIFT)) & UART_USR1_SAD_MASK)

#define UART_USR1_AWAKE_MASK                     (0x10U)
#define UART_USR1_AWAKE_SHIFT                    (4U)
/*! AWAKE
 *  0b0..No falling edge was detected on the RXD Serial pin
 *  0b1..A falling edge was detected on the RXD Serial pin
 */
#define UART_USR1_AWAKE(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR1_AWAKE_SHIFT)) & UART_USR1_AWAKE_MASK)

#define UART_USR1_AIRINT_MASK                    (0x20U)
#define UART_USR1_AIRINT_SHIFT                   (5U)
/*! AIRINT
 *  0b0..No pulse was detected on the RXD IrDA pin
 *  0b1..A pulse was detected on the RXD IrDA pin
 */
#define UART_USR1_AIRINT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_USR1_AIRINT_SHIFT)) & UART_USR1_AIRINT_MASK)

#define UART_USR1_RXDS_MASK                      (0x40U)
#define UART_USR1_RXDS_SHIFT                     (6U)
/*! RXDS
 *  0b0..Receive in progress
 *  0b1..Receiver is IDLE
 */
#define UART_USR1_RXDS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RXDS_SHIFT)) & UART_USR1_RXDS_MASK)

#define UART_USR1_DTRD_MASK                      (0x80U)
#define UART_USR1_DTRD_SHIFT                     (7U)
#define UART_USR1_DTRD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_DTRD_SHIFT)) & UART_USR1_DTRD_MASK)

#define UART_USR1_AGTIM_MASK                     (0x100U)
#define UART_USR1_AGTIM_SHIFT                    (8U)
/*! AGTIM
 *  0b0..AGTIM is not active
 *  0b1..AGTIM is active (write 1 to clear)
 */
#define UART_USR1_AGTIM(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR1_AGTIM_SHIFT)) & UART_USR1_AGTIM_MASK)

#define UART_USR1_RRDY_MASK                      (0x200U)
#define UART_USR1_RRDY_SHIFT                     (9U)
/*! RRDY
 *  0b0..No character ready
 *  0b1..Character(s) ready (interrupt posted)
 */
#define UART_USR1_RRDY(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RRDY_SHIFT)) & UART_USR1_RRDY_MASK)

#define UART_USR1_FRAMERR_MASK                   (0x400U)
#define UART_USR1_FRAMERR_SHIFT                  (10U)
/*! FRAMERR
 *  0b0..No frame error detected
 *  0b1..Frame error detected (write 1 to clear)
 */
#define UART_USR1_FRAMERR(x)                     (((uint32_t)(((uint32_t)(x)) << UART_USR1_FRAMERR_SHIFT)) & UART_USR1_FRAMERR_MASK)

#define UART_USR1_ESCF_MASK                      (0x800U)
#define UART_USR1_ESCF_SHIFT                     (11U)
/*! ESCF
 *  0b0..No escape sequence detected
 *  0b1..Escape sequence detected (write 1 to clear).
 */
#define UART_USR1_ESCF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_ESCF_SHIFT)) & UART_USR1_ESCF_MASK)

#define UART_USR1_RTSD_MASK                      (0x1000U)
#define UART_USR1_RTSD_SHIFT                     (12U)
/*! RTSD
 *  0b0..RTS_B pin did not change state since last cleared
 *  0b1..RTS_B pin changed state (write 1 to clear)
 */
#define UART_USR1_RTSD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RTSD_SHIFT)) & UART_USR1_RTSD_MASK)

#define UART_USR1_TRDY_MASK                      (0x2000U)
#define UART_USR1_TRDY_SHIFT                     (13U)
/*! TRDY
 *  0b0..The transmitter does not require data
 *  0b1..The transmitter requires data (interrupt posted)
 */
#define UART_USR1_TRDY(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_TRDY_SHIFT)) & UART_USR1_TRDY_MASK)

#define UART_USR1_RTSS_MASK                      (0x4000U)
#define UART_USR1_RTSS_SHIFT                     (14U)
/*! RTSS
 *  0b0..The RTS_B module input is high (inactive)
 *  0b1..The RTS_B module input is low (active)
 */
#define UART_USR1_RTSS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RTSS_SHIFT)) & UART_USR1_RTSS_MASK)

#define UART_USR1_PARITYERR_MASK                 (0x8000U)
#define UART_USR1_PARITYERR_SHIFT                (15U)
/*! PARITYERR
 *  0b0..No parity error detected
 *  0b1..Parity error detected (write 1 to clear)
 */
#define UART_USR1_PARITYERR(x)                   (((uint32_t)(((uint32_t)(x)) << UART_USR1_PARITYERR_SHIFT)) & UART_USR1_PARITYERR_MASK)
/*! @} */

/*! @name USR2 - UART Status Register 2 */
/*! @{ */

#define UART_USR2_RDR_MASK                       (0x1U)
#define UART_USR2_RDR_SHIFT                      (0U)
/*! RDR
 *  0b0..No receive data ready
 *  0b1..Receive data ready
 */
#define UART_USR2_RDR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR2_RDR_SHIFT)) & UART_USR2_RDR_MASK)

#define UART_USR2_ORE_MASK                       (0x2U)
#define UART_USR2_ORE_SHIFT                      (1U)
/*! ORE
 *  0b0..No overrun error
 *  0b1..Overrun error (write 1 to clear)
 */
#define UART_USR2_ORE(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR2_ORE_SHIFT)) & UART_USR2_ORE_MASK)

#define UART_USR2_BRCD_MASK                      (0x4U)
#define UART_USR2_BRCD_SHIFT                     (2U)
/*! BRCD
 *  0b0..No BREAK condition was detected
 *  0b1..A BREAK condition was detected (write 1 to clear)
 */
#define UART_USR2_BRCD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_BRCD_SHIFT)) & UART_USR2_BRCD_MASK)

#define UART_USR2_TXDC_MASK                      (0x8U)
#define UART_USR2_TXDC_SHIFT                     (3U)
/*! TXDC
 *  0b0..Transmit is incomplete
 *  0b1..Transmit is complete
 */
#define UART_USR2_TXDC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_TXDC_SHIFT)) & UART_USR2_TXDC_MASK)

#define UART_USR2_RTSF_MASK                      (0x10U)
#define UART_USR2_RTSF_SHIFT                     (4U)
/*! RTSF
 *  0b0..Programmed edge not detected on RTS_B
 *  0b1..Programmed edge detected on RTS_B (write 1 to clear)
 */
#define UART_USR2_RTSF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_RTSF_SHIFT)) & UART_USR2_RTSF_MASK)

#define UART_USR2_DCDIN_MASK                     (0x20U)
#define UART_USR2_DCDIN_SHIFT                    (5U)
#define UART_USR2_DCDIN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR2_DCDIN_SHIFT)) & UART_USR2_DCDIN_MASK)

#define UART_USR2_DCDDELT_MASK                   (0x40U)
#define UART_USR2_DCDDELT_SHIFT                  (6U)
#define UART_USR2_DCDDELT(x)                     (((uint32_t)(((uint32_t)(x)) << UART_USR2_DCDDELT_SHIFT)) & UART_USR2_DCDDELT_MASK)

#define UART_USR2_WAKE_MASK                      (0x80U)
#define UART_USR2_WAKE_SHIFT                     (7U)
/*! WAKE
 *  0b0..start bit not detected
 *  0b1..start bit detected (write 1 to clear)
 */
#define UART_USR2_WAKE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_WAKE_SHIFT)) & UART_USR2_WAKE_MASK)

#define UART_USR2_IRINT_MASK                     (0x100U)
#define UART_USR2_IRINT_SHIFT                    (8U)
/*! IRINT
 *  0b0..no edge detected
 *  0b1..valid edge detected (write 1 to clear)
 */
#define UART_USR2_IRINT(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR2_IRINT_SHIFT)) & UART_USR2_IRINT_MASK)

#define UART_USR2_RIIN_MASK                      (0x200U)
#define UART_USR2_RIIN_SHIFT                     (9U)
#define UART_USR2_RIIN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_RIIN_SHIFT)) & UART_USR2_RIIN_MASK)

#define UART_USR2_RIDELT_MASK                    (0x400U)
#define UART_USR2_RIDELT_SHIFT                   (10U)
#define UART_USR2_RIDELT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_USR2_RIDELT_SHIFT)) & UART_USR2_RIDELT_MASK)

#define UART_USR2_ACST_MASK                      (0x800U)
#define UART_USR2_ACST_SHIFT                     (11U)
/*! ACST
 *  0b0..Measurement of bit length not finished (in autobaud)
 *  0b1..Measurement of bit length finished (in autobaud). (write 1 to clear)
 */
#define UART_USR2_ACST(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_ACST_SHIFT)) & UART_USR2_ACST_MASK)

#define UART_USR2_IDLE_MASK                      (0x1000U)
#define UART_USR2_IDLE_SHIFT                     (12U)
/*! IDLE
 *  0b0..No idle condition detected
 *  0b1..Idle condition detected (write 1 to clear)
 */
#define UART_USR2_IDLE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_IDLE_SHIFT)) & UART_USR2_IDLE_MASK)

#define UART_USR2_DTRF_MASK                      (0x2000U)
#define UART_USR2_DTRF_SHIFT                     (13U)
#define UART_USR2_DTRF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_DTRF_SHIFT)) & UART_USR2_DTRF_MASK)

#define UART_USR2_TXFE_MASK                      (0x4000U)
#define UART_USR2_TXFE_SHIFT                     (14U)
/*! TXFE
 *  0b0..The transmit buffer (TxFIFO) is not empty
 *  0b1..The transmit buffer (TxFIFO) is empty
 */
#define UART_USR2_TXFE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_TXFE_SHIFT)) & UART_USR2_TXFE_MASK)

#define UART_USR2_ADET_MASK                      (0x8000U)
#define UART_USR2_ADET_SHIFT                     (15U)
/*! ADET
 *  0b0..ASCII "A" or "a" was not received
 *  0b1..ASCII "A" or "a" was received (write 1 to clear)
 */
#define UART_USR2_ADET(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_ADET_SHIFT)) & UART_USR2_ADET_MASK)
/*! @} */

/*! @name UESC - UART Escape Character Register */
/*! @{ */

#define UART_UESC_ESC_CHAR_MASK                  (0xFFU)
#define UART_UESC_ESC_CHAR_SHIFT                 (0U)
#define UART_UESC_ESC_CHAR(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UESC_ESC_CHAR_SHIFT)) & UART_UESC_ESC_CHAR_MASK)
/*! @} */

/*! @name UTIM - UART Escape Timer Register */
/*! @{ */

#define UART_UTIM_TIM_MASK                       (0xFFFU)
#define UART_UTIM_TIM_SHIFT                      (0U)
#define UART_UTIM_TIM(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UTIM_TIM_SHIFT)) & UART_UTIM_TIM_MASK)
/*! @} */

/*! @name UBIR - UART BRM Incremental Register */
/*! @{ */

#define UART_UBIR_INC_MASK                       (0xFFFFU)
#define UART_UBIR_INC_SHIFT                      (0U)
#define UART_UBIR_INC(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UBIR_INC_SHIFT)) & UART_UBIR_INC_MASK)
/*! @} */

/*! @name UBMR - UART BRM Modulator Register */
/*! @{ */

#define UART_UBMR_MOD_MASK                       (0xFFFFU)
#define UART_UBMR_MOD_SHIFT                      (0U)
#define UART_UBMR_MOD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UBMR_MOD_SHIFT)) & UART_UBMR_MOD_MASK)
/*! @} */

/*! @name UBRC - UART Baud Rate Count Register */
/*! @{ */

#define UART_UBRC_BCNT_MASK                      (0xFFFFU)
#define UART_UBRC_BCNT_SHIFT                     (0U)
#define UART_UBRC_BCNT(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UBRC_BCNT_SHIFT)) & UART_UBRC_BCNT_MASK)
/*! @} */

/*! @name ONEMS - UART One Millisecond Register */
/*! @{ */

#define UART_ONEMS_ONEMS_MASK                    (0xFFFFFFU)
#define UART_ONEMS_ONEMS_SHIFT                   (0U)
#define UART_ONEMS_ONEMS(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ONEMS_ONEMS_SHIFT)) & UART_ONEMS_ONEMS_MASK)
/*! @} */

/*! @name UTS - UART Test Register */
/*! @{ */

#define UART_UTS_SOFTRST_MASK                    (0x1U)
#define UART_UTS_SOFTRST_SHIFT                   (0U)
/*! SOFTRST
 *  0b0..Software reset inactive
 *  0b1..Software reset active
 */
#define UART_UTS_SOFTRST(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_SOFTRST_SHIFT)) & UART_UTS_SOFTRST_MASK)

#define UART_UTS_RXFULL_MASK                     (0x8U)
#define UART_UTS_RXFULL_SHIFT                    (3U)
/*! RXFULL
 *  0b0..The RxFIFO is not full
 *  0b1..The RxFIFO is full
 */
#define UART_UTS_RXFULL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXFULL_SHIFT)) & UART_UTS_RXFULL_MASK)

#define UART_UTS_TXFULL_MASK                     (0x10U)
#define UART_UTS_TXFULL_SHIFT                    (4U)
/*! TXFULL
 *  0b0..The TxFIFO is not full
 *  0b1..The TxFIFO is full
 */
#define UART_UTS_TXFULL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_TXFULL_SHIFT)) & UART_UTS_TXFULL_MASK)

#define UART_UTS_RXEMPTY_MASK                    (0x20U)
#define UART_UTS_RXEMPTY_SHIFT                   (5U)
/*! RXEMPTY
 *  0b0..The RxFIFO is not empty
 *  0b1..The RxFIFO is empty
 */
#define UART_UTS_RXEMPTY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXEMPTY_SHIFT)) & UART_UTS_RXEMPTY_MASK)

#define UART_UTS_TXEMPTY_MASK                    (0x40U)
#define UART_UTS_TXEMPTY_SHIFT                   (6U)
/*! TXEMPTY
 *  0b0..The TxFIFO is not empty
 *  0b1..The TxFIFO is empty
 */
#define UART_UTS_TXEMPTY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_TXEMPTY_SHIFT)) & UART_UTS_TXEMPTY_MASK)

#define UART_UTS_RXDBG_MASK                      (0x200U)
#define UART_UTS_RXDBG_SHIFT                     (9U)
/*! RXDBG
 *  0b0..rx fifo read pointer does not increment
 *  0b1..rx_fifo read pointer increments as normal
 */
#define UART_UTS_RXDBG(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXDBG_SHIFT)) & UART_UTS_RXDBG_MASK)

#define UART_UTS_LOOPIR_MASK                     (0x400U)
#define UART_UTS_LOOPIR_SHIFT                    (10U)
/*! LOOPIR
 *  0b0..No IR loop
 *  0b1..Connect IR transmitter to IR receiver
 */
#define UART_UTS_LOOPIR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_LOOPIR_SHIFT)) & UART_UTS_LOOPIR_MASK)

#define UART_UTS_DBGEN_MASK                      (0x800U)
#define UART_UTS_DBGEN_SHIFT                     (11U)
/*! DBGEN
 *  0b0..UART will go into debug mode when debug_req is HIGH
 *  0b1..UART will not go into debug mode even if debug_req is HIGH
 */
#define UART_UTS_DBGEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UTS_DBGEN_SHIFT)) & UART_UTS_DBGEN_MASK)

#define UART_UTS_LOOP_MASK                       (0x1000U)
#define UART_UTS_LOOP_SHIFT                      (12U)
/*! LOOP
 *  0b0..Normal receiver operation
 *  0b1..Internally connect the transmitter output to the receiver input
 */
#define UART_UTS_LOOP(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UTS_LOOP_SHIFT)) & UART_UTS_LOOP_MASK)

#define UART_UTS_FRCPERR_MASK                    (0x2000U)
#define UART_UTS_FRCPERR_SHIFT                   (13U)
/*! FRCPERR
 *  0b0..Generate normal parity
 *  0b1..Generate inverted parity (error)
 */
#define UART_UTS_FRCPERR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_FRCPERR_SHIFT)) & UART_UTS_FRCPERR_MASK)
/*! @} */

/*! @name UMCR - UART RS-485 Mode Control Register */
/*! @{ */

#define UART_UMCR_MDEN_MASK                      (0x1U)
#define UART_UMCR_MDEN_SHIFT                     (0U)
/*! MDEN
 *  0b0..Normal RS-232 or IrDA mode, see for detail.
 *  0b1..Enable RS-485 mode, see for detail
 */
#define UART_UMCR_MDEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_MDEN_SHIFT)) & UART_UMCR_MDEN_MASK)

#define UART_UMCR_SLAM_MASK                      (0x2U)
#define UART_UMCR_SLAM_SHIFT                     (1U)
/*! SLAM
 *  0b0..Select Normal Address Detect mode
 *  0b1..Select Automatic Address Detect mode
 */
#define UART_UMCR_SLAM(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SLAM_SHIFT)) & UART_UMCR_SLAM_MASK)

#define UART_UMCR_TXB8_MASK                      (0x4U)
#define UART_UMCR_TXB8_SHIFT                     (2U)
/*! TXB8
 *  0b0..0 will be transmitted as the RS485 9th data bit
 *  0b1..1 will be transmitted as the RS485 9th data bit
 */
#define UART_UMCR_TXB8(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_TXB8_SHIFT)) & UART_UMCR_TXB8_MASK)

#define UART_UMCR_SADEN_MASK                     (0x8U)
#define UART_UMCR_SADEN_SHIFT                    (3U)
/*! SADEN
 *  0b0..Disable RS-485 Slave Address Detected Interrupt
 *  0b1..Enable RS-485 Slave Address Detected Interrupt
 */
#define UART_UMCR_SADEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SADEN_SHIFT)) & UART_UMCR_SADEN_MASK)

#define UART_UMCR_SLADDR_MASK                    (0xFF00U)
#define UART_UMCR_SLADDR_SHIFT                   (8U)
#define UART_UMCR_SLADDR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SLADDR_SHIFT)) & UART_UMCR_SLADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x30860000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x30890000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Peripheral UART3 base address */
#define UART3_BASE                               (0x30880000u)
/** Peripheral UART3 base pointer */
#define UART3                                    ((UART_Type *)UART3_BASE)
/** Peripheral UART4 base address */
#define UART4_BASE                               (0x30A60000u)
/** Peripheral UART4 base pointer */
#define UART4                                    ((UART_Type *)UART4_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { 0u, UART1_BASE, UART2_BASE, UART3_BASE, UART4_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { (UART_Type *)0u, UART1, UART2, UART3, UART4 }
/** Interrupt vectors for the UART peripheral type */
#define UART_IRQS                                { NotAvail_IRQn, UART1_IRQn, UART2_IRQn, UART3_IRQn, UART4_IRQn }

/* IUART module features */

/** UART Transmit/Receive FIFO Size */
#define FSL_FEATURE_IUART_FIFO_SIZEn(x) (32)

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */

#endif  /* _NXP_IMX8M_H_ */

