//queue.c

#include "queue.h"
#include <stdlib.h>
#include <string.h>

Queue* queue_initialize(int itemSize, char* type) {

	Queue *queue = malloc(sizeof(*queue));

	//intialize the array_list in the queue to do the work
	queue->alist = alist_initialize(10, itemSize, type);

	return queue;
}

bool queue_enqueue(Queue* queue, void* item) {

	if (queue == NULL || item == NULL) {
	
		return false;
	}

	return alist_add_at(queue->alist, 0, item);
}

void* queue_dequeue(Queue* queue) {

	if (queue == NULL) {
	
		return false;
	}

	return alist_remove(queue->alist, queue->alist->size -1);
}

void* queue_peek(Queue* queue) {

	if (queue == false) {
	
		return false;
	}

	return alist_get(queue->alist, (queue->alist->size - 1));
}

int queue_size(Queue* queue) {

	if (queue == NULL) {
	
		return -1;
	}

	return queue->alist->size;
}

bool queue_contains(Queue* queue, void* item) {

	if (queue == NULL || item == NULL) {
	
		return false;
	}

	if (alist_index_of(queue->alist, item) != -1) {
	
		return true;
	}
	else {
	
		return false;
	}
}

bool queue_destroy(Queue* queue) {

	if (queue == NULL) {
	
		return false;
	}

	for (int i = 0; i < queue->alist->size; i++) {
	
		queue_dequeue(queue);
	}

	free(queue->alist->arr);
	free(queue->alist->type);
	free(queue->alist);

	free(queue);

	return true;
}



