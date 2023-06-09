#ifndef CPU_USAGE_TRACKER_READER_H
#define CPU_USAGE_TRACKER_READER_H

#include <stddef.h>
#include <stdint.h>

typedef enum{
    reader_success = 0,
    reader_open_fail,
    reader_stats_destroyed,
    reader_stats_null,
    reader_zero_cores
}reader_error;

typedef struct cpu_stats{
    uint64_t user;
    uint64_t nice;
    uint64_t system;
    uint64_t idle;
    uint64_t iowait;
    uint64_t irq;
    uint64_t softirq;
    uint64_t steal;
    uint64_t guest;
    uint64_t guest_nice;

} cpu_stats;

typedef struct cpu_stats_arr{
    uint8_t cpu_cores;
    cpu_stats* arr[];
} cpu_stats_arr;

cpu_stats_arr* reader_stats_arr_new(void);
reader_error reader_stats_arr_delete(cpu_stats_arr* stats);

reader_error reader_stats_arr_clean(cpu_stats_arr* stats);
reader_error reader_read_stats(cpu_stats_arr* stats);

reader_error reader_get_core_num(uint8_t* cores);

#endif //CPU_USAGE_TRACKER_READER_H
