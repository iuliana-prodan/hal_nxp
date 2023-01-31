/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_common.h"
#include "fsl_clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

#define FracPLL_GNRL_CTL_Offset  (0U)
#define FracPLL_FDIV_CTL0_Offset (4U)
#define FracPLL_FDIV_CTL1_Offset (8U)

#define IntegerPLL_GNRL_CTL_Offset (0U)
#define IntegerPLL_DIV_CTL_Offset  (4U)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Gets the clock frequency for a specific clock name.
 *
 * This function checks the current clock configurations and then calculates
 * the clock frequency for a specific clock name defined in clock_name_t.
 *
 * param clockName Clock names defined in clock_name_t
 * return Clock frequency value in hertz
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq;

    switch (clockName)
    {
        case kCLOCK_Osc24MClk:
            freq = OSC24M_CLK_FREQ;
            break;
        case kCLOCK_ArmPllClk:
            freq = CLOCK_GetPllFreq(kCLOCK_ArmPllCtrl);
            break;
        case kCLOCK_DramPllClk:
            freq = CLOCK_GetPllFreq(kCLOCK_DramPllCtrl);
            break;
        case kCLOCK_VpuPllClk:
            freq = CLOCK_GetPllFreq(kCLOCK_VpuPllCtrl);
            break;
        case kCLOCK_SysPll1Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl);
            break;
        case kCLOCK_SysPll1Div2Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 2U;
            break;
        case kCLOCK_SysPll1Div3Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 3U;
            break;
        case kCLOCK_SysPll1Div4Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 4U;
            break;
        case kCLOCK_SysPll1Div5Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 5U;
            break;
        case kCLOCK_SysPll1Div6Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 6U;
            break;
        case kCLOCK_SysPll1Div8Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 8U;
            break;
        case kCLOCK_SysPll1Div10Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 10U;
            break;
        case kCLOCK_SysPll1Div20Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 20U;
            break;
        case kCLOCK_SysPll2Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl);
            break;
        case kCLOCK_SysPll2Div2Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 2U;
            break;
        case kCLOCK_SysPll2Div3Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 3U;
            break;
        case kCLOCK_SysPll2Div4Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 4U;
            break;
        case kCLOCK_SysPll2Div5Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 5U;
            break;
        case kCLOCK_SysPll2Div6Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 6U;
            break;
        case kCLOCK_SysPll2Div8Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 8U;
            break;
        case kCLOCK_SysPll2Div10Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 10U;
            break;
        case kCLOCK_SysPll2Div20Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 20U;
            break;
        case kCLOCK_SysPll3Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll3Ctrl);
            break;
        case kCLOCK_AudioPll1Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_AudioPll1Ctrl);
            break;
        case kCLOCK_AudioPll2Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_AudioPll2Ctrl);
            break;
        case kCLOCK_VideoPll1Clk:
            freq = CLOCK_GetPllFreq(kCLOCK_VideoPll1Ctrl);
            break;
        case kCLOCK_ExtClk1:
        case kCLOCK_ExtClk2:
        case kCLOCK_ExtClk3:
        case kCLOCK_ExtClk4:
            freq = CLKPAD_FREQ;
            break;
        default:
            freq = 0U;
            break;
    }
    return freq;
}

/*!
 * brief Gets the frequency of selected clock root.
 *
 * param clockRoot The clock root used to get the frequency, please refer to @ref clock_root_t.
 * return The frequency of selected clock root.
 */
uint32_t CLOCK_GetClockRootFreq(clock_root_t clockRoot)
{
    static const clock_name_t clockRootSourceArray[][8]          = CLOCK_ROOT_SOURCE;
    static const clock_root_control_t clockRootControlArray[]    = CLOCK_ROOT_CONTROL_TUPLE;

    clock_root_control_t clockRootControl                        = clockRootControlArray[(uint8_t)clockRoot];

    uint32_t freq = 0U;
    uint32_t pre  = CLOCK_GetRootPreDivider(clockRootControl);
    uint32_t post = CLOCK_GetRootPostDivider(clockRootControl);
    uint32_t mux = CLOCK_GetRootMux(clockRootControl);

    clock_name_t clockSourceName;

    clockSourceName = clockRootSourceArray[(uint8_t)clockRoot][mux];

    assert(clockSourceName != kCLOCK_NoneName);

    freq = CLOCK_GetFreq(clockSourceName);

    if (clockRoot == kCLOCK_IpgClkRoot)
    {
        freq /= CLOCK_GetRootPostDivider(kCLOCK_RootIpg);
    }
    if (clockRoot == kCLOCK_AudioIpgClkRoot)
    {
        freq /= CLOCK_GetRootPostDivider(kCLOCK_RootAudioIpg);
    }

    return freq / pre / post;
}

/*!
 * brief Gets PLL reference clock frequency.
 *
 * param type fractional pll type.

 * return  Clock frequency
 */
uint32_t CLOCK_GetPllRefClkFreq(clock_pll_ctrl_t ctrl)
{
    uint32_t refClkFreq = 0U;
    uint8_t clkSel      = 0U;

    if (ctrl < kCLOCK_ArmPllCtrl)
    {
        clkSel =
            (uint8_t)((CCM_ANALOG_TUPLE_REG(CCM_ANALOG, ctrl) & CCM_ANALOG_AUDIO_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK));
    }
    else
    {
        clkSel = (uint8_t)(CCM_ANALOG_TUPLE_REG(CCM_ANALOG, ctrl) & CCM_ANALOG_SYS_PLL1_GEN_CTRL_PLL_REF_CLK_SEL_MASK);
    }

    switch (clkSel)
    {
        case kANALOG_PllRefOsc24M:
            refClkFreq = OSC24M_CLK_FREQ;
            break;

        case kANALOG_PllPadClk:
            /* The value of PAD CLK need user to define according to the actual condition. */
            refClkFreq = CLKPAD_FREQ;
            break;

        default:
            refClkFreq = 0U;
            break;
    }

    return refClkFreq;
}

/*!
 * brief Gets PLL clock frequency.
 *
 * param type fractional pll type.

 * return  Clock frequency
 */
uint32_t CLOCK_GetPllFreq(clock_pll_ctrl_t pll)
{
    uint32_t pllFreq       = 0U;
    uint32_t pllRefFreq    = 0U;
    bool intergerPllBypass = false;
    bool fracPllBypass     = false;

    pllRefFreq = CLOCK_GetPllRefClkFreq(pll);

    switch (pll)
    {
        /* Integer PLL frequency */
        case kCLOCK_ArmPllCtrl:
            intergerPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_ArmPllPwrBypassCtrl);
            break;
        case kCLOCK_SystemPll1Ctrl:
            intergerPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll1InternalPll1BypassCtrl);
            break;
        case kCLOCK_SystemPll2Ctrl:
            intergerPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll2InternalPll1BypassCtrl);
            break;
        case kCLOCK_SystemPll3Ctrl:
            intergerPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll3InternalPll1BypassCtrl);
            break;
        /* Fractional PLL frequency */
        case kCLOCK_AudioPll1Ctrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_AudioPll1BypassCtrl);
            break;
        case kCLOCK_AudioPll2Ctrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_AudioPll2BypassCtrl);
            break;
        case kCLOCK_VideoPll1Ctrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_VideoPll1BypassCtrl);
            break;
        case kCLOCK_DramPllCtrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_DramPllInternalPll1BypassCtrl);
            break;
        default:
            fracPllBypass = false;
            break;
    }
    if (pll < kCLOCK_ArmPllCtrl)
    {
        if (fracPllBypass)
        {
            pllFreq = pllRefFreq;
        }
        else
        {
            pllFreq = CLOCK_GetFracPllFreq(CCM_ANALOG, pll, pllRefFreq);
        }
    }
    else
    {
        if (intergerPllBypass)
        {
            /* if PLL is bypass, return reference clock directly */
            pllFreq = pllRefFreq;
        }
        else
        {
            pllFreq = CLOCK_GetIntegerPllFreq(CCM_ANALOG, pll, pllRefFreq, false);
        }
    }

    return (uint32_t)pllFreq;
}

/*!
 * brief Gets the ANALOG Fractional PLL clock frequency.
 *
 * param base CCM_ANALOG base pointer.
 * param type fractional pll type.
 * param fractional pll reference clock frequency
 *
 * return  Clock frequency
 */
uint32_t CLOCK_GetFracPllFreq(CCM_ANALOG_Type *base, clock_pll_ctrl_t type, uint32_t refClkFreq)
{
    assert(type < kCLOCK_ArmPllCtrl);

    uint32_t fracCfg1 = CCM_ANALOG_TUPLE_REG_OFF(base, type, FracPLL_FDIV_CTL0_Offset);
    uint32_t fracCfg2 = CCM_ANALOG_TUPLE_REG_OFF(base, type, FracPLL_FDIV_CTL1_Offset);
    uint64_t fracClk  = 0U;

    uint32_t mainDiv = CCM_BIT_FIELD_EXTRACTION(fracCfg1, CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK,
                                                CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT);
    uint8_t preDiv   = (uint8_t)CCM_BIT_FIELD_EXTRACTION(fracCfg1, CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK,
                                                       CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT);
    uint8_t postDiv  = (uint8_t)CCM_BIT_FIELD_EXTRACTION(fracCfg1, CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK,
                                                        CCM_ANALOG_AUDIO_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT);
    uint32_t dsm     = CCM_BIT_FIELD_EXTRACTION(fracCfg2, CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM_MASK,
                                            CCM_ANALOG_AUDIO_PLL1_FDIV_CTL1_PLL_DSM_SHIFT);

    fracClk = (uint64_t)((uint64_t)refClkFreq * ((uint64_t)mainDiv * 65536ULL + dsm) /
                         (65536ULL * (uint32_t)preDiv * (1ULL << postDiv)));

    return (uint32_t)fracClk;
}

/*!
 * brief Get the ANALOG Integer PLL clock frequency.
 *
 * param base CCM ANALOG base address.
 * param type integer pll type
 * param pll1Bypass pll1 bypass flag
 *
 * return  Clock frequency
 */
uint32_t CLOCK_GetIntegerPllFreq(CCM_ANALOG_Type *base, clock_pll_ctrl_t type, uint32_t refClkFreq, bool pll1Bypass)
{
    assert(type >= kCLOCK_SystemPll1Ctrl);

    uint32_t integerCfg1 = CCM_ANALOG_TUPLE_REG_OFF(base, type, IntegerPLL_DIV_CTL_Offset);
    uint64_t pllOutClock = 0U;

    uint32_t mainDiv = CCM_BIT_FIELD_EXTRACTION(integerCfg1, CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV_MASK,
                                                CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_MAIN_DIV_SHIFT);
    uint8_t preDiv   = (uint8_t)CCM_BIT_FIELD_EXTRACTION(integerCfg1, CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV_MASK,
                                                       CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_PRE_DIV_SHIFT);
    uint8_t postDiv  = (uint8_t)CCM_BIT_FIELD_EXTRACTION(integerCfg1, CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV_MASK,
                                                        CCM_ANALOG_SYS_PLL1_FDIV_CTL0_PLL_POST_DIV_SHIFT);

    if (pll1Bypass)
    {
        pllOutClock = refClkFreq;
    }

    else
    {
        pllOutClock = (uint64_t)refClkFreq * mainDiv / (((uint64_t)(1U) << postDiv) * preDiv);
    }

    return (uint32_t)pllOutClock;
}

/*!
 * brief Enable CCGR clock gate and root clock gate for each module
 * User should set specific gate for each module according to the description
 * of the table of system clocks, gating and override in CCM chapter of
 * reference manual. Take care of that one module may need to set more than
 * one clock gate.
 *
 * param ccmGate Gate control for each module (see ref clock_ip_name_t enumeration).
 */
void CLOCK_EnableClock(clock_ip_name_t ccmGate)
{
    uint32_t ccgr      = CCM_TUPLE_CCGR(ccmGate);
    uint32_t rootClk   = 0U;

    CCM_REG_SET(ccgr) = (uint32_t)kCLOCK_ClockNeededAll;
    rootClk           = CCM_TUPLE_ROOT(ccmGate);


    /* if root clock is 0xFFFFU, then skip enable root clock */
    if (rootClk != 0xFFFFU)
    {
        CCM_REG_SET(rootClk) = CCM_TARGET_ROOT_SET_ENABLE_MASK;
    }
}

/*!
 * brief Disable CCGR clock gate for the each module
 * User should set specific gate for each module according to the description
 * of the table of system clocks, gating and override in CCM chapter of
 * reference manual. Take care of that one module may need to set more than
 * one clock gate.
 *
 * param ccmGate Gate control for each module (see ref clock_ip_name_t enumeration).
 */
void CLOCK_DisableClock(clock_ip_name_t ccmGate)
{
    uint32_t ccgr      = CCM_TUPLE_CCGR(ccmGate);
    uint32_t rootClk   = 0U;

    CCM_REG(ccgr) = (uint32_t)kCLOCK_ClockNotNeeded;
    rootClk       = CCM_TUPLE_ROOT(ccmGate);

    /* if root clock is 0xFFFFU, then skip disable root clock */
    if (rootClk != 0xFFFFU)
    {
        CCM_REG_CLR(rootClk) = CCM_TARGET_ROOT_CLR_ENABLE_MASK;
    }
}
