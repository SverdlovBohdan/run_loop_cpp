cmake_minimum_required(VERSION 3.0.0)
project(multi_run_loops VERSION 0.1.0)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)
target_compile_options(project_options INTERFACE
  -Wall -Wextra -Wpedantic -Werror)

add_subdirectory(src)

option(ENABLE_TEST "Turn on to enable tests" ON)
if (ENABLE_TEST)
    add_subdirectory(test)
endif()