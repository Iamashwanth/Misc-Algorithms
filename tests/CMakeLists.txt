cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

file(GLOB TEST_SRCS *.cpp)

add_library(libtest STATIC ${TEST_SRCS})

target_link_libraries(libtest libcode)

target_include_directories(libtest PUBLIC
			   ${CMAKE_CURRENT_SOURCE_DIR})
