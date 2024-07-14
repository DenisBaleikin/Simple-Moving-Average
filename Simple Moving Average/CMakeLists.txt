cmake_minimum_required(VERSION 3.20)
project(SMA)

set(CMAKE_CXX_STANDARD 17)

set(RND_LIB rand_gen/impl/rand_impl.cpp)
add_library(rand_gen ${RND_LIB})


add_executable(sma main.cpp)
target_link_libraries(sma rand_gen)