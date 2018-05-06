cmake_minimum_required(VERSION 3.8)
set(PROJECT_NAME FactoryModel)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES abstract_factory_model.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_executable(Strategy strategy_model.cpp)
