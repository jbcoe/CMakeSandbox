cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-fPIC")

add_library(a SHARED a.cpp)
add_library(a2 SHARED a2.cpp)
add_library(b SHARED b.cpp)
add_library(abc SHARED abc.cpp)
add_library(abd SHARED abd.cpp)
add_library(abe SHARED abe.cpp)

add_executable(main main.cpp)

target_link_libraries(abc a b)
target_link_libraries(abd a2 b abc)
target_link_libraries(abe abc abd)
target_link_libraries(main abe)
