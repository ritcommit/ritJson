cmake_minimum_required(VERSION 3.0)
project(ritJson C)

set(CMAKE_C_STANDARD_REQUIRED ON)

# Add the executable
# Gather all .c sources from the ritJson and example folders
file(GLOB RITJSON_SRC "${CMAKE_SOURCE_DIR}/ritJson/*.c")
file(GLOB EXAMPLE_SRC "${CMAKE_SOURCE_DIR}/example/*.c")
set(SRC_FILES ${RITJSON_SRC} ${EXAMPLE_SRC})
set(INC_DIR ${CMAKE_SOURCE_DIR}/ritJson)

# include paths
include_directories(${INC_DIR})

# executable
add_executable(ritJson ${SRC_FILES})