enable_testing()

include(FetchContent)

FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip)
FetchContent_MakeAvailable(googletest)

add_executable(
  multi_run_loops_test
  priority_task_queue_test.cpp
  task_pump_std_test.cpp
  run_loop_test.cpp
)
target_link_libraries(
  multi_run_loops_test
  multi_run_loops_static
  GTest::gtest_main
  GTest::gmock
)
target_compile_features(multi_run_loops_test INTERFACE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(multi_run_loops_test)