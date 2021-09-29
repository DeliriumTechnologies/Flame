cmake_minimum_required(VERSION 3.16)

project("Flame" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/OpenCL-SDK)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/thirdparty/OpenCL-SDK/include)

set (SOURCES api.h)

install (TARGETS OpenCL DESTINATION ${CMAKE_SOURCE_DIR}/lib)
install (TARGETS OpenCL DESTINATION ${install_dest})

link_libraries(OpenCL)

add_library(libflameray-opencl SHARED ${SOURCES})

add_library(libflameray-opencl_s STATIC ${SOURCES})
set_target_properties(libflameray-opencl_s PROPERTIES OUTPUT_NAME libflameray-opencl)

if (${PLATFORM} MATCHES "win")
target_compile_definitions(libflameray-opencl PRIVATE WIN_EXPORT)
endif()