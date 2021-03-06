//stack.h

#ifndef __STACK_HEADER
#define __STACK_HEADER

#include <stdbool.h>
#include "../array_list/array_list.h"

//create a struct for stacks
typedef struct _Stack {

	ArrayList* alist;
} Stack;

Stack* stack_initialize(int, char*);
bool stack_push(Stack*, void*);
void* stack_pop(Stack*);
void* stack_peek(Stack*);
int stack_size(Stack*);
bool stack_contains(Stack*, void*);
bool stack_destroy(Stack*);

#endif
