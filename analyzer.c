#include "analyzer.h"

#include "reader.h"
#include <stdlib.h>



struct analyzer
{
    cpu_stats_arr* prev;
    cpu_stats_arr* curr;
};

cpu_usage* analyzer_analyze(analyzer* an)
{
   if(an == NULL)
       return NULL;

    if(an->curr == NULL || an->prev == NULL)
       return NULL;

   const register uint8_t cpu_core = an->curr->cpu_cores;

   cpu_usage* usage = calloc(1,sizeof(*usage) + sizeof(double) * cpu_core);
   if(usage == NULL)
       return NULL;

   usage->cpu_core = cpu_core;

   for(uint8_t i = 0; i<cpu_core; i++){
        uint64_t prev_idle = an->prev->arr[i]->idle + an->prev->arr[i]->iowait;
        uint64_t curr_idle = an->curr->arr[i]->idle + an->curr->arr[i]->iowait;

        uint64_t prev_non_idle =
                an->prev->arr[i]->user + an->prev->arr[i]->nice + an->prev->arr[i]->system +
                an->prev->arr[i]->irq + an->prev->arr[i]->softirq + an->prev->arr[i]->steal;

        uint64_t curr_non_idle =
               an->curr->arr[i]->user + an->curr->arr[i]->nice + an->curr->arr[i]->system +
               an->curr->arr[i]->irq + an->curr->arr[i]->softirq + an->curr->arr[i]->steal;


        uint64_t prev_total = prev_idle + prev_non_idle;
        uint64_t total = curr_idle + curr_non_idle;

        uint64_t total_d = total - prev_total;
        uint64_t idle_d = curr_idle - prev_idle;

        usage->usage[i] = ( (double) (total_d - idle_d)/total_d ) * 100;
   }

    reader_stats_arr_delete(an->prev);
    an->prev = an->curr;
    an->curr = NULL;

   return usage;
}

void analyzer_update(cpu_stats_arr* const stats, analyzer* an)
{
    if(stats == NULL) return;

    if(an == NULL) return;

    if(an->curr == NULL)
        an->curr = stats;
    else
    {
        reader_stats_arr_delete(an->prev);
        an->prev = an->curr;
        an->curr = stats;
    }

}

void analyzer_delete(analyzer* an)
{
    if(an == NULL) return;

    reader_stats_arr_delete(an->prev);
    reader_stats_arr_delete(an->curr);

    free(an);
}

void analyzer_usage_delete(cpu_usage* usage)
{
    if(usage == NULL)
        return;

    free(usage);
}

analyzer* analyzer_new()
{
    analyzer* an = calloc(1,sizeof(*an));
    return an;
}