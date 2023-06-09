#include <stdio.h>
#include "printer.h"
#include<unistd.h>

int main() {
    cpu_stats_arr* arr1 = reader_stats_arr_new();
    cpu_stats_arr* arr2 = reader_stats_arr_new();

    reader_read_stats(arr1);
    sleep(1);
    reader_read_stats(arr2);

    analyzer_update(arr1);
    analyzer_update(arr2);

    cpu_usage* usage = analyzer_analyze();

    print_usage(usage);

    analyzer_delete();
    analyzer_usage_delete(usage);

    return 0;
}
