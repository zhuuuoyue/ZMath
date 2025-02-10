cmake_minimum_required(VERSION 3.10)

set(REPOS_DIR ${CMAKE_SOURCE_DIR}/..)

project(ZMathSolution)
add_subdirectory(ZMath)
add_subdirectory(Tests)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Tests)
set_target_properties(Tests PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${REPOS_DIR}/bin/$<CONFIG>)

add_dependencies(Tests ZMath)
