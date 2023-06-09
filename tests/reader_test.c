#include "reader_test.h"
#include "../reader.h"

#include <assert.h>

static void test_reader_read_stats(void)
{
    {
        cpu_stats_arr* stats_arr = reader_stats_arr_new();
        register const reader_error e = reader_read_stats(stats_arr);
        register const reader_error d = reader_stats_arr_delete(stats_arr);

        assert(stats_arr != NULL);
        assert(e == reader_success);
        assert(d == reader_stats_destroyed);
    }

    {
        cpu_stats_arr* stats_arr = reader_stats_arr_new();
        register const reader_error e = reader_read_stats(NULL);
        register const reader_error d = reader_stats_arr_delete(NULL);

        assert(stats_arr != NULL);
        assert(e == reader_stats_null);
        assert(d == reader_stats_null);
    }

}

static void test_reader_stats_arr_new(void)
{
    {
        cpu_stats_arr* stats_arr = reader_stats_arr_new();
        assert(stats_arr != NULL);
        reader_stats_arr_delete(stats_arr);
    }
}

static void test_reader_stats_arr_delete(void)
{
    {
        cpu_stats_arr* stats_arr = reader_stats_arr_new();
        register const reader_error d = reader_stats_arr_delete(stats_arr);
        assert(d == reader_stats_destroyed);
    }

    {
        register const reader_error d = reader_stats_arr_delete(NULL);
        assert(d == reader_stats_null);
    }
}

static void test_reader_stats_arr_clean(void)
{
    {
        cpu_stats_arr* stats_arr = reader_stats_arr_new();
        register const reader_error c = reader_stats_arr_clean(stats_arr);
        assert(stats_arr != NULL);
        assert(c == reader_stats_destroyed);

        reader_stats_arr_delete(stats_arr);
    }

    {
        register const reader_error c = reader_stats_arr_clean(NULL);
        assert(c == reader_stats_null);
    }
}

static void  test_reader_get_core_num(void)
{
    {
        uint8_t core_num;
        register const reader_error err = reader_get_core_num(&core_num);
        assert(err == reader_success);
    }
}


void test_reader_main(void)
{
    test_reader_read_stats();

    test_reader_stats_arr_new();
    test_reader_stats_arr_delete();

    test_reader_stats_arr_clean();

    test_reader_get_core_num();
}
