cmake_minimum_required(VERSION 3.16)

project("Phoenix3D" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets Gui Core OpenGLWidgets Qml Quick REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set (SOURCES main.cpp mainwindow.h mainwindow.cpp viewport.h viewport.cpp)

qt6_add_resources(SOURCES res.qrc)

add_executable(phoenix ${SOURCES})

target_link_libraries(phoenix PRIVATE Qt6::Widgets Qt6::OpenGLWidgets Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)