cmake_minimum_required(VERSION 3.22)
project(cpu_usage_tracker C)

set(CMAKE_C_STANDARD 99)

add_library(queue queue.h queue.c)
add_library(reader reader.h reader.c)
add_library(analyzer analyzer.h analyzer.c)

add_executable(cut main.c printer.h)
add_executable(tests tests/main_test.c tests/queue_test.c tests/reader_test.c tests/analyzer_test.c)

target_link_libraries(cut PRIVATE queue)
target_link_libraries(cut PRIVATE reader)
target_link_libraries(cut PRIVATE analyzer)

target_link_libraries(tests PRIVATE queue)
target_link_libraries(tests PRIVATE reader)
target_link_libraries(tests PRIVATE analyzer)

