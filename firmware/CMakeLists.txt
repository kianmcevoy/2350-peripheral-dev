# Cmake version
cmake_minimum_required(VERSION 3.13)

# Set board and environment variables before including Pico SDK
set(ENV{PICO_SDK_FETCH_FROM_GIT} 1)
set(ENV{PICO_EXTRAS_FETCH_FROM_GIT} 1)
set(PICO_BOARD solderparty_rp2350_stamp_xl)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(system/pico_sdk_import.cmake)

project(
    # Project name
    peripheral-dev

    # Version number
    VERSION 0.0.1

    # Enable languages
    LANGUAGES C CXX ASM
)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Instrument directory
set(INSTRUMENT_DIR ${PROJECT_SOURCE_DIR}/instrument)
# Hardware directory
set(HARDWARE_DIR ${PROJECT_SOURCE_DIR}/hardware)
# System directory
set(SYSTEM_DIR ${PROJECT_SOURCE_DIR}/system)
# Interface directory
set(INTERFACE_DIR ${PROJECT_SOURCE_DIR}/interface)
# Processor directory
set(ENGINE_DIR ${PROJECT_SOURCE_DIR}/engine)
# Shared directory
set(SHARED_FILES_DIR ${PROJECT_SOURCE_DIR}/../shared)
# ISL directory
set(ISL_DIR ${SHARED_FILES_DIR}/isl)

# Collect all source files
file(GLOB TARGET_SRCS
    # Project Sources
    ${SYSTEM_DIR}/src/*.cpp
    ${INSTRUMENT_DIR}/src/*.cpp
    ${INTERFACE_DIR}/src/*.cpp
    ${HARDWARE_DIR}/src/*.cpp
    ${ENGINE_DIR}/src/*.cpp
)

# Create the executable target
add_executable(${TARGET_NAME} ${TARGET_SRCS})

# Configure Pico-specific settings
pico_set_program_name(${TARGET_NAME} "template")
pico_set_program_version(${TARGET_NAME} "0.1")

pico_enable_stdio_uart(${TARGET_NAME} 0)
pico_enable_stdio_usb(${TARGET_NAME} 1)
pico_enable_stdio_rtt(${TARGET_NAME} 1)
pico_enable_stdio_semihosting(${TARGET_NAME} 1)

# Include directories
target_include_directories(${TARGET_NAME} PRIVATE
    # Project include
    ${SYSTEM_DIR}/include
    ${INSTRUMENT_DIR}/include
    ${INTERFACE_DIR}/include
    ${HARDWARE_DIR}/include
    ${ENGINE_DIR}/include
    ${ISL_DIR}/include
)

# Link libraries
target_link_libraries(${TARGET_NAME}
    pico_stdlib
    hardware_i2c
    hardware_dma
    hardware_pio
    hardware_clocks
    hardware_adc
    hardware_timer
    hardware_pll
    hardware_vreg
)

# Compile definitions
target_compile_definitions(${TARGET_NAME} PUBLIC
    Sample=float
    SYSTEM_RP2350=1
)

# Set NDEBUG for release builds (enables automatic log level detection)
target_compile_definitions(${TARGET_NAME} PUBLIC
    $<$<CONFIG:Release>:NDEBUG>
)

# Compile options
target_compile_options(${TARGET_NAME} PRIVATE 
    -w 
    -Og 
    -Wall
)

# Generate additional output files
pico_add_extra_outputs(${TARGET_NAME})


