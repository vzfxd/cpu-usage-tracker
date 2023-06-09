#ifndef CPU_USAGE_TRACKER_PRINTER_H
#define CPU_USAGE_TRACKER_PRINTER_H

#include "analyzer.h"
#include "stdio.h"
#include "stddef.h"

void print_usage(cpu_usage* usage)
{
    for(uint8_t i = 0; i<usage->cpu_core; i++){
        printf("cpu%d",i);
        for(uint8_t j = 0; j < usage->usage[i]; j++){
            printf("█");
        }
        printf("\n");
    }
}

#endif //CPU_USAGE_TRACKER_PRINTER_H
