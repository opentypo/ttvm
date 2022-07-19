add_executable(ttvm-platform-tests PlatformTest.cpp PlatformErrorTest.cpp MemoryBlockTest.cpp)

target_link_libraries(ttvm-platform-tests PUBLIC ttvm-platform GTest::gtest GTest::gtest_main)
target_include_directories(ttvm-platform-tests PUBLIC ${PROJECT_SOURCE_DIR}/include)

gtest_discover_tests(ttvm-platform-tests)
