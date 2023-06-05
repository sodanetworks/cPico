cmake_minimum_required(VERSION 3.13)

set(PROGRAM_NAME tcpTemp)
# Set pico board
set(PICO_BOARD pico_w)
# Set the C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(${PROGRAM_NAME} C CXX ASM)


# Include the lwIP headers
# include_directories(
#     ${PICO_SDK_PATH}/lib/tinyusb/src/portable/nxp/rp2040
#     ${PICO_SDK_PATH}/lib/tinyusb/src/portable/nxp/rp2040/device
#     ${PICO_SDK_PATH}/lib/tinyusb/src/portable/nxp/rp2040/device/usb_descriptors
#     ${PICO_SDK_PATH}/lib/tinyusb/src/class/cdc
#     ${PICO_SDK_PATH}/lib/tinyusb/src
#     ${PICO_SDK_PATH}/lib/lwip/src/include
#     ${PICO_SDK_PATH}/lib/lwip/src/include/ipv4
#     ${PICO_SDK_PATH}/lib/lwip/src/include/ipv6
#     ${PICO_SDK_PATH}/lib/lwip/src/include/netif
#     ${PICO_SDK_PATH}/lib/lwip/src/include/lwip
#     ${PICO_SDK_PATH}/src/rp2_common/pico_lwip/include/
#     ${PICO_SDK_PATH}/src/rp2_common/pico_base/include/arch
# )


pico_sdk_init()

# message("Running makefsdata python script")
# execute_process(COMMAND
#     py makefsdata.py
#     WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
# )

add_executable(${PROGRAM_NAME}
    main.c
    # tempsender.cpp
)

target_include_directories(${PROGRAM_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
)

target_link_libraries(${PROGRAM_NAME}
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background
)

pico_enable_stdio_usb(${PROGRAM_NAME} TRUE)
pico_enable_stdio_uart(${PROGRAM_NAME} FALSE)

pico_add_extra_outputs(${PROGRAM_NAME})

# Add extra flags for lwIP compilation
# target_compile_definitions(${PROJECT_NAME} PRIVATE PICO_HAVE_LWIP lwip)