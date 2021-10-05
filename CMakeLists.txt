cmake_minimum_required(VERSION 3.5)

project(LINKED_LIST LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(BUILD_TESTS "Builds the ut tests" OFF)

set(CMAKE_CXX_FLAGS "-g" ${CMAKE_CXX_FLAGS})

add_subdirectory( app )

if(BUILD_TESTS)
    add_subdirectory( ut )
endif()