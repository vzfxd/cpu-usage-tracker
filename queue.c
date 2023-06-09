#include "queue.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    size_t head;
    size_t tail;

    size_t capacity;
    size_t elem_size;
    size_t elem_num;

    uint64_t buff[];
};

Queue* queue_new(register const size_t capacity, register const size_t elem_size)
{
    if(elem_size==0)
        return NULL;

    if(capacity==0)
        return NULL;

    Queue* q = calloc(1, sizeof(*q) + (capacity * elem_size) );
    if(q == NULL)
        return NULL;

    *q = (Queue){
        .head = 0,
        .tail = 0,
        .elem_num = 0,
        .capacity = capacity,
        .elem_size = elem_size
    };

    return q;
}

queue_error queue_delete(Queue* q)
{
    if(q==NULL)
        return queue_null;

    free(q);

    return queue_destroyed;
}

bool queue_is_full(const Queue* q)
{
    if(q == NULL)
        return false;

    return q->elem_num == q->capacity;
}

bool queue_is_empty(const Queue* q)
{
    if(q == NULL)
        return true;

    return q->elem_num == 0;
}

queue_error queue_enqueue(Queue* const restrict q,void* restrict elem)
{
    if(q == NULL)
        return queue_null;

    if(elem == NULL)
        return queue_null_enqueue;

    if(queue_is_full(q) == true)
        return queue_full;

    uint64_t* const ptr = &q->buff[ q->head * q->elem_size ];
    memcpy(ptr,elem,q->elem_size);
    q->elem_num++;

    q->head = (q->head + 1) % q->capacity;

    return queue_success;
}

queue_error queue_dequeue(Queue* const restrict q, void* restrict elem)
{
    if(q == NULL)
        return queue_null;

    if(elem == NULL)
        return queue_null_dequeue;

    if(queue_is_empty(q) == true)
        return queue_empty;

    uint64_t* const ptr = &q->buff[ q->tail * q->elem_size ];
    memcpy(elem,ptr,q->elem_size);
    q->elem_num--;

    q->tail = (q->tail + 1) % q->capacity;

    return queue_success;
}


