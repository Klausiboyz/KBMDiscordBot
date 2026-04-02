cmake_minimum_required(VERSION 3.14)
project(cpp-project VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(dpp REQUIRED)

add_executable(cpp-project
    src/main.cpp
    src/system/command_handler.cpp
    src/system/event_handler.cpp
    src/game_elements/game_objects/items.cpp
    src/game_elements/game_objects/character_sheet.cpp
    src/game_elements/game_mechanics/abilities.cpp
    src/game_elements/game_mechanics/level_up.cpp
)

target_include_directories(cpp-project PRIVATE include)

target_link_libraries(cpp-project PRIVATE dpp::dpp)
