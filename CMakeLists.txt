cmake_minimum_required(VERSION 3.24)
project(cpu_usage_tracker C)

set(CMAKE_C_STANDARD 99)

add_library(queue queue.h queue.c)
add_library(reader reader.h reader.c)

add_executable(cut main.c reader.c reader.h)
add_executable(tests tests/main_test.c tests/queue_test.c tests/queue_test.h tests/reader_test.c tests/reader_test.h)

target_link_libraries(cut PRIVATE queue)
target_link_libraries(cut PRIVATE reader)

target_link_libraries(tests PRIVATE queue)
target_link_libraries(tests PRIVATE reader)
