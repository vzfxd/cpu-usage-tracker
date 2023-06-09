#ifndef CPU_USAGE_TRACKER_QUEUE_H
#define CPU_USAGE_TRACKER_QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef enum{
    queue_success = 0,
    queue_destroyed,
    queue_null,
    queue_full,
    queue_empty,
    queue_null_enqueue, //provided null pointer as element to enqueue
    queue_null_dequeue //provided null pointer as element to dequeue
}queue_error;

typedef struct Queue Queue;

Queue* queue_new(size_t capacity, size_t elem_size);
queue_error queue_delete(Queue* q);

bool queue_is_full(const Queue* q);
bool queue_is_empty(const Queue* q);

queue_error queue_enqueue(Queue* restrict q, void* restrict elem);
queue_error queue_dequeue(Queue* restrict q, void* restrict elem);


#endif
