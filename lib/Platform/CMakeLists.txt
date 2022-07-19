add_library(ttvm-platform Platform.cpp)

target_include_directories(ttvm-platform PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(ttvm-platform PUBLIC Threads::Threads)
