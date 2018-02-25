cmake_minimum_required (VERSION 3.0)

include_directories("$(CMAKE_CURRENT_SOURCE_DIR)/inc")

file(GLOB SOURCES */*.cpp)

add_library(libcode STATIC ${SOURCES})

target_include_directories(libcode PUBLIC
			   ${CMAKE_CURRENT_SOURCE_DIR}/inc)
