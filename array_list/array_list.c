//array_list.c

#include "array_list.h"

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function for initializing an ArrayList struct
ArrayList* alist_initialize(int maxSize, int itemSize, char* type) {

	ArrayList *alist = malloc(sizeof(*alist));

	if (alist == NULL) {
	
		return NULL;
	}

	//allocate space for arr
	alist->arr = malloc(sizeof(void*) * maxSize);

	alist->size = 0;
	alist->maxSize = maxSize;
	alist->itemSize = itemSize;
	alist->type = malloc(sizeof(*type));
	memcpy(alist->type, type, sizeof(type));

	return alist;

}

//add to the end of the arraylist
bool alist_add(ArrayList* alist, void* item) {

	if (alist == NULL || item == NULL) {
	
		return false;
	}

	int index = alist->size;

	
	if (index == (alist->maxSize)) {

		//reallocate arr by growth factor of 2
		alist->arr = realloc(alist->arr, sizeof(void*) * alist->maxSize * 2);

		//increase the stored value of maxSize
		alist->maxSize = alist->maxSize * 2;
	}

	free(alist->arr[index]);

	alist->arr[index] = malloc(alist->itemSize);

	//add item to the end of the list
	memcpy(alist->arr[index], item, alist->itemSize);

	//increase the size of the arraylist
	alist->size++;

	printf("alist_add, adding: %d\n", *(int*)item);

	//succsessfully added item to the list
	return true;
}

bool alist_add_at(ArrayList* alist, int index, void* item) {

	if(alist == NULL || item == NULL || (index >= alist->size && index != 0) || index < 0) {
	
		return false;
	}

	//if more space needs to be allocated, reallocate
	if (alist->maxSize == alist->size) {
	
		//reallocate arr by growth factor of 2
		alist->arr = realloc(alist->arr, sizeof(void*) * alist->maxSize * 2);

		alist->maxSize = alist->maxSize * 2;
	}

	//move everything over to make a space for the new item
	for (int i = alist->size - 1; i >= index; i--) {

		alist->arr[i+1] = malloc(alist->itemSize);
		memcpy(alist->arr[i+1], alist->arr[i], alist->itemSize);
		free(alist->arr[i]);		
	}
	
	alist->arr[index] = malloc(alist->itemSize);

	//copy the new item contents into the given index
	memcpy(alist->arr[index], item, alist->itemSize);

	alist->size++;

	return true;
}

//clear the arraylist
void alist_clear(ArrayList* alist) {

	if (alist == NULL) {
	
		return;
	}

	for (int i = 0; i < alist->size; i++) {
	
		free(alist->arr[i]);
	}

	alist->size = 0;
}

//gets an item from a given element and returns it to the user, null if the index doesn't exist
void* alist_get(ArrayList* alist, int index) {

	if (alist == NULL || alist->arr[index] == NULL || index < 0 || index >= alist->size) {
		
		return NULL;	
	}

	//a null pointer to store the item at the given index
	void* item = malloc(alist->itemSize);

	//coppying the contents of arralylist at the given index into the item
	memcpy(item, alist->arr[index], alist->itemSize);

	return item;
}

//checks to see if an item exists in a list and returns it's index if true
int alist_index_of(ArrayList* alist, void* item) {

	if (alist == NULL || item == NULL) {
	
		return -1;
	}

	for (int i = 0; i < alist->size; i++) {
	
		//compare items to see if we can find the arg item
		int diff = memcmp(item, alist->arr[i], alist->itemSize);

		//this means that the item was found
		if (diff == 0) {
			printf("diff: %d\n", diff);
			//return the index that it was found at
			return i;
		}
	}

	//item was never found
	return -1;
}

//remove an element from a given index
void* alist_remove(ArrayList* alist, int index) {

	if (alist == NULL || index < 0 || index >= alist->size) {
	
		return NULL;
	}

	void* item = malloc(alist->itemSize);

	memcpy(item, alist->arr[index], alist->itemSize);

	free(alist->arr[index]);

	for (int i = index; i < alist->size - 1; i++) {
	
		alist->arr[i] = malloc(alist->itemSize);
		memcpy(alist->arr[i], alist->arr[i + 1], alist->itemSize);
		free(alist->arr[i + 1]);
	}

	alist->size--;

	return item;
}

//deallocate everything in the arraylist and then the arraylist itself
bool alist_destroy(ArrayList* alist) {

	if (alist == NULL) {
	
		return false;
	}

	//free every element in the arraylist
	for (int i = 0; i < alist->size; i++) {
	
		free(alist->arr[i]);
	}

	//free the array, then the tyoe array, then the whole alist itself
	free(alist->arr);
	free(alist->type);
	free(alist);

	//true becuase the alist was sussefully destroyed
	return true;
}

//resize the array
bool _alist_resize(ArrayList* alist) {

	if (alist == NULL) {
	
		return false;
	}
	
	//reallocate arraylist
	alist->arr = realloc(alist->arr, sizeof(void*) * (alist->maxSize) * 2);

	//return true if reallocation was sussessful
	return true;
}


