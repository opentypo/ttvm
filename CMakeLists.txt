cmake_minimum_required(VERSION 3.18)

project(TTVM
    VERSION 1.0.0
    HOMEPAGE_URL https://opentypo.github.io
    LANGUAGES CXX
)

enable_testing()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include(GoogleTest)

add_subdirectory(lib)
add_subdirectory(unittests)
