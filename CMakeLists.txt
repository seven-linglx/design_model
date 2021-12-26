cmake_minimum_required(VERSION 3.4)
set(PROJECT_NAME DesignPattern)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

add_executable(FactoryModel abstract_factory_model.cpp)
add_executable(Strategy strategy_model.cpp)
add_executable(Pimpl pimpl.cpp)
