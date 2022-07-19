cmake_minimum_required(VERSION 3.18)

project(TTVM
    VERSION 1.0.0
    HOMEPAGE_URL https://opentypo.github.io
    LANGUAGES CXX
)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(lib)
add_subdirectory(unittests)

enable_testing()

add_test(ttvm-platform-tests unittests/Platform/ttvm-platform-tests)
