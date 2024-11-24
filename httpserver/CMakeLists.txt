cmake_minimum_required(VERSION 3.18)
project(server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/httpserver/)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/httpserver/*.cpp)

add_executable(server ${SOURCES})

target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})