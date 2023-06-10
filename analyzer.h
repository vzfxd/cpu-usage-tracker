#ifndef CPU_USAGE_TRACKER_ANALYZER_H
#define CPU_USAGE_TRACKER_ANALYZER_H

#include "reader.h"

typedef struct analyzer analyzer;

typedef struct cpu_usage{
    uint8_t cpu_core;
    double usage[];

} cpu_usage;

void analyzer_delete(analyzer* an);
analyzer* analyzer_new(void);

cpu_usage* analyzer_analyze(analyzer* an);

void analyzer_update(cpu_stats_arr* stats, analyzer* an);
void analyzer_usage_delete(cpu_usage* usage);





#endif //CPU_USAGE_TRACKER_ANALYZER_H
