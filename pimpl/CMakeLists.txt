cmake_minimum_required(VERSION 3.4)
set(APP_NAME PImplPattern)
project(${APP_NAME})
set(CMAKE_CXX_STANDARD 14)

add_executable(Pimpl pimpl.cpp)
