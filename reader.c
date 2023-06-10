#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static cpu_stats* reader_stats_new(void)
{
    cpu_stats* stats = calloc(1,sizeof(*stats));

    if(stats == NULL)
        return NULL;

    *stats = (cpu_stats){
        .user = 0,
        .nice = 0,
        .system = 0,
        .idle = 0,
        .iowait = 0,
        .irq = 0,
        .softirq = 0,
        .steal = 0,
        .guest = 0,
        .guest_nice = 0
    };

    return stats;
}

static reader_error reader_stats_delete(cpu_stats* stats)
{
    if(stats == NULL)
        return reader_stats_null;

    free(stats);

    return reader_stats_destroyed;
}

reader_error reader_read_stats(cpu_stats_arr* const stats)
{
    const register size_t buff_size = 1024;
    char buffer[buff_size];

    FILE* in_stream = fopen("/proc/stat","r");
    if(in_stream == NULL)
        return reader_open_fail;

    if(stats == NULL){
        fclose(in_stream);
        return reader_stats_null;
    }


    if(stats->cpu_cores <= 0){
        fclose(in_stream);
        return reader_zero_cores;
    }


    reader_stats_arr_clean(stats);

    //skipping first line
    fgets(buffer,buff_size,in_stream);

    for(uint8_t i = 0; i < stats->cpu_cores; i++){
        cpu_stats* new_stats = reader_stats_new();

        if(fgets(buffer,buff_size,in_stream) ){
            char* line = strtok(buffer,"\n");
            int curr_cpu;
            if(line[0] == 'c'){
                sscanf(line, "cpu%d %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
                       &curr_cpu, &(new_stats->user), &(new_stats->nice),
                       &(new_stats->system), &(new_stats->idle), &(new_stats->iowait),
                       &(new_stats->irq), &(new_stats->softirq), &(new_stats->steal),
                       &(new_stats->guest), &(new_stats->guest_nice));
            }
        }
        stats->arr[i] = new_stats;
    }

    fclose(in_stream);

    return reader_success;
}

cpu_stats_arr* reader_stats_arr_new()
{
    uint8_t cpu_cores;
    reader_get_core_num(&cpu_cores);

    if(cpu_cores <= 0)
        return NULL;

    cpu_stats_arr* stats_arr = calloc(1,sizeof(*stats_arr) + sizeof(cpu_stats) * cpu_cores);

    if(stats_arr == NULL)
        return NULL;

    stats_arr->cpu_cores = cpu_cores;


    for(uint8_t i = 0; i < cpu_cores; i++){
        cpu_stats* new_stats = reader_stats_new();
        stats_arr->arr[i] = new_stats;
    }

    return stats_arr;
}

reader_error reader_stats_arr_delete(cpu_stats_arr* stats)
{
    if(stats == NULL)
        return reader_stats_null;

    reader_stats_arr_clean(stats);
    free(stats);

    return reader_stats_destroyed;
}

reader_error reader_stats_arr_clean(cpu_stats_arr* stats)
{
    if(stats == NULL)
        return reader_stats_null;

    for(uint8_t i = 0; i < stats->cpu_cores; i++){
        reader_stats_delete(stats->arr[i]);
        stats->arr[i] = NULL;
    }

    return reader_stats_destroyed;
}

reader_error reader_get_core_num(uint8_t* cores)
{
    if(cores == NULL)
        return reader_stats_null;

    FILE* file;
    const register size_t buff_size = 1024;
    char buffer[buff_size];

    file = fopen("/proc/stat", "r");
    if (file == NULL)
        return reader_open_fail;


    uint8_t no_cores = 0;
    while (fgets(buffer, buff_size, file) != NULL) {
        if (buffer[0] == 'c' && buffer[1] == 'p' && buffer[2] == 'u')
            no_cores++;
    }

    fclose(file);

    *cores = no_cores - 1;

    return reader_success;
}