cmake_minimum_required(VERSION 2.8.9)
project(blackbird_apps)

macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

use_cxx11()
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#Bring the headers
include_directories(/usr/local/include)
include_directories(/usr/local/include/antlr4-runtime)

# bring the libraries
find_library(ANTLR4_RUNTIME antlr4-runtime HINTS /usr/local/lib)
find_library(BLACKBIRD blackbird HINTS /usr/local/lib)

# Create print_blackbird example
set(SOURCES print_blackbird.cpp)
add_executable(print_blackbird ${SOURCES})
target_link_libraries(print_blackbird -O ${ANTLR4_RUNTIME} ${BLACKBIRD})

# Create chip0_simulator example
set(SOURCES chip0_simulator.cpp)
add_executable(chip0_simulator ${SOURCES})
target_link_libraries(chip0_simulator -O ${ANTLR4_RUNTIME} ${BLACKBIRD})
