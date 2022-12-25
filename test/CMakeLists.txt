enable_testing()

include(FetchContent)

FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip)
FetchContent_MakeAvailable(googletest)

add_executable(
  multi_run_loops_test
  main_test.cpp
)
target_link_libraries(
  multi_run_loops_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(multi_run_loops_test)