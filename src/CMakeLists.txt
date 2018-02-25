cmake_minimum_required (VERSION 3.0)

project (Misc-Algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories("$(CMAKE_CURRENT_SOURCE_DIR)")
include_directories("$(CMAKE_CURRENT_SOURCE_DIR)/tests/")

file(GLOB
     SOURCES
     main.cpp *.h test/*.h
     )

add_subdirectory(tests)
add_subdirectory(tree)

add_executable(run ${SOURCES})

target_link_libraries(run libtest libtree)

install(TARGETS run DESTINATION bin)
