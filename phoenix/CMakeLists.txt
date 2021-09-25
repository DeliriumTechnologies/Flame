cmake_minimum_required(VERSION 3.16)

project("Phoenix3D" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Gui Core OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(phoenix main.cpp mainwindow.h mainwindow.cpp viewport.h viewport.cpp)

target_link_libraries(phoenix Qt5::Widgets Qt5::OpenGL Qt5::Core Qt5::Gui)