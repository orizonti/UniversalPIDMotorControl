cmake_minimum_required(VERSION 3.20)

project("G431CBU_CONTROL_PROJECT" C CXX ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/st-project.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties(${PROJECT_NAME})

include_directories("${PROJECT_SOURCE_DIR}/Drivers/ETHERNET")
include_directories("C:/HEADERS/STM32_HEADERS")
message("${PROJECT_SOURCE_DIR}/Drivers/ETHERNET")