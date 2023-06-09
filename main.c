#include "printer.h"
#include<unistd.h>

int main() {
    cpu_stats_arr* arr1 = reader_stats_arr_new();
    cpu_stats_arr* arr2 = reader_stats_arr_new();

    analyzer* an = analyzer_new();

    reader_read_stats(arr1);
    sleep(1);
    reader_read_stats(arr2);

    analyzer_update(arr1,an);
    analyzer_update(arr2,an);

    cpu_usage* usage = analyzer_analyze(an);

    print_usage(usage);

    analyzer_delete(an);
    analyzer_usage_delete(usage);

    return 0;
}
