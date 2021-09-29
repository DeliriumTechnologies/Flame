cmake_minimum_required(VERSION 3.16)

project("Flame" VERSION 1.0.0 LANGUAGES CXX)

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

set (install_dest ${CMAKE_SOURCE_DIR}/${PLATFORM})

add_subdirectory("libgui")

install (TARGETS libgui DESTINATION ${install_dest})

install (TARGETS libgui_s DESTINATION ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory("libflameray-opencl")

install (TARGETS libflameray-opencl DESTINATION ${install_dest})

install (TARGETS libflameray-opencl_s DESTINATION ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory("flame")

install (TARGETS flame DESTINATION ${install_dest})