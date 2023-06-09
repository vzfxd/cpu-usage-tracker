#include "../queue.h"

#include <assert.h>
#include <stdint.h>

static void test_queue_new(void)
{
    register const size_t capacity = 3;
    register const size_t elem_size = 2;

    {
        Queue* q = queue_new(0,elem_size);
        assert(q == NULL);
    }

    {
        Queue* q = queue_new(capacity,0);
        assert(q == NULL);
    }

    {
        Queue* q = queue_new(capacity,elem_size);
        assert(q != NULL);
        queue_delete(q);
    }
}

static void test_queue_delete(void)
{
    register const size_t capacity = 3;
    register const size_t elem_size = 2;

    {
        register const queue_error err = queue_delete(NULL);
        assert(err == queue_null);
    }

    {
        Queue* q = queue_new(capacity,elem_size);
        register const queue_error err = queue_delete(q);
        assert(err == queue_destroyed);
    }
}

static void test_queue_is_full(void)
{
    enum {capacity = 3};
    int elems_to_insert[capacity] = {7,9,4};
    register const size_t elem_size = sizeof(int);

    {
        Queue* q = queue_new(capacity,elem_size);
        assert(queue_is_full(q) == false);
        queue_delete(q);
    }

    {
        assert(queue_is_full(NULL) == false);
    }

    {
        Queue* q = queue_new(capacity,elem_size);

        for(size_t i = 0; i<capacity; i++)
            queue_enqueue(q,&elems_to_insert[i]);

        assert(queue_is_full(q) == true);
        queue_delete(q);
    }
}

static void test_queue_is_empty(void)
{
    register const size_t capacity = 3;
    register const size_t elem_size = 2;

    {
        Queue* q = queue_new(capacity,elem_size);
        assert(queue_is_empty(q) == true);
        queue_delete(q);
    }

    {
        assert(queue_is_empty(NULL) == true);
    }

    {
        Queue* q  = queue_new(capacity,elem_size);
        queue_enqueue(q,&(int){5});
        assert(queue_is_empty(q) == false);
        queue_delete(q);
    }
}

static void test_queue_enqueue(void)
{
    enum {capacity = 3};
    uint8_t elems_to_insert[capacity] = {7,9,4};
    register const size_t elem_size = sizeof(uint8_t);

    {
        Queue* q = queue_new(capacity-1,elem_size);
        queue_error err;


        err = queue_enqueue(q,&elems_to_insert[0]);
        err = queue_enqueue(q,&elems_to_insert[1]);

        assert(err != queue_full);
        queue_delete(q);
    }

    {
        Queue* q = queue_new(capacity,elem_size);
        queue_error err;
        err = queue_enqueue(q,NULL);
        assert(err == queue_null_enqueue);
        queue_delete(q);
    }

    {
        Queue* q = queue_new(capacity,elem_size);
        queue_error err;
        err = queue_enqueue(NULL,&(int){5});
        assert(err == queue_null);
        queue_delete(q);
    }
}

static void test_queue_dequeue(void)
{
    enum {capacity = 3};
    int elems_to_insert[capacity] = {7,9,4};
    register const size_t elem_size = sizeof(int);

    {
        Queue* q = queue_new(capacity,elem_size);
        queue_error err;
        int elem;

        for(size_t i = 0; i<capacity; i++)
            err = queue_enqueue(q,&elems_to_insert[i]);

        for(size_t i = 0; i<capacity+1; i++)
            err = queue_dequeue(q,&elem);

        assert(err == queue_empty);
        assert(elem == elems_to_insert[capacity-1]);
        queue_delete(q);
    }

    {
        Queue* q = queue_new(capacity,elem_size);
        queue_error err;
        err = queue_dequeue(q,NULL);
        assert(err == queue_null_dequeue);
        queue_delete(q);
    }

    {
        Queue* q = queue_new(capacity,elem_size);
        queue_error err;
        err = queue_dequeue(NULL,&(int){5});
        assert(err == queue_null);
        queue_delete(q);
    }
}

void test_queue_main(void)
{
    test_queue_new();
    test_queue_delete();

    test_queue_is_empty();
    test_queue_is_full();

    test_queue_enqueue();
    test_queue_dequeue();
}