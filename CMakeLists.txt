cmake_minimum_required(VERSION 3.4)
set(PROJECT_NAME DesignPattern)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(factory)
add_subdirectory(pimpl)
add_subdirectory(strategy)
add_subdirectory(proxy)
