add_library(multi_run_loops_static
    run_loop.cpp
    priority_task_queue.cpp
    steady_time_provider.cpp
    task_pump_std.cpp
)
target_include_directories(multi_run_loops_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(multi_run_loops_static PRIVATE project_options)