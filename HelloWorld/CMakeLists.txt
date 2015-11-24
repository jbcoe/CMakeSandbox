cmake_minimum_required(VERSION 3.3)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

include(extras)

add_custom_target(Wibble COMMAND echo "All your base are belong to us")

set(TEXT_SOURCES hello_text.c goodbye_text.c)

add_library(Text SHARED ${TEXT_SOURCES})

include_directories(${XercesC_INCLUDE_DIRS})
add_executable(HelloWorld hello.c)

target_link_libraries(HelloWorld Text)

add_dependencies(HelloWorld Wibble)

