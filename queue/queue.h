//array_list.h

#ifndef __QUEUE_HEADER
#define __QUEUE_HEADER

#include <stdbool.h>
#include "../array_list/array_list.h"

//creating a type for queues

typedef struct _Queue {

	ArrayList* alist;

} Queue;

//forward declarations
Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);


#endif
