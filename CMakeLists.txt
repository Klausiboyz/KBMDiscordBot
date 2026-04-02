cmake_minimum_required(VERSION 3.14)
project(cpp-project VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(dpp REQUIRED)

add_executable(cpp-project src/main.cpp)
target_link_libraries(cpp-project PRIVATE dpp::dpp)
