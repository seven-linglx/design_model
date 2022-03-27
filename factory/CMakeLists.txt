cmake_minimum_required(VERSION 3.4)
set(APP_NAME FactoryPattern)
project(${APP_NAME})
set(CMAKE_CXX_STANDARD 14)

add_executable(Factory abstract_factory_model.cpp)
