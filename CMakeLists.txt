cmake_minimum_required(VERSION 3.16)

project("Phoenix3D" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set (PLATFORM "default")

if (WIN32)
    set (PLATFORM "win")
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set (PLATFORM "osx")
endif()

if (UNIX AND NOT APPLE)
    set (PLATFORM "x11")
endif()

add_subdirectory("phoenix")

set (install_dest ${CMAKE_SOURCE_DIR}/${PLATFORM})

install (TARGETS phoenix DESTINATION ${install_dest})