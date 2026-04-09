cmake_minimum_required(VERSION 4.1.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(backend)

find_package(gRPC)

add_subdirectory(src)
add_subdirectory(bin)
