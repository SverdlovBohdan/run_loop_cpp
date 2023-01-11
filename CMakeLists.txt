cmake_minimum_required(VERSION 3.0.0)
project(multi_run_loops VERSION 0.1.0)

option(ENABLE_TEST "Turn on to enable tests" ON)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)
target_compile_options(project_options INTERFACE
-Wall -Wextra -Wpedantic -Werror -Wstrict-aliasing -Wuninitialized
  -Wunused-parameter -Wsign-compare -Wsign-conversion -Wunreachable-code
  -Wcast-align -Wno-implicit-fallthrough -Wno-uninitialized
  -Wno-missing-field-initializers -Wno-ignored-qualifiers -Wswitch-enum
  -Wredundant-decls -Wno-strict-overflow -Wshadow
  $<$<COMPILE_LANGUAGE:CXX>:
      -Woverloaded-virtual -Wreorder -Wzero-as-null-pointer-constant -Wnon-virtual-dtor>)

add_subdirectory(src)

if (ENABLE_TEST)
    add_subdirectory(test)
endif()