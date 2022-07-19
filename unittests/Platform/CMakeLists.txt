add_executable(ttvm-platform-tests PlatformTest.cpp)

target_link_libraries(ttvm-platform-tests PUBLIC GTest::gtest GTest::gtest_main)
