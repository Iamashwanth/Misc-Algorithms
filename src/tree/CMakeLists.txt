cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
include_directories("$(CMAKE_CURRENT_SOURCE_DIR)")

file(GLOB TREE_SRCS tree_util.cpp tree.h)

add_library(libtree STATIC ${TREE_SRCS})

target_include_directories(libtree PUBLIC
			   ${CMAKE_CURRENT_SOURCE_DIR})
