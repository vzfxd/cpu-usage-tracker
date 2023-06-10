#include "printer.h"
#include "queue.h"
#include "analyzer.h"

#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void delay(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

typedef struct thread_options {
    Queue* stats_q;
    Queue* usage_q;
    uint8_t cpu_cores;
    analyzer* an;
} thread_options;

static void* reader_f(void* arg)
{
    thread_options* opt = arg;

    Queue* stats_q = opt->stats_q;


    while(1)
    {
        queue_lock(stats_q);

        if(queue_is_full(stats_q))
            queue_wait_for_consumer(stats_q);

        cpu_stats_arr* stats = reader_stats_arr_new();
        reader_read_stats(stats);

        queue_enqueue(stats_q,stats);
        free(stats);

        queue_call_consumer(stats_q);
        queue_unlock(stats_q);

        delay(750);
    }
}

static void* analyzer_f(void* arg)
{
    thread_options* opt = arg;

    Queue* stats_q = opt->stats_q;
    Queue* usage_q = opt->usage_q;
    uint8_t cpu_cores = opt->cpu_cores;
    analyzer* an = opt->an;

    while(1)
    {
        // ZBIERANIE DANYCH OD READERA //
        queue_lock(stats_q);

        if(queue_is_empty(stats_q))
            queue_wait_for_producer(stats_q);

        cpu_stats_arr* stats = calloc(1,sizeof(cpu_stats_arr) + sizeof(cpu_stats) * cpu_cores);
        queue_dequeue(stats_q,stats);

        queue_call_producer(stats_q);
        queue_unlock(stats_q);
        //



        // ENQUEUE DLA PRINTERA //
        queue_lock(usage_q);

        if(queue_is_full(usage_q))
            queue_wait_for_consumer(usage_q);

        analyzer_update(stats,an);
        cpu_usage* usage = analyzer_analyze(an);
        queue_enqueue(usage_q,usage);
        free(usage);

        queue_call_consumer(usage_q);
        queue_unlock(usage_q);
        //
    }
}

static void* printer_f(void* arg)
{
    thread_options* opt = arg;

    Queue* usage_q = opt->usage_q;
    uint8_t cpu_cores = opt->cpu_cores;

    while(1)
    {
        queue_lock(usage_q);

        if(queue_is_empty(usage_q))
            queue_wait_for_producer(usage_q);

        cpu_usage* usage = calloc(1,sizeof(cpu_usage) + sizeof(double) * cpu_cores);
        queue_dequeue(usage_q,usage);
        print_usage(usage);

        analyzer_usage_delete(usage);

        queue_call_producer(usage_q);
        queue_unlock(usage_q);
    }
}

int main() {
    Queue* stats_q;
    Queue* usage_q;
    uint8_t cpu_cores;
    analyzer* an;

    pthread_t reader;
    pthread_t analyzer;
    pthread_t printer;

    reader_get_core_num(&cpu_cores);
    stats_q = queue_new(10,sizeof(cpu_stats_arr) + sizeof(cpu_stats) * cpu_cores);
    usage_q = queue_new(10,sizeof(cpu_usage) + sizeof(double) * cpu_cores);
    an = analyzer_new();

    thread_options opt = {
            .usage_q = usage_q,
            .cpu_cores = cpu_cores,
            .stats_q = stats_q,
            .an = an
    };

    pthread_create(&reader, NULL, reader_f, &opt);
    pthread_create(&analyzer, NULL, analyzer_f,&opt );
    pthread_create(&printer, NULL, printer_f, &opt);

    pthread_join(reader,NULL);
    pthread_join(analyzer,NULL);
    pthread_join(printer,NULL);

    analyzer_delete(an);
    queue_delete(stats_q);
    queue_delete(usage_q);

    return 0;
}
