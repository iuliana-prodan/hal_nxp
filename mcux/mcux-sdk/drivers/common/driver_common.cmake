#Description: Common Driver; user_visible: True
include_guard(GLOBAL)
message("driver_common component is included.")

#Include core specific common file
set(SPECIFIC_COMMON_FILE "fsl_common_arm.c")
if(CONFIG_SOC_FAMILY_NXP_ADSP)
    set(SPECIFIC_COMMON_FILE "fsl_common_dsp.c")
endif()

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_common.c
    ${CMAKE_CURRENT_LIST_DIR}/${SPECIFIC_COMMON_FILE}
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

include(driver_reset)

#CMSIS is not needed for Audio DSP
if(NOT CONFIG_SOC_FAMILY_NXP_ADSP)
    include(device_CMSIS)
endif()
