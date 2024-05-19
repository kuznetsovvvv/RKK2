cmake_minimum_required(VERSION 3.10)

project(GumballMachine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    SoldState.cpp
    gumballmachine.cpp
    hasquarterstate.cpp
    main.cpp
    noquarterstate.cpp
    soldoutstate.cpp
    winnerstate.cpp
)

# Добавление исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})

# Добавление пути к заголовочным файлам
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Добавление заголовочных файлов
set(HEADERS
    HasQuarterState.h
    NoQuarterState.h
    SoldOutState.h
    SoldState.h
    State.h
    WinnerState.h
    gumballmachine.h
)

target_sources(${PROJECT_NAME} PUBLIC ${HEADERS})

# Tests
enable_testing()

# Tests for State.h and GumballMachine.h in tests.cpp
add_executable(GumballMachineTests tests/tests.cpp)
target_link_libraries(GumballMachineTests GumballMachine catch2)
target_include_directories(GumballMachineTests PUBLIC ${catch2_SOURCE_DIR}/include)
add_test(NAME GumballMachineTests COMMAND GumballMachineTests)
