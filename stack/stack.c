//stack.c


#include "stack.h"
#include <stdlib.h>
#include <string.h>

Stack* stack_initialize(int itemSize, char* type) {

	Stack *stack = malloc(sizeof(*stack));

	stack->alist = alist_initialize(10, itemSize, type);

	return stack;
}

bool stack_push(Stack* stack, void *item) {

	if (stack == NULL || item == NULL) {
		
		return false;	
	}

	return alist_add(stack->alist, item);
}

void* stack_pop(Stack* stack) {

	if (stack == NULL || stack->alist->size == 0) {
	
		return NULL;
	}

	return alist_remove(stack->alist, stack->alist->size - 1);
}

void* stack_peek(Stack* stack) {

	if (stack == NULL || stack->alist->size == 0) {
	
		return NULL;
	}
	
	return alist_get(stack->alist, stack->alist->size - 1);
}

int stack_size(Stack* stack) {

	if (stack == NULL) {
	
		return - 1;
	}

	return stack->alist->size;
}

bool stack_contains(Stack* stack, void *item) {

	if (stack == NULL || item == NULL) {
	
		return false;
	}

	if (alist_index_of(stack->alist, item) != -1) {
	
		return true;
	}
	else {
	
		return false;
	}
}

bool stack_destroy(Stack* stack) {

	if (stack == NULL) {
	
		return false;
	}

	for (int i = 0; i < stack->alist->size; i++) {
	
		stack_pop(stack);
	}

	free(stack->alist->arr);
	free(stack->alist->type);
	free(stack->alist);

	free(stack);

	return true;
} 








