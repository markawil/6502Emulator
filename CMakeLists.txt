cmake_minimum_required(VERSION 4.3)
project(6502Emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(emulator
        src/emulator.cpp
)

target_include_directories(emulator PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(6502Emulator main.cpp)
target_link_libraries(6502Emulator PRIVATE emulator)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    )

    # Primarily needed when building on Windows.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_executable(emulator_tests
            tests/emulator_test.cpp
    )

    target_link_libraries(emulator_tests PRIVATE
            emulator
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(emulator_tests)
endif()