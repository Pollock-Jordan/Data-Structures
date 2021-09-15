//array_list.h

#ifndef __ARRAY_LIST_HEADER
#define __ARRAY_LIST_HEADER

#include <stdbool.h>

//arrayList struct typedef so that we can call these ArrayLists
typedef struct _AList {

	void** arr;
	int size;
	int maxSize;
	int itemSize;
	char* type;

} ArrayList;

//forward declarations
ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool _alist_destroy(ArrayList*);
bool alist_resize(ArrayList*);

#endif
