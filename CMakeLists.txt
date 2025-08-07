cmake_minimum_required(VERSION 3.10)

project(c_extension C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
aux_source_directory(src CEX_SRC)

set(ORIGINAL_STATIC_LIB_NAME ${PROJECT_NAME}-static)

add_library(${PROJECT_NAME} SHARED ${CEX_SRC})
add_library(${ORIGINAL_STATIC_LIB_NAME} STATIC $<TARGET_OBJECTS:${PROJECT_NAME}>)

set_target_properties(${ORIGINAL_STATIC_LIB_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})