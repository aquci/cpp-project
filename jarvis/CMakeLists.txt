cmake_minimum_required(VERSION 3.10)

project(Jarvis)

set(CMAKE_CXX_STANDARD 17)

add_executable(jarvis
    jarvis.cpp
    jarvisUi.cpp
)

target_link_libraries(jarvis ncurses)
