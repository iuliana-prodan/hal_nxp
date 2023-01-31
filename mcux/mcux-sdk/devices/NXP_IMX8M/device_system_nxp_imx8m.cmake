#Description: device_system; user_visible: False
include_guard(GLOBAL)
message("device_system component is included.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)
