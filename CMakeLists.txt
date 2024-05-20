cmake_minimum_required(VERSION 3.4)
project(GumballMachine)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/code)
include(CPack.cmake)

if(BUILD_TESTS)
  add_compile_options(--coverage)
endif()


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB CODE_TEST_SOURCES tests/*.cpp)
  add_executable(check ${CODE_TEST_SOURCES})
  target_link_libraries(check code gtest_main gmock_main)
  add_test(NAME check COMMAND check)
endif()

