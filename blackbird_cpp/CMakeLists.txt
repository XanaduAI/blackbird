cmake_minimum_required(VERSION 3.0.1)
# project(blackbird VERSION 0.1.0 DESCRIPTION "Blackbird C++ parser shared library")
project(blackbird)

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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories(/usr/local/include)
include_directories(/usr/local/include/antlr4-runtime)


add_library(${PROJECT_NAME} SHARED
	Visitor.cpp
	blackbirdBaseVisitor.cpp
	blackbirdLexer.cpp
	blackbirdParser.cpp)

find_library(ANTLR4_RUNTIME antlr4-runtime HINTS /usr/local/include/lib)

target_link_libraries(${PROJECT_NAME} -O ${ANTLR4_RUNTIME})
# set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
	"Blackbird.h;blackbirdLexer.h;blackbirdVisitor.h;blackbirdParser.h;blackbirdBaseVisitor.h;BlackbirdProgram.h;BlackbirdVariables.h")
target_include_directories(${PROJECT_NAME} PRIVATE .)
# set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 0)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
