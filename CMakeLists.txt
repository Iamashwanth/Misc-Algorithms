cmake_minimum_required (VERSION 3.0)

project (Misc-Algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories("$(CMAKE_CURRENT_SOURCE_DIR)")
include_directories("$(CMAKE_CURRENT_SOURCE_DIR)/tests/")

file(GLOB
     SOURCES
     main.cpp)

add_subdirectory(library)
add_subdirectory(tests)

add_executable(run_tests ${SOURCES})

target_link_libraries(run_tests libtest libcode)

install(TARGETS run_tests DESTINATION bin)
