cmake_minimum_required(VERSION 3.3)

project(Shape_c)

SET(Shape_c_VERSION_MAJOR 0)
SET(Shape_c_VERSION_MINOR 1)
SET(Shape_c_VERSION_PATCH 0)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER /usr/local/bin/clang++-3.6)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(Shape_c SHARED Shape_c.cpp Shape.h)

add_executable(TestMe TestMe.cpp)

file(COPY "test.py" "Shape.py" DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

install(TARGETS Shape_c DESTINATION .)
install(FILES "test.py" "Shape.py" DESTINATION .)

################################################################################

SET(CPACK_PACKAGE_VERSION_MAJOR ${Shape_c_VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${Shape_c_VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${Shape_c_VERSION_PATCH})
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "Shape_c.${Shape_c_VERSION_MAJOR}.${Shape_c_VERSION_MINOR}")
set(CPACK_GENERATOR TBZ2)
include(CPack)

################################################################################

enable_testing()

add_test(NAME TestPythonBindings
  COMMAND ${PYTHON_EXECUTABLE} test.py
  WORKING_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_test(NAME TestMe
  COMMAND TestMe
  WORKING_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
