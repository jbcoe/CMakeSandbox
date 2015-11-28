cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

add_library(favourite_number SHARED FavouriteNumber.cpp)
add_library(least_favourite_number SHARED LeastFavouriteNumber.cpp)

add_executable(main main.cpp)

target_link_libraries(main favourite_number least_favourite_number)
