#include "../analyzer.h"

#include <assert.h>
#include<unistd.h>


static void test_analyzer_mix(void)
{
    {
        cpu_usage* usage = analyzer_analyze();
        assert(usage == NULL);
        analyzer_delete();
    }

    {
        cpu_stats_arr* arr1 = reader_stats_arr_new();
        cpu_stats_arr* arr2 = reader_stats_arr_new();

        reader_read_stats(arr1);
        sleep(1);
        reader_read_stats(arr2);

        analyzer_update(arr1);
        analyzer_update(arr2);

        cpu_usage* usage = analyzer_analyze();

        assert(usage != NULL);

        analyzer_delete();
        analyzer_usage_delete(usage);

    }
}


void test_analyzer_main(void)
{
   test_analyzer_mix();
}
