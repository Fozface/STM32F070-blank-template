cmake_minimum_required(VERSION 3.20)
project(STM32F070F6P C ASM)

# ---- CMSIS (MUST be F0, not F4) ----
set(CMSIS_ROOT "C:/Users/tfaty/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.6/Drivers/CMSIS")

add_executable(${PROJECT_NAME}.elf)

# ---- CPU flags (Cortex-M0 → NO FPU) ----
set(MCPU_FLAGS
  -mcpu=cortex-m0
  -mthumb
)

# ---- MCU define ----
target_compile_definitions(${PROJECT_NAME}.elf PRIVATE
  STM32F070xx
)

# ---- Includes ----
target_include_directories(${PROJECT_NAME}.elf PRIVATE
  ${CMAKE_SOURCE_DIR}/Inc
  ${CMSIS_ROOT}/Include
  ${CMSIS_ROOT}/Device/ST/STM32F0xx/Include
)

# ---- Sources (DEFINE BEFORE target_sources) ----
file(GLOB SRC_C
  ${CMAKE_SOURCE_DIR}/Src/*.c
  ${CMSIS_ROOT}/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c
)

file(GLOB STARTUP
  ${CMAKE_SOURCE_DIR}/Startup/*.s
  ${CMAKE_SOURCE_DIR}/Startup/*.S
)

target_sources(${PROJECT_NAME}.elf PRIVATE
  ${SRC_C}
  ${STARTUP}
)

# ---- Compile options ----
target_compile_options(${PROJECT_NAME}.elf PRIVATE
  ${MCPU_FLAGS}
  -ffunction-sections
  -fdata-sections
  -fno-builtin
  -Wall -Wextra
  $<$<CONFIG:Debug>:-Og;-g3>
  $<$<CONFIG:Release>:-O2>
)

# ---- Linker ----
target_link_options(${PROJECT_NAME}.elf PRIVATE
  ${MCPU_FLAGS}
  -Wl,--gc-sections
  -Wl,-Map=${PROJECT_NAME}.map
  -Wl,--print-memory-usage
  --specs=nosys.specs
  -T${CMAKE_SOURCE_DIR}/STM32F070F6PX_FLASH.ld
)

# ---- Post build ----
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.hex
  COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.bin
  COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}.elf>
)
