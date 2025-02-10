cmake_minimum_required(VERSION 3.10)

set(CMAKE_DEBUG_POSTFIX d)
set(PROJECT_NAME Tests)
set(REPOS_DIR ${PROJECT_SOURCE_DIR}/..)

project(${PROJECT_NAME})
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${REPOS_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${REPOS_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${REPOS_DIR}/bin)

include_directories(
    ${REPOS_DIR}/include/zmath
    ${REPOS_DIR}/3rd/gtest/include
)
link_directories(
    ${REPOS_DIR}/bin
    ${REPOS_DIR}/3rd/gtest/bin
)
link_libraries(
    zmath.lib
    $<IF:$<CONFIG:Debug>,gtestd.lib,gtest.lib>
    $<IF:$<CONFIG:Debug>,gtest_maind.lib,gtest_main.lib>
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
