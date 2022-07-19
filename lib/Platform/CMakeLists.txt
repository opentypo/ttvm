add_library(ttvm-platform Platform.cpp Memory.cpp MemoryBlock.cpp PlatformError.cpp)

target_include_directories(ttvm-platform PUBLIC ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIR})
target_link_libraries(ttvm-platform PUBLIC Threads::Threads ${Boost_LIBRARIES})
