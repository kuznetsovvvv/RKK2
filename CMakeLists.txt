cmake_minimum_required(VERSION 3.10)

project(GumballMachine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option to enable tests
option(BUILD_TESTS "Build tests" OFF)

# Library
set(SOURCES 
    SoldState.cpp
    gumballmachine.cpp
    hasquarterstate.cpp
    noquarterstate.cpp
    soldoutstate.cpp
    winnerstate.cpp
)

add_library(GumballMachineLib STATIC ${SOURCES})
target_include_directories(GumballMachineLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Executable (for the main application)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} GumballMachineLib)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Header files (Use absolute paths)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/HasQuarterState.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/NoQuarterState.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SoldOutState.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SoldState.h
    ${CMAKE_CURRENT_SOURCE_DIR}/State.h
    ${CMAKE_CURRENT_SOURCE_DIR}/WinnerState.h
    ${CMAKE_CURRENT_SOURCE_DIR}/gumballmachine.h
)

target_sources(GumballMachineLib PUBLIC ${HEADERS})

# Tests
if(BUILD_TESTS)
  enable_testing()

  # Include Google Test using FetchContent
  include(FetchContent)
  FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.11.0 # Use the desired Google Test version
  )
  FetchContent_GetProperties(googletest)
  if(NOT googletest_POPULATED)
      FetchContent_Populate(googletest)
      add_subdirectory(${googletest_SOURCE_DIR})
  endif()

  # Include Google Mock using FetchContent
  include(FetchContent)
  FetchContent_Declare(
      googlemock
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.11.0 # Use the desired Google Test version
  )
  FetchContent_GetProperties(googlemock)
  if(NOT googlemock_POPULATED)
      FetchContent_Populate(googlemock)
      add_subdirectory(${googlemock_SOURCE_DIR})
  endif()

  # Tests for State.h and gumballmachine.h in tests.cpp
  add_executable(GumballMachineTests tests/tests.cpp)
  target_link_libraries(GumballMachineTests GumballMachineLib gtest gmock)
  target_include_directories(GumballMachineTests PUBLIC 
    ${googletest_SOURCE_DIR}/googletest/include 
    ${googlemock_SOURCE_DIR}/googlemock/include
  )
  add_test(NAME GumballMachineTests COMMAND GumballMachineTests)
endif()

# Set CPack options for source package
include(CPack)
set(CPACK_GENERATOR "TGZ") # Specify the package format
set(CPACK_PACKAGE_NAME "GumballMachine") # Set the package name
set(CPACK_PACKAGE_VERSION_MAJOR 1) # Set the package version (major)
set(CPACK_PACKAGE_VERSION_MINOR 0) # Set the package version (minor)
set(CPACK_PACKAGE_VERSION_PATCH 0) # Set the package version (patch)

# Specify the directories to include in the package
set(CPACK_INSTALLED_DIRECTORIES 
    "${CMAKE_CURRENT_SOURCE_DIR}/include" "include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src" "src" 
    "${CMAKE_CURRENT_SOURCE_DIR}/tests" "tests" 
)
